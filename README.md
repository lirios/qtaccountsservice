Qt Accounts Service
===================

[![ZenHub.io](https://img.shields.io/badge/supercharged%20by-zenhub.io-blue.svg)](https://zenhub.io)

[![License](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](http://www.gnu.org/licenses/lgpl.txt)
[![GitHub release](https://img.shields.io/github/release/lirios/qtaccountsservice.svg)](https://github.com/lirios/qtaccountsservice)
[![Build Status](https://travis-ci.org/lirios/qtaccountsservice.svg?branch=develop)](https://travis-ci.org/lirios/qtaccountsservice)
[![Coverity Status](https://img.shields.io/coverity/scan/5911.svg)](https://scan.coverity.com/projects/5911)
[![GitHub issues](https://img.shields.io/github/issues/lirios/qtaccountsservice.svg)](https://github.com/lirios/qtaccountsservice/issues)
[![Maintained](https://img.shields.io/maintenance/yes/2017.svg)](https://github.com/lirios/qtaccountsservice/commits/develop)

Qt-style API to use freedesktop.org's AccountsService DBus service.

For more information [read here](http://www.freedesktop.org/wiki/Software/AccountsService)

## Dependencies

Qt >= 5.8.0 with at least the following modules is required:

 * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
 * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)

## Installation

From the root of the repository, run:

```sh
mkdir build; cd build
qmake ../qtaccountsservice.pro
make
make install # use sudo if necessary
```

On the `qmake` line, you can specify additional configuration parameters:

 * `LIRI_INSTALL_PREFIX=/path/to/install` (for example `/opt/liri` or `/usr`)
 * `CONFIG+=debug` if you want a debug build
 * `CONFIG+=use_qt_paths` as an alternative to `LIRI_INSTALL_PREFIX=/path/to/install`
   if you want to install where Qt is installed

Use `make distclean` from inside your `build` directory to clean up.
You need to do this before rerunning `qmake` with different options.

## Licensing

Licensed under the terms of the GNU Lesser General Public License version 3 or,
at your option, any later version.
