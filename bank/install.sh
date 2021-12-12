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
cd build
cmake ../src
cmake --build .
sudo make install

cd ..
echo "Program installed successfully!"