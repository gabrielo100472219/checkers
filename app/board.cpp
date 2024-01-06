#include "board.hpp"

void Board::setup_white() {
  // We create the white pieces and put them in their corresponding positions
  for (int y=0; y<3; y++){
    // Depending on the y position, whe start by cells 0 or 1
    int x = 0;
    if (y == 1){
      x += 1;
    }
    // We add all white pieces to the white list
    for (; x<8; x+=2){
      Piece white;
      white.color = "white"; // Color is white obviously
      white.position = {x, y}; // Position is the one corresponding with the loop's logic
      this->white_pieces.push_back(white);
    }
  }
}

void Board::setup_black() {
  // Now we do the same for the black pieces, going from
  for (int y=5; y<8; y++){
    // Depending on the y position, whe start by cells 0 or 1
    int x = 1;
    if (y == 6){
      x -= 1;
    }
    // We add all black pieces to the white list
    for (; x<8; x+=2){
      Piece black;
      black.color = "black"; // Color is black obviously
      black.position = {x, y}; // Position is the one corresponding with the loop's logic
      this->black_pieces.push_back(black);
    }
  }
}

int Board::check_valid_position(Position position_to_check) {
  // We first check if the current position is in bounds
  if (position_to_check.x < 0 or position_to_check.y < 0 or position_to_check.x >= 8 or position_to_check.y >= 8){
    return -1;
  }

  // We now check if the position is a white box
  // If y is pair, the piece must be in an pair x
  if (position_to_check.y%2 == 0){
    if (position_to_check.x%2 == 1){
      return -2;
    }
  }else{
    // If y is odd, x must be odd
    if (position_to_check.x%2 == 0){
      return -3;
    }
  }
  return 0;
}


