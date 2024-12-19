#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>

namespace module {

struct Coordinate {
  double longitude;
  double latitude;

  bool isEqual(const Coordinate& other) const & noexcept;

  std::string toSting() const;
};

} // namespace module

#endif