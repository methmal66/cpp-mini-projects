#! /bin/sh

#pre install
if [ ! -d .accounts ]
then
    mkdir .accounts
fi

#build and install
if [ ! -d build ]
then 
    mkdir build
fi

cmake .
cmake --build .
sudo make install

echo "Program installed successfully!"