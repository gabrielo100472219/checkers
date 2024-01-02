#include "piece.hpp"


int Piece::move(const string& vertical_dir, const string& horizontal_dir) {
  array<int, 2> destination = this->position; // Square to which the piece arrives to
  // We change the vertical exe position of the piece depending on the input
  if(vertical_dir == "up") {
     destination[1] += 1;
  }else if(vertical_dir == "down"){
    destination[1] -= 1;
  }else{
    // If the input is different from those two, we terminate with error code -1
    return -1;
  }
  // Now we change the horizontal exe position of the piece depending on the input
  if(horizontal_dir == "right") {
    destination[0] += 1;
  }else if(horizontal_dir == "left"){
    destination[0] -= 1;
  }else{
    // If the input is different from those two, we terminate with error code -1
    return -1;
  }
  this->position = destination;
  return 0;
}

int Piece::check_valid_position() {
  // We first check if the current position is in bounds
  if (this->position[0] < 0 or this->position[1] < 0 or this->position[0] >= 8 or this->position[1] >= 8){
    return -1;
  }

  // We now check if the position is a white box
  // If y is pair, the piece must be in an pair x
  if (this->position[1]%2 == 0){
    if (this->position[0]%2 == 1){
      return -2;
    }
  }else{
    // If y is odd, x must be odd
    if (this->position[0]%2 == 0){
      return -3;
    }
  }
  return 0;
}
