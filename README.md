Qt AccountsService binding
==========================

[![GitHub release](https://img.shields.io/github/release/hawaii-desktop/qtaccountsservice.svg)](https://github.com/hawaii-desktop/qtaccountsservice)
[![GitHub issues](https://img.shields.io/github/issues/hawaii-desktop/qtaccountsservice.svg)](https://github.com/hawaii-desktop/qtaccountsservice/issues)
[![IRC Network](https://img.shields.io/badge/irc-freenode-blue.svg "IRC Freenode")](https://webchat.freenode.net/?channels=hawaii-desktop)

Qt-style API to use freedesktop.org's AccountsService DBus service.

For more information see:
    http://www.freedesktop.org/wiki/Software/AccountsService

No build dependencies besides Qt 5.x, but to use this library you need
the AccountsService daemon running.

## Build && Install

```
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr    \
    -DLIB_INSTALL_DIR=lib   \
    -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
make
sudo make install
```


## Build

Building this project is a piece of cake.

Assuming you are in the source directory, just create a build directory
and run cmake:

```sh
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/opt/hawaii ..
```

To do a debug build the last command can be:

```sh
cmake -DCMAKE_INSTALL_PREFIX=/opt/hawaii -DCMAKE_BUILD_TYPE=Debug ..
```

To do a release build instead it can be:

```sh
cmake -DCMAKE_INSTALL_PREFIX=/opt/hawaii -DCMAKE_BUILD_TYPE=Release ..
```

If not passed, the `CMAKE_INSTALL_PREFIX` parameter defaults to /usr/local.
You have to specify a path that fits your needs, /opt/hawaii is just an example.

Package maintainers would pass `-DCMAKE_INSTALL_PREFIX=/usr`.

The `CMAKE_BUILD_TYPE` parameter allows the following values:

* **Debug:** debug build
* **Release:** release build
* **RelWithDebInfo:** release build with debugging information

## Installation

It's really easy, it's just a matter of typing:

```sh
make install
```

from the build directory.
