cmake_minimum_required(VERSION 3.12.4)

project(elfio)
set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    if(MSVC_VERSION LESS 1600)
        add_definitions(-DELFIO_NO_CSTDINT)
    endif()
endif()

add_subdirectory(examples/add_section)
add_subdirectory(examples/anonymizer)
add_subdirectory(examples/elfdump)
add_subdirectory(examples/tutorial)
add_subdirectory(examples/write_obj)
add_subdirectory(examples/writer)
add_subdirectory(examples/c_wrapper)
