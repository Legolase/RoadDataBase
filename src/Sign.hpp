#ifndef SIGN_H
#define SIGN_H

#include <memory>
#include <string>

#include "Coordinate.hpp"

namespace module {

struct Sign : std::enable_shared_from_this<Sign> {
  using Ptr = std::shared_ptr<Sign>;

  Sign(std::string, int, const Coordinate &);


  std::string name_;
  Coordinate coordinate_;
  int id_;
};

bool isEqual(const Sign::Ptr that, const Sign::Ptr other) noexcept;

} // namespace module

#endif