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

### Build with Qbs

Qbs is a new build system that is much easier to use compared to qmake or CMake.
It is the default build system for this project and soon will become the only one.

If you want to learn more, please read the [Qbs manual](http://doc.qt.io/qbs/index.html),
especially the [setup guide](http://doc.qt.io/qbs/configuring.html) and how to install artifacts
from the [installation guide](http://doc.qt.io/qbs/installing-files.html).

From the root of the repository, run:

```sh
qbs setup-toolchains --type gcc /usr/bin/g++ gcc
qbs setup-qt /usr/bin/qmake-qt5 qt5
qbs config profiles.qt5.baseProfile gcc
qbs -d build -j $(nproc) profile:qt5 # use sudo if necessary
```

On the last `qbs` line, you can specify additional configuration parameters at the end:

 * `qbs.installRoot:/path/to/install` (for example `/opt/liri` or `/usr`)
 * `lirideployment:libDir=/relative/path/to/lib` indicates where libraries will be installed,
   relative to `qbs.installRoot`, this is only needed if `qbs.installRoot` is a system-wide path
   such as `/usr`.
 * `lirideployment:qmlDir=/relative/path/to/qml` indicates where QML plugins will be installed,
   relative to `qbs.installRoot`, this is only needed if `qbs.installRoot` is a system-wide path
   such as `/usr`.

If you specify `qbs.installRoot` you might need to prefix the entire line with `sudo`,
depending on whether you have permissions to write there or not.

### Build with qmake

qmake, the Qt build system is still supported but will be removed at some point.
Qbs is a much better alternative with none of the complexity brought by qmake.

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
 * `CONFIG+=use_qt_paths` to install plugins and QML modules inside Qt

Use `make distclean` from inside your `build` directory to clean up.
You need to do this before rerunning `qmake` with different options.

## Licensing

Licensed under the terms of the GNU Lesser General Public License version 3 or,
at your option, any later version.
