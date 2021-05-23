#!/bin/sh

echo "Trying to create a Xcode project in directory \"proj\""

if [ ! -d "proj" ]
then
    echo "Creating Xcode project in directory \"proj\""
    mkdir proj
    cd proj
    cmake -G Xcode ..
else
    echo "\"proj\" already exist"
fi
