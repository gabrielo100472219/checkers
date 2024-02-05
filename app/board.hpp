#ifndef CHECKERS_BOARD_HPP
#define CHECKERS_BOARD_HPP

#include "piece.hpp"
#include "checkers_commons.hpp"
#include "position.hpp"
#include <string>
#include <vector>

using namespace std;


class Board {
  public:
    vector<Piece> white_pieces;
    vector<Piece> black_pieces;

    Board(){
      this->setup_white_pieces();
      this->setup_black_pieces();
    }

    void create_black_piece(Position piece_position);
    void create_white_piece(Position piece_position);

  private:
    void setup_white_pieces();
    void setup_black_pieces();
    static int get_starting_x_from_y(int y);
};


#endif //CHECKERS_BOARD_HPP
