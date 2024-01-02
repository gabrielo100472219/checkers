#include <gtest/gtest.h>
#include "app/board.hpp"


using namespace std;


TEST(GTestsBoard, test_initial_state) {
  Board test_board;
  // We check if the board is created with 12 black and 12 white pieces
  EXPECT_EQ(test_board.white_pieces.size(), 12);
  EXPECT_EQ(test_board.black_pieces.size(), 12);
}

TEST(GTestsBoard, test_initial_positions) {
  Board test_board;
  // We check if all the positions for the board are valid
  for (int i=0; i<12; i++){
    EXPECT_EQ(test_board.white_pieces[i].check_valid_position(), 0);
    EXPECT_EQ(test_board.black_pieces[i].check_valid_position(), 0);

  }
}