cmake_minimum_required(VERSION 3.20)
project(ImageRecoveryTEC)

set(CMAKE_CXX_STANDARD 17)

add_executable(ImageRecoveryTEC main.cpp XML/ReadWrite.cpp XML/ReadWrite.h logic/HexGeneticAlgo.cpp logic/HexGeneticAlgo.h image/ImageManager.cpp image/ImageManager.h)
