cmake_minimum_required(VERSION 3.12)

# Detect if we are the top level CMakeLists.txt or are we included in some
# other project
if(NOT DEFINED PROJECT_NAME)
  set(IS_TOP_PROJECT TRUE)
endif()

# Turn this on in order to build elfio examples
option(ELFIO_BUILD_EXAMPLES "Build ELFIO examples" OFF)

# Turns this on in order to build tests
option(ELFIO_BUILD_TESTS    "Build ELFIO tests" OFF)

project(elfio LANGUAGES C CXX)

include(GNUInstallDirs)

# Create a header only CMake target for elfio
add_library(elfio INTERFACE)
add_library(elfio::elfio ALIAS elfio)

target_include_directories(
    elfio
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../elfio>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Enable C++11 for examples and tests
if (ELFIO_BUILD_EXAMPLES OR ELFIO_BUILD_TESTS)
    set(CMAKE_CXX_STANDARD 11)
endif()

if (ELFIO_BUILD_EXAMPLES)
    # set (CMAKE_CXX_FLAGS "-Wall")
    add_subdirectory(examples)
endif()

if (ELFIO_BUILD_TESTS AND IS_TOP_PROJECT)
    # set (CMAKE_CXX_FLAGS "-Wall")
    enable_testing()
    add_subdirectory(ELFIOTest)
endif()

# If this is the top level project, add in logic to install elfio
if (IS_TOP_PROJECT)
    if(MSVC)
        if(MSVC_VERSION LESS 1910)
            target_compile_options(
                elfio
                INTERFACE
                    /wd4996
            )
        endif()
        if(MSVC_VERSION LESS 1700)
            target_compile_options(
                elfio
                INTERFACE
                    /wd4355
            )
        endif()
    endif()
endif()
