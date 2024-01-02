#include <gtest/gtest.h>
#include "app/piece.hpp"

using namespace std;

TEST(GTestsBoard, test_move_right) {
// Board test_game;
Piece white_p;
Piece black_p1;
Piece blackk_p2;
white_p.position = {3, 0};
white_p.move("up", "right");
array <int, 2> destination = {4, 1};
EXPECT_EQ(destination, white_p.position);
}

TEST(GTestsBoard, test_move_left) {
// Board test_game;
Piece white_p;
Piece black_p1;
Piece blackk_p2;
white_p.position = {3, 0};
white_p.move("up", "left");
array <int, 2> destination = {2, 1};
EXPECT_EQ(destination, white_p.position);
}

TEST(GTestsBoard, test_out_of_bounds_position){
  Piece test_piece1;
  Piece test_piece2;
  Piece test_piece3;
  Piece test_piece4;
  test_piece1.position = {-1, 0};
  test_piece2.position = {0, -1};
  test_piece3.position = {8, 0};
  test_piece4.position = {0, 8};
  EXPECT_EQ(test_piece1.check_valid_position(), -1);
  EXPECT_EQ(test_piece2.check_valid_position(), -1);
  EXPECT_EQ(test_piece3.check_valid_position(), -1);
  EXPECT_EQ(test_piece4.check_valid_position(), -1);
}

TEST(GTestBoard, test_white_box_position_odd_y) {
  Piece test_piece;
  test_piece.position = {0, 1};
  EXPECT_EQ(test_piece.check_valid_position(), -3);
}

TEST(GTestBoard, test_white_box_position_pair_y) {
  Piece test_piece;
  test_piece.position = {1, 0};
  EXPECT_EQ(test_piece.check_valid_position(), -2);
}