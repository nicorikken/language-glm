describe 'Properties grammar', ->
  grammar = null

  beforeEach ->
    waitsForPromise ->
      atom.packages.activatePackage 'language-glm'

    runs ->
      grammar = atom.grammars.grammarForScopeName 'source.glm'

  # convenience function during development
  debug = (tokens) ->
    console.log(JSON.stringify(tokens, null, ' '))

  it 'load the "properties" config grammar', ->
    expect(grammar).toBeTruthy()
    expect(grammar.scopeName).toBe 'source.glm'

  describe 'Should tokenize when', ->

    it 'is a line comment', ->
      {tokens} = grammar.tokenizeLine '//comment'
      expect(tokens).toHaveLength 1
      expect(tokens[0]).toEqual value: '//comment', scopes: ['source.glm','comment.line.glm']
