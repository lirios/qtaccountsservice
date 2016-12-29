Qt Accounts Service
===================

[![ZenHub.io](https://img.shields.io/badge/supercharged%20by-zenhub.io-blue.svg)](https://zenhub.io)

[![License](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](http://www.gnu.org/licenses/lgpl.txt)
[![GitHub release](https://img.shields.io/github/release/lirios/qtaccountsservice.svg)](https://github.com/lirios/qtaccountsservice)
[![Build Status](https://travis-ci.org/lirios/qtaccountsservice.svg?branch=develop)](https://travis-ci.org/lirios/qtaccountsservice)
[![Coverity Status](https://img.shields.io/coverity/scan/5911.svg)](https://scan.coverity.com/projects/5911)
[![GitHub issues](https://img.shields.io/github/issues/lirios/qtaccountsservice.svg)](https://github.com/lirios/qtaccountsservice/issues)
[![Maintained](https://img.shields.io/maintenance/yes/2016.svg)](https://github.com/lirios/qtaccountsservice/commits/master)

Qt-style API to use freedesktop.org's AccountsService DBus service.

For more information [read here](http://www.freedesktop.org/wiki/Software/AccountsService)

## Dependencies

Qt >= 5.0.0 with at least the following modules is required:

 * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
 * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)

The following modules and their dependencies are required:

 * [ECM >= 1.7.0](http://quickgit.kde.org/?p=extra-cmake-modules.git)

## Installation

From the root of the repository, run:

```sh
mkdir build; cd build
cmake .. -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
make
make install # use sudo if necessary
```

On the `cmake` line, you can specify additional configuration parameters:

 * `-DCMAKE_INSTALL_PREFIX=/path/to/install` (for example, `/opt/liri` or `/usr`)
 * `-DCMAKE_BUILD_TYPE=<build_type>`, where `<build_type>` is one of:
   * **Debug:** debug build
   * **Release:** release build
   * **RelWithDebInfo:** release build with debugging information

## Licensing

Licensed under the terms of the GNU Lesser General Public License version 3 or,
at your option, any later version.
