#!/bin/bash

#The project name
PROJECT="struct_data"

#get current directory
DIR=$(cd $(dirname $0) && pwd);

#build directory ({PROJECT}/build/)
BUILD_DIR="$DIR/build"

cd "$BUILD_DIR/"
BIN_DIR="$( cd ../../bin/ $(dirname $0) && pwd)"
cd ..

#if folder build ton found 
if ! [[ -d "$BUILD_DIR" ]]; then
	echo "ERROR: directory $BUILD_DIR not found"
	exit
#if file CMakeLists.txt not found
else if ! [[ -f "$BUILD_DIR/CMakeLists.txt" ]]; then
	echo "ERROR: file CMakeLists.txt from '$BUILD_DIR' not found"
	exit
else
	#run command cmake
	cmake "$BUILD_DIR/CMakeLists.txt"
	#if Makefile not found 
	if ! [[ -f "$BUILD_DIR/Makefile" ]]; then
		echo "ERROR: make file from $BUILD_DIR not found"
		exit
	else
		cd "$BUILD_DIR/"
		#execute Makefile
		make
		cd "$DIR/"
	fi
fi
fi

#if the output file was not found
if ! [[ -f "$BUILD_DIR/$PROJECT" ]]; then
	echo "ERROR: execute file '$PROJECT' not found"
	exit
#if the directory $BIN_DIR is valide and the executable file in the directory $BIN_DIR was nod fond, 
#then will be move the executable file to the directory $BIN_DIR
else if [[ -d "$BIN_DIR" ]] && ! [[ -f "$BIN_DIR/$PROJECT" ]]; then
	mv "$BUILD_DIR/$PROJECT" "$BIN_DIR" && echo "-- The new executable file '$PROJECT' was moved from $BUILD_DIR/ to $BIN_DIR"
#if the directory $BIN_DIR is valide and the executable file in the directory $BIN_DIR was found,
#then will be remove the old executable file and will be move new executable file to the directory $BIN_DIR
else if [[ -d "$BIN_DIR" ]] && [[ -f "$BIN_DIR/$PROJECT" ]]; then
	rm "$BIN_DIR/$PROJECT"
	mv "$BUILD_DIR/$PROJECT" "$BIN_DIR" && echo "-- The older executable file '$PROJECT' from $BIN_DIR/ was removed and the new file was moved to $BIN_DIR"
else
#if the $BIN_DIR is not valide
	echo "ERROR: the directory $BIN_DIR was not found"
fi
fi
fi