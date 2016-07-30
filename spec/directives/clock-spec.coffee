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
    it 'is a valid clock definition', ->
      tokens = grammar.tokenizeLines '''
        clock{
          timestamp '2000-01-01 0:00:00';
          stoptime '2000-01-02 0:00:00';
          timezone EST+8EDT;
        }
      '''
      expect(tokens).toHaveLength 5
      expect(tokens[0]).toHaveLength 2
      expect(tokens[0][0]).toEqual value: 'clock', scopes: ['source.glm','clock.glm','keyword.type.clock.glm']
      expect(tokens[0][1]).toEqual value: '{', scopes: ['source.glm', 'clock.glm']
      expect(tokens[1]).toHaveLength 5
      expect(tokens[1][0]).toEqual value: '  ', scopes: ['source.glm','clock.glm','clock.property.glm']
      expect(tokens[1][1]).toEqual value: 'timestamp', scopes: ['source.glm','clock.glm','clock.property.glm','keyword.clock.property.glm']
      expect(tokens[1][2]).toEqual value: ' ', scopes: ['source.glm','clock.glm','clock.property.glm']
      expect(tokens[1][3]).toEqual value: '\'2000-01-01 0:00:00\'', scopes: ['source.glm','clock.glm','clock.property.glm','constant.timestamp.glm']
      expect(tokens[1][4]).toEqual value: ';', scopes: ['source.glm','clock.glm']
      expect(tokens[2]).toHaveLength 5
      expect(tokens[2][0]).toEqual value: '  ', scopes: ['source.glm','clock.glm','clock.property.glm']
      expect(tokens[2][1]).toEqual value: 'stoptime', scopes: ['source.glm','clock.glm','clock.property.glm','keyword.clock.property.glm']
      expect(tokens[2][2]).toEqual value: ' ', scopes: ['source.glm','clock.glm','clock.property.glm']
      expect(tokens[2][3]).toEqual value: '\'2000-01-02 0:00:00\'', scopes: ['source.glm','clock.glm','clock.property.glm','constant.timestamp.glm']
      expect(tokens[2][4]).toEqual value: ';', scopes: ['source.glm','clock.glm']
      expect(tokens[3]).toHaveLength 5
      expect(tokens[3][0]).toEqual value: '  ', scopes: ['source.glm','clock.glm','clock.property.glm']
      expect(tokens[3][1]).toEqual value: 'timezone', scopes: ['source.glm','clock.glm','clock.property.glm','keyword.clock.property.glm']
      expect(tokens[3][2]).toEqual value: ' ', scopes: ['source.glm','clock.glm','clock.property.glm']
      expect(tokens[3][3]).toEqual value: 'EST+8EDT', scopes: ['source.glm','clock.glm','clock.property.glm','constant.timezone.clock.property.glm']
      expect(tokens[3][4]).toEqual value: ';', scopes: ['source.glm','clock.glm']
      expect(tokens[4]).toHaveLength 1
      expect(tokens[4][0]).toEqual value: '}', scopes: ['source.glm','clock.glm']
