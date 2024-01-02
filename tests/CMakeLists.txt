add_executable(checkers_test
        ../app/board.cpp
        ../app/piece.cpp
)

# Crear una librería estática con los archivos comunes
add_library(checkers_lib STATIC ../app/board.cpp ../app/piece.cpp)
target_link_libraries(checkers_test PRIVATE checkers_lib)

# Include your unit test source files
add_executable(tests
        gtests_main.cpp
        gtests_board.cpp
        gtests_piece.cpp
)

target_link_libraries(checkers_test PRIVATE checkers_lib)

# Link the unit tests with your project and Google Test
target_link_libraries(tests
        gtest
        gtest_main
        Microsoft.GSL::GSL
        checkers_lib
        gtest
        gtest_main)

# Discover and add the tests
include(GoogleTest)

include_directories(app)
include_directories(${GTEST_INCLUDE_DIRS})