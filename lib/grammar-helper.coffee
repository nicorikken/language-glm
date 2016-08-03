# grammar-helper.coffee
# This file is part of language-glm.
#
# Copyright (C) 2016 Ludovic Fernandez
#  as contributed to atom-language-asciidoc project
#  MIT license
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

{Directory} = require 'atom'
CSON = require 'season'
path = require 'path'

String::endsWith ?= (s) -> s is '' or @[-s.length..] is s

class GrammarHelper

  constructor: (@rootInputDirectory, @rootOutputDirectory) ->

  readGrammarFile: (file) ->
    filepath = path.join __dirname, @rootInputDirectory, file
    CSON.readFileSync filepath

  writeGrammarFile: (grammar, file) ->
    outputFilepath = path.join __dirname, @rootOutputDirectory, file
    CSON.writeFileSync outputFilepath, grammar

  appendPartialGrammars: (grammar, partialGrammarFiles) ->
    for grammarFile in partialGrammarFiles
      {key, patterns} = @readGrammarFile grammarFile
      if key? and patterns?
        grammar.repository[key] =
          patterns: patterns

  appendPartialGrammarsDirectory: (grammar, grammarDirectories) ->
    for directoryName in grammarDirectories
      directory = new Directory path.join(__dirname, @rootInputDirectory, directoryName)
      entries = directory.getEntriesSync()
      for entry in entries
        if entry.isFile() and entry.getBaseName().endsWith '.cson'
          {key, patterns} = CSON.readFileSync entry.path
          if key? and patterns?
            grammar.repository[key] =
              patterns: patterns

module.exports = GrammarHelper
