#include <gtest/gtest.h>
#include "app/board.hpp"
#include "app/position_validator.hpp"

positionValidator position_validator;

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
    EXPECT_EQ(position_validator.check_invalid_position(test_board.white_pieces[i].position), false);
    EXPECT_EQ(position_validator.check_invalid_position(test_board.black_pieces[i].position), false);

  }
}

TEST(GTestsBoard, test_negative_x_position){
  Board test_board;
  Position position_to_check = {-1, 0};
  EXPECT_EQ(position_validator.check_invalid_position(position_to_check), true);
}

TEST(GTestsBoard, test_negative_y_position){
  Board test_board;
  Position position_to_check = {0, -1};
  EXPECT_EQ(position_validator.check_invalid_position(position_to_check), true);
}

TEST(GTestsBoard, test_out_of_bounds_x_position){
  Board test_board;
  Position position_to_check = {8, 0};
  EXPECT_EQ(position_validator.check_invalid_position(position_to_check), true);
}

TEST(GTestsBoard, test_out_of_bounds_y_position){
  Board test_board;
  Position position_to_check = {0, 8};
  EXPECT_EQ(position_validator.check_invalid_position(position_to_check), true);
}

TEST(GTestBoard, test_white_box_position_odd_y) {
  Board test_board;
  Position position_to_check = {0, 1};
  EXPECT_EQ(position_validator.check_invalid_position(position_to_check), true);
}

TEST(GTestBoard, test_white_box_position_pair_y) {
  Board test_board;
  Position position_to_check = {1, 0};
  EXPECT_EQ(position_validator.check_invalid_position(position_to_check), true);
}

