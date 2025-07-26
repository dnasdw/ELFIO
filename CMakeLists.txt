cmake_minimum_required(VERSION 3.17.3)

project(elfio)
set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    if(MSVC_VERSION LESS 1600)
        add_definitions(-DELFIO_NO_CSTDINT)
    endif()
endif()

add_subdirectory(examples)
