#include "piece.hpp"


int Piece::move(const string& vertical_dir, const string& horizontal_dir) {
  Position destination = this->position; // Square to which the piece arrives to
  // We change the vertical exe position of the piece depending on the input
  if(vertical_dir == "up") {
     destination.y += 1;
  }else if(vertical_dir == "down"){
    destination.y -= 1;
  }else{
    // If the input is different from those two, we terminate with error code -1
    return -1;
  }
  // Now we change the horizontal exe position of the piece depending on the input
  if(horizontal_dir == "right") {
    destination.x += 1;
  }else if(horizontal_dir == "left"){
    destination.x -= 1;
  }else{
    // If the input is different from those two, we terminate with error code -1
    return -1;
  }
  this->possible_moves[0] = destination;
  return 0;
}

// Todo: ver que hacer con esta funcion bien
