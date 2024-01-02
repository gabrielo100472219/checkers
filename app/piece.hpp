#ifndef CHECKERS_PIECE_HPP
#define CHECKERS_PIECE_HPP

#include <string>
#include <array>
using namespace std;

class Piece {
public:
  array<int, 2> position; // x, y
  string color; // black or white

  // Function for moving a piece given the two directions in which it will move
  int move(const string& vertical_dir, const string& horizontal_dir);

  // Function for checking if the position of a piece is valid
  int check_valid_position();

};


#endif //CHECKERS_PIECE_HPP
