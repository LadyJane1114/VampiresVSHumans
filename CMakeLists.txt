cmake_minimum_required(VERSION 4.0)
project(VampiresVSHumans)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(inc)
include_directories(src)

add_executable(VampiresVSHumans
        .idea/.gitignore
        .idea/editor.xml
        .idea/modules.xml
        .idea/VampiresVSHumans.iml
        .idea/vcs.xml
        .idea/workspace.xml
        inc/Building.h
        inc/GameSpecs.h
        inc/Human.h
        inc/Island.h
        inc/Organism.h
        inc/Vampire.h
        main.cpp
        ReadMe)
