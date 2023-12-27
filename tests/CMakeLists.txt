add_executable(checkers_test.exe
        ../app/board.cpp)

# Include your unit test source files
add_executable(tests.exe
        gtests_main.cpp
        gtests_board.cpp
)

# Link the unit tests with your project and Google Test
target_link_libraries(tests.exe
        gtest
        gtest_main
        Microsoft.GSL::GSL)

# Discover and add the tests
include(GoogleTest)

include_directories(app)
include_directories(${GTEST_INCLUDE_DIRS})