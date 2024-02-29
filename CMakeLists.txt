cmake_minimum_required(VERSION 3.26)
project( checkers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set compiler options
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native")

# Enable GoogleTest Library
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable GSL Library
FetchContent_Declare(GSL
        GIT_REPOSITORY "https://github.com/microsoft/GSL"
        GIT_TAG v4.0.0
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)
# All includes relative to source tree root.
include_directories(PUBLIC .)

add_subdirectory(app)
add_subdirectory(tests)
# Unit tests and functional tests
enable_testing()

add_executable(checkers
        app/main.cpp
        app/piece.hpp
        app/piece.cpp
        app/position_validator.hpp
        app/position_validator.cpp
        app/checkers_commons.hpp
)