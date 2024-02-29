#ifndef CHECKERS_PIECE_HPP
#define CHECKERS_PIECE_HPP

#include "checkers_commons.hpp"
#include <string>
#include <vector>
using namespace std;


class Piece {
public:
  Position position;
  string color;

  bool has_possible_moves();

  void update_possible_moves(vector<Position> list_of_possible_moves);



private:
  vector<Position> possible_moves;
};


#endif //CHECKERS_PIECE_HPP
