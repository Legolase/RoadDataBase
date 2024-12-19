#include "RoadDB.hpp"

#include <iostream>
#include <stdexcept>

namespace module {
void RoadDB::insert(const Sign::Ptr &sign) {
  if (!sign) {
    throw std::invalid_argument("Invalid argument. sign is empty\n");
  }

  auto insertion = map_.emplace(sign->id_, std::make_shared<Sign>(*sign));

  if (!insertion.second) {
    throw std::invalid_argument("Invalid argument. sign.id == " + std::to_string(sign->id_) +
                                " is already exists\n");
  }
}

void RoadDB::erase(int id) {
  int erased_number = map_.erase(id);

  if (!erased_number) {
    std::cerr << "Warning: there is no sign.id == " << id << '\n';
  }
}

Sign::Ptr RoadDB::find(int id) {
  auto find_result = map_.find(id);

  if (find_result == map_.end()) {
    std::cerr << "Warning: there is no sign.id == " << id << '\n';

    return nullptr;
  }

  return std::make_shared<Sign>(*(find_result->second));
}

} // namespace module