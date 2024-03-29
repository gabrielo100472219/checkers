#ifndef CHECKERS_POSITION_VALIDATOR_HPP
#define CHECKERS_POSITION_VALIDATOR_HPP

#include "checkers_commons.hpp"


class positionValidator {
public:
  bool check_invalid_position(Position position_to_check);

private:
  Position position_being_checked;

  [[nodiscard]] bool position_is_out_of_bounds() const;
  [[nodiscard]] bool position_is_white_box() const;
  [[nodiscard]] bool x_is_odd() const;
  [[nodiscard]] bool y_is_odd() const;
};


#endif //CHECKERS_POSITION_VALIDATOR_HPP
