# main.coffee
# This file is part of language-glm.
#
# Copyright (C) 2016 Ludovic Fernandez
#  as contributed to atom-language-asciidoc project
#  MIT license
# Copyright (C) 2016 Nico Rikken
#
# Language-GLM is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Foobar is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

{CompositeDisposable} = require 'atom'
CSON = require 'season'
GrammarHelper = require './grammar-helper'
# generator = require './code-block-generator'
path = require 'path'

module.exports =

  config:
    liveReload:
      title: '[Only on Developer Mode] Grammars live reload'
      type: 'boolean'
      default: false

  subscriptions: null
  liveReloadSubscriptions: null

  activate: (state) ->
    return unless atom.inDevMode() and not atom.inSpecMode()

    @subscriptions = new CompositeDisposable

    @helper = new GrammarHelper '../grammars/repositories/', '../grammars/'

    # Add actions in Command Palette
    @subscriptions.add atom.commands.add 'atom-workspace',
      'glm-grammar:compile-grammar-and-reload': => @compileGrammar()
      'glm-grammar:toggle-live-reload': ->
        keyPath = 'language-glm.liveReload'
        atom.config.set(keyPath, not atom.config.get(keyPath))

    # Calls immediately and every time the value is changed
    @subscriptions.add atom.config.observe 'language-glm.liveReload', (newValue) =>
      return unless atom.inDevMode()
      if newValue
        @compileGrammar()
        @liveReloadSubscriptions = new CompositeDisposable
        @startliveReload()
      else
        @liveReloadSubscriptions?.dispose()

  startliveReload: ->
    return unless atom.inDevMode() and not atom.inSpecMode() and atom.config.get 'language-glm.liveReload'

    @liveReloadSubscriptions.add atom.workspace.observeTextEditors (editor) =>
      if path.extname(editor.getTitle()) is '.cson'
        @liveReloadSubscriptions.add editor.buffer.onDidSave =>
          @compileGrammar()

  compileGrammar: (debug) ->
    return unless atom.inDevMode() and not atom.inSpecMode()

    rootGrammar = @helper.readGrammarFile 'glm-grammar.cson'
    rootGrammar.name = "GridLAB-D Model (GLM)" # TODO better naming?
    rootGrammar.scopeName = 'source.glm'
    rootGrammar.fileTypes = [
      'glm'
    ]

    @helper.appendPartialGrammarsDirectory rootGrammar, ['partials/', 'macros/', 'modules/', 'variables/', 'powerflow/', 'residential/', 'commercial/', 'tape/']

    if debug
      console.log CSON.stringify rootGrammar
    @helper.writeGrammarFile rootGrammar, 'language-glm.cson'
    @reload()

  reload: ->
    # Remove grammars
    atom.grammars.removeGrammarForScopeName 'source.glm'
    # atom.grammars.removeGrammarForScopeName 'source.glm.properties'

    # Remove loaded package (Hack force reload)
    delete atom.packages.loadedPackages['language-glm']

    # Load package
    updatedPackage = atom.packages.loadPackage 'language-glm'
    updatedPackage.loadGrammarsSync()

    # Reload grammars for each editor
    atom.workspace.getTextEditors().forEach (editor) ->
      if editor.getGrammar().packageName is 'language-glm'
        editor.reloadGrammar()

    console.log 'GLM grammars reloaded'

    deactivate: ->
      @liveReloadSubscriptions?.dispose()
      @subscriptions.dispose()
