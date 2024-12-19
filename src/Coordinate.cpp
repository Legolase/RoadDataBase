#include "Coordinate.hpp"

namespace module {
bool Coordinate::isEqual(const Coordinate &other) const & noexcept {
  if (this == &other) {
    return true;
  }
  return this->longitude == other.longitude && this->latitude == other.latitude;
}

std::string Coordinate::toSting() const {
  return "<RoadDataBase.Coordinate {" + std::to_string(longitude) + ", " +
         std::to_string(latitude) + "}>";
}

} // namespace module