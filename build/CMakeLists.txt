cmake_minimum_required ( VERSION 3.2.2 )

set( PROJECT algorithms )

set ( CMAKE_CXX_STANDARD 14 )

set ( CMAKE_CXX_STANDARD_REQUIRED on )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++" )

SET( FLAG_DEBUG "Debug" )

#флаги компиллятора для DEBUG версии
if( "${CMAKE_BUILD_TYPE}" STREQUAL "${FLAG_DEBUG}" )
    SET( CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "postfix applied to debug build of libraries" )
    SET( CMAKE_CXX_FLAGS_DEBUG "-O0 -g" )
    add_definitions( -D_DEBUG )
else()
#флаги клмпиллятора для RELEASE версии
    SET( CMAKE_RELEASE_POSTFIX "" CACHE STRING "postfix applied to release build of libraries" )
    SET( CMAKE_CXX_FLAGS_RELEASE "-O3 -g" )
endif()

#путь к исполнеямым файлам
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )
#путь к динамическим библиотекам
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )
#путь к статическим библиотекам
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin )

project( ${PROJECT} )

include_directories (
        ../simple_algorithms/inc
        ../sorting_algorithms/inc
        ../struct_data/inc
        )
#файлы реализации программы algorithms
aux_source_directory( ../                       ALGORITHMS_SRC )
aux_source_directory( ../simple_algorithms/src  ALGORITHMS_SRC )
aux_source_directory( ../sorting_algorithms/src ALGORITHMS_SRC )
aux_source_directory( ../struct_data/src        ALGORITHMS_SRC )

#исполняемый файл algorithms
add_executable( algorithm ${ALGORITHMS_SRC} )
