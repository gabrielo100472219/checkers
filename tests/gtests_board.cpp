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
    EXPECT_EQ(test_board.check_valid_position(test_board.white_pieces[i].position), 0);
    EXPECT_EQ(test_board.check_valid_position(test_board.black_pieces[i].position), 0);

  }
}

TEST(GTestsBoard, test_negative_x_position){
  Board test_board;
  Position position_to_check = {-1, 0};
  EXPECT_EQ(test_board.check_valid_position(position_to_check), -1);
}

TEST(GTestsBoard, test_negative_y_position){
  Board test_board;
  Position position_to_check = {0, -1};
  EXPECT_EQ(test_board.check_valid_position(position_to_check), -1);
}

TEST(GTestsBoard, test_out_of_bounds_x_position){
  Board test_board;
  Position position_to_check = {8, 0};
  EXPECT_EQ(test_board.check_valid_position(position_to_check), -1);
}

TEST(GTestsBoard, test_out_of_bounds_y_position){
  Board test_board;
  Position position_to_check = {0, 8};
  EXPECT_EQ(test_board.check_valid_position(position_to_check), -1);
}

TEST(GTestBoard, test_white_box_position_odd_y) {
  Board test_board;
  Position position_to_check = {0, 1};
  EXPECT_EQ(test_board.check_valid_position(position_to_check), -2);
}

TEST(GTestBoard, test_white_box_position_pair_y) {
  Board test_board;
  Position position_to_check = {1, 0};
  EXPECT_EQ(test_board.check_valid_position(position_to_check), -2);
}

TEST(GTestBoard, test_white_2_possible_moves) {
  Board test_board;
  test_board.create_white_piece({4, 2});
  test_board.white_pieces[0].calculate_possible_moves();
  int number_of_possible_moves = int(test_board.white_pieces[0].possible_moves.size());
  Position destination1 = test_board.white_pieces[0].possible_moves[0];
  Position destination2 = test_board.white_pieces[0].possible_moves[1];
  EXPECT_EQ(number_of_possible_moves, 2);
  EXPECT_EQ(destination1.x, 3);
  EXPECT_EQ(destination1.y, 3);
  EXPECT_EQ(destination2.x, 5);
  EXPECT_EQ(destination2.x, 3);
}

TEST(GTestBoard, test_white_possible_move_left_from_wall) {
  Board test_board;
  test_board.create_white_piece({7, 1});
  test_board.white_pieces[0].calculate_possible_moves();
  int number_of_possible_moves = int(test_board.white_pieces[0].possible_moves.size());
  Position destination = test_board.white_pieces[0].possible_moves[0];
  EXPECT_EQ(number_of_possible_moves, 1);
  EXPECT_EQ(destination.x, 6);
  EXPECT_EQ(destination.y, 2);
}

TEST(GTestBoard, test_white_possible_move_right_from_wall) {
  Board test_board;
  test_board.create_white_piece({0, 2});
  test_board.white_pieces[0].calculate_possible_moves();
  int number_of_possible_moves = int(test_board.white_pieces[0].possible_moves.size());
  Position destination = test_board.white_pieces[0].possible_moves[0];
  EXPECT_EQ(number_of_possible_moves, 1);
  EXPECT_EQ(destination.x, 1);
  EXPECT_EQ(destination.y, 3);
}