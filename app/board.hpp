#ifndef CHECKERS_BOARD_HPP
#define CHECKERS_BOARD_HPP

#include "piece.hpp"
#include <string>
#include <vector>
using namespace std;


class Board {
  public:
    vector<Piece> white_pieces;
    vector<Piece> black_pieces;
    Board(){
      this->setup_white();
      this->setup_black();
    }

    // Function for creating all white pieces with correct positions
    void setup_white();

  // Function for creating all black pieces with correct positions
  void setup_black();



};


#endif //CHECKERS_BOARD_HPP
