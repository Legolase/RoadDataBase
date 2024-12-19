#ifndef ROAD_DB_H
#define ROAD_DB_H

#include <cstdint>
#include <memory>
#include <unordered_map>

#include "Sign.hpp"

namespace module {

struct RoadDB {
  void insert(const Sign::Ptr &);
  void erase(int);
  Sign::Ptr find(int);

  std::unordered_map<int, Sign::Ptr> map_;
};

} // namespace module

#endif
