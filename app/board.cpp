#include "board.hpp"


void Board::setup_white() {
  // We create the white pieces and put them in their corresponding positions
  for (int y=0; y<3; y++){
    int x = get_starting_x_from_y(y);
    // We add all white pieces to the white list
    for (; x<MAX_BOARD_SIZE; x+=2){
      create_white_piece({x, y});
    }
  }
}

void Board::create_initial_black_pieces() {
  // Now we do the same for the black pieces, going from
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
  white.color = "white"; // Color is white obviously
  white.position = piece_position; // Position is the one corresponding with the loop's logic
  white_pieces.push_back(white);
}

void Board::create_black_piece(Position piece_position) {
  Piece black;
  black.color = "black"; // Color is black obviously
  black.position = piece_position; // Position is the one corresponding with the loop's logic
  black_pieces.push_back(black);
}

int Board::check_valid_position(Position position_to_check) {
  if (position_is_out_of_bounds(position_to_check)){
    return -1;
  }
  if (position_is_white_box(position_to_check)){
    return -2;
  }
  return 0;
}

bool Board::position_is_white_box(const Position &position_to_check) {
  if (position_to_check.y % 2 == 0){
    if (position_to_check.x % 2 == 1){
      return true;
    }
  }else{
    // If y is odd, x must be odd
    if (position_to_check.x % 2 == 0){
      return true;
    }
  }
  return false;
}

bool Board::position_is_out_of_bounds(const Position &position_to_check) {
  return position_to_check.x < 0 or position_to_check.y < 0 or position_to_check.x >= MAX_BOARD_SIZE or
  position_to_check.y >= MAX_BOARD_SIZE;
}