#include "piece.hpp"

#include <utility>


bool Piece::has_possible_moves() {
  return not this->possible_moves.empty();
}

void Piece::update_possible_moves(vector<Position> list_of_possible_moves) {
  this->possible_moves = std::move(list_of_possible_moves);
}
