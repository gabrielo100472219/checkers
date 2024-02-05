#ifndef CHECKERS_POSITION_HPP
#define CHECKERS_POSITION_HPP


class Position {
public:
  int x;
  int y;

  [[nodiscard]] bool x_is_odd() const;
  [[nodiscard]] bool y_is_odd() const;
};


#endif //CHECKERS_POSITION_HPP
