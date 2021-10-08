cmake_minimum_required(VERSION 3.20)
project(ABC)

set(CMAKE_CXX_STANDARD 20)

add_executable(ABC main.cpp CyclicShiftEncryption.cpp CyclicShiftEncryption.h SymbolsEncryption.cpp SymbolsEncryption.h NumbersEncryption.cpp NumbersEncryption.h container.cpp container.h Encryption.cpp Encryption.h)
