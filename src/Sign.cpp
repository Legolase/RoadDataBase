#include "Sign.hpp"
#include <iostream>

namespace module {
Sign::Sign(std::string name, int id, const Coordinate &coordinate)
    : name_(std::move(name)), id_(id), coordinate_(coordinate) {}

bool isEqual(const Sign::Ptr that, const Sign::Ptr other) noexcept {
  if (!that || !other) {
    return false;
  }
  if (that == other) {
    return true;
  }
  return that->id_ == other->id_ && that->name_ == other->name_ &&
         that->coordinate_.isEqual(other->coordinate_);
}

} // namespace module