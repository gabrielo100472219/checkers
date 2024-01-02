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
