#include "position.hpp"

bool Position::x_is_odd() const {
  return this->x % 2 == 1;
}

bool Position::y_is_odd() const {
  return this->y % 2 == 1;
}
