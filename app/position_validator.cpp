#include "position_validator.hpp"


bool positionValidator::check_invalid_position(Position position_to_check) {
  this->position_being_checked = position_to_check;
  return this->position_is_out_of_bounds() or this->position_is_white_box();
}

bool positionValidator::position_is_white_box() const {
  if (not this->y_is_odd()){
    if (this->x_is_odd()){
      return true;
    }
  }else{
    if (not this->x_is_odd()){
      return true;
    }
  }
  return false;
}

bool positionValidator::position_is_out_of_bounds() const {
  return this->position_being_checked.x < 0 or this->position_being_checked.y < 0 or this->position_being_checked.x >=
  MAX_BOARD_SIZE or this->position_being_checked.y >= MAX_BOARD_SIZE;
}

bool positionValidator::x_is_odd() const {
  return this->position_being_checked.x % 2 == 1;
}

bool positionValidator::y_is_odd() const {
  return this->position_being_checked.y % 2 == 1;
}