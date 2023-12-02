Qt Accounts Service
===================

[![License](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](http://www.gnu.org/licenses/lgpl.txt)
[![GitHub release](https://img.shields.io/github/release/lirios/qtaccountsservice.svg)](https://github.com/lirios/qtaccountsservice)
[![GitHub issues](https://img.shields.io/github/issues/lirios/qtaccountsservice.svg)](https://github.com/lirios/qtaccountsservice/issues)
[![CI](https://github.com/lirios/qtaccountsservice/workflows/CI/badge.svg?branch=develop)](https://github.com/lirios/qtaccountsservice/actions?query=workflow%3ACI)

Qt-style API to use freedesktop.org's AccountsService DBus service.

For more information [read here](http://www.freedesktop.org/wiki/Software/AccountsService)

## Dependencies

Qt >= 6.6.0 with at least the following modules is required:

 * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
 * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)

The following modules and their dependencies are required:

 * [cmake](https://gitlab.kitware.com/cmake/cmake) >= 3.19.0
 * [extra-cmake-modules](https://invent.kde.org/frameworks/extra-cmake-modules) >= 5.245.0
 * [cmake-shared](https://github.com/lirios/cmake-shared.git) >= 2.0.99

## Installation

```sh
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/path/to/prefix ..
make
make install # use sudo if necessary
```

Replace `/path/to/prefix` to your installation prefix.
Default is `/usr/local`.

You can also append the following options to the `cmake` command:

 * `-DQTACCOUNTSSERVICE_WITH_EXAMPLES:BOOL=OFF`: Do not build the examples.

## Licensing

Licensed under the terms of the GNU Lesser General Public License version 3 or,
at your option, any later version.
