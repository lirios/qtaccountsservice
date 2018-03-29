#!/bin/bash

set -e

msg() {
    lightblue='\033[1;34m'
    reset='\e[0m'
    echo -e "${lightblue}$@${reset}"
}

# Install
msg "Install packages..."
apt-get install -y \
    g++ clang \
    git \
    xvfb \
    dbus \
    curl \
    qt5-default \
    qbs \
    qtbase5-dev qtbase5-dev-tools qtbase5-private-dev \
    qtdeclarative5-dev qtdeclarative5-dev-tools qtdeclarative5-private-dev \
    qttools5-dev qttools5-dev-tools qttools5-private-dev \
    qml-module-qtquick2 qml-module-qtquick-window2 qml-module-qtquick-layouts qml-module-qttest

# Install artifacts
msg "Install artifacts..."
curl https://raw.githubusercontent.com/lirios/repotools/develop/travis/download-aritfacts > /tmp/download-artifacts
chmod 755 /tmp/download-artifacts
/tmp/download-artifacts $TRAVIS_BRANCH qbs-shared-artifacts.tar.gz

# Configure qbs
msg "Setup qbs..."
qbs setup-toolchains --detect
qbs setup-qt $(which qmake) travis-qt5
qbs config profiles.travis-qt5.baseProfile $CC

# Build
msg "Build..."
dbus-run-session -- \
xvfb-run -a -s "-screen 0 800x600x24" \
qbs -d build -j $(nproc) --all-products profile:travis-qt5 \
    modules.lirideployment.prefix:/usr \
    modules.lirideployment.libDir:/usr/lib/x86_64-linux-gnu \
    modules.lirideployment.qmlDir:/usr/lib/x86_64-linux-gnu/qt5/qml \
    modules.lirideployment.pluginsDir:/usr/lib/x86_64-linux-gnu/qt5/plugins \
    project.withExamples:true
