# GridLAB-D language support

_Atom language support for GridLAB-D markup GLM_

[![](doc/power-pattern.jpg)](https://www.flickr.com/photos/mrsteveparker/16008590119)
Image copyright by Steve Parker, Power Pattern, 2015, CC-2.0-BY

## Goals
- Full syntax parsing
- Practical syntax highlighting
- Keyword recognition
- Keyword completion using [autocomplete-plus](https://github.com/atom/autocomplete-plus)
- Handy snippets for source editing
- Extensive test coverage
- Structural folding support
- Prettify command like [pretty-json](https://github.com/federomero/pretty-json)
- Support for [symbols tree view](https://github.com/xndcn/symbols-tree-view)
  - This inherits the tag parsing from the [symbols view package](https://github.com/atom/symbols-view), which leads the matching regexes into [ctags](http://ctags.sourceforge.net/index.html) from out of the [ctags-config file](https://github.com/atom/symbols-view/blob/master/lib/ctags-config).

## Inspiration and reuse
- [GLM language parser](https://github.com/sordina/GLM)
- [Sublime Text GLM support](https://github.com/dpinney/gridlabSublime) _which is sadly in practice only a C language port_
- [GitHub flavoured Markdown support](https://github.com/atom/language-gfm) _as a generic atom language example_

## Copyright and Licensing
Copyright (C) 2016 Nico Rikken.
Free use of this software is granted under the terms of the LGPL v3 License.
This license is specifically chosen to enable all users to benefit from downstream derivations.

![](doc/lgplv3-147x51.png)

See the [COPYRIGHT.LESSER](COPYRIGHT.LESSER) file for details.
