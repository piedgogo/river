#!/bin/sh
make clean all
rm -rf debian

mkdir -p debian
mkdir -p debian/DEBIAN

cp debian.control debian/DEBIAN/control
dpkg -b debian river-`uname -m`.deb
rm -rf debian/
