Qt AccountsService binding
==========================

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

