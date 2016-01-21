#!/bin/bash
DIR=$(cd $(dirname $0) && pwd);
BIN_DIR="${DIR}/bin"

case "$1" in 
	"-simple_algorithms" )
		./simple_algorithms/make.sh
	;;
	"-struct_data" )
		./struct_data/make.sh
	;;
	"-all"     )
		./simple_algorithms/make.sh
		./struct_data/make.sh
	;;
	*)
	echo "Options:" 
	echo "  -simple_algorithms        Build the project simple_algorithms"
	echo "  -all            		  Build all projects"
esac
