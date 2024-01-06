#include <gtest/gtest.h>
#include "app/piece.hpp"

using namespace std;

TEST(GTestsPiece, test_move_right) {
  Piece white_p;
  Piece black_p1;
  Piece black_p2;
  white_p.position = {3, 0};
  white_p.move("up", "right");
  Position destination = {4, 1};
  EXPECT_EQ(destination.x, white_p.possible_moves[0].x);
  EXPECT_EQ(destination.y, white_p.possible_moves[0].y);
}

TEST(GTestsPiece, test_move_left) {
  Piece white_p;
  Piece black_p1;
  Piece blackk_p2;
  white_p.position = {3, 0};
  white_p.move("up", "left");
  Position destination = {2, 1};
  EXPECT_EQ(destination.x, white_p.possible_moves[0].x);
  EXPECT_EQ(destination.y, white_p.possible_moves[0].y);
}