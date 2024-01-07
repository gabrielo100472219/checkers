#ifndef CHECKERS_BOARD_HPP
#define CHECKERS_BOARD_HPP

#include "piece.hpp"
#include <string>
#include <vector>

const int MAX_BOARD_SIZE = 8;
using namespace std;


class Board {
  public:
    vector<Piece> white_pieces;
    vector<Piece> black_pieces;
    Board(){
      this->setup_white();
      this->create_initial_black_pieces();
    }

    // Function for creating all white pieces with correct positions
    void setup_white();

    // Function for creating all black pieces with correct positions
     void create_initial_black_pieces();

    // Function for checking if the position of a piece is valid
    static int check_valid_position(Position position_to_check);
    
    void create_black_piece(Position piece_position);

    static int get_starting_x_from_y(int y) ;

    void create_white_piece(Position piece_position);

  static bool position_is_out_of_bounds(const Position &position_to_check);

  static bool position_is_white_box(const Position &position_to_check);
};


#endif //CHECKERS_BOARD_HPP
