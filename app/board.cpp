#include "board.hpp"


void Board::setup_white_pieces() {
  for (int y=0; y<3; y++){
    int x = get_starting_x_from_y(y);
    // We add all white pieces to the white list
    for (; x<MAX_BOARD_SIZE; x+=2){
      create_white_piece({x, y});
    }
  }
}

void Board::setup_black_pieces() {
  for (int y=5; y<MAX_BOARD_SIZE; y++){
    int x = get_starting_x_from_y(y);
    // We add all black pieces to the white list
    for (; x<MAX_BOARD_SIZE; x+=2){
      create_black_piece({x, y});
    }
  }
}

int Board::get_starting_x_from_y(int y) {
  // Depending on the y position, whe start by cells 0 or 1
  int x = 0;
  if (y%2 == 1){
    x = 1;
  }
  return x;
}

void Board::create_white_piece(Position piece_position) {
  Piece white;
  white.color = "white";
  white.position = piece_position;
  white_pieces.push_back(white);
}

void Board::create_black_piece(Position piece_position) {
  Piece black;
  black.color = "black"; // Color is black obviously
  black.position = piece_position; // Position is the one corresponding with the loop's logic
  black_pieces.push_back(black);
}