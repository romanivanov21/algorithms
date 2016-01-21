#!/bin/bash

#get current directory
DIR=$(cd $(dirname $0) && pwd);

#build derectory
BUILD_DIR="$DIR/build"

#if build directiry not found
if ! [[ -d "$BUILD_DIR" ]]; then
	echo "ERROR: directory $BUILD_DIR not found"
	exit
else
	cd "$BUILD_DIR/"
	#execute comand clean
	make clean
	cd "$DIR/"
fi