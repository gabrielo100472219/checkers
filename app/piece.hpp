#ifndef CHECKERS_PIECE_HPP
#define CHECKERS_PIECE_HPP

#include <string>
#include <array>
using namespace std;


struct Position {
  int x;
  int y;
};

class Piece {
public:
  Position position;
  string color; // black or white
  array<Position, 2> possible_moves;

  // Function for moving a piece given the two directions in which it will move
  int move(const string& vertical_dir, const string& horizontal_dir);



};


#endif //CHECKERS_PIECE_HPP
