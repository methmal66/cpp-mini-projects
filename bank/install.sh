#! /bin/sh
mkdir build
cd build
cmake ../src
cmake --build .
sudo make install
cd ..
