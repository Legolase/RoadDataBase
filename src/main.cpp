// #include <cstdint>
// #include <iostream>
// #include <memory>
#include <pybind11/pybind11.h>
// #include <stdexcept>
// #include <string>
// #include <unordered_map>
#include "RoadDB.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(RoadDataBase, m) {
  using namespace module;
  py::class_<Coordinate>(m, "Coordinate")
      .def(py::init<int, int>())
      .def("__eq__", static_cast<bool (Coordinate::*)(const Coordinate&) const & noexcept>(&Coordinate::isEqual))
      .def_readwrite("longitude", &Coordinate::longitude)
      .def_readwrite("latitude", &Coordinate::latitude)
      .def("__repr__", &Coordinate::toSting);

  py::class_<Sign, std::shared_ptr<Sign>>(m, "Sign")
      .def(py::init<std::string, int, const Coordinate &>())
      .def("__eq__", static_cast<bool (*)(const Sign::Ptr, const Sign::Ptr)>(&isEqual))
      .def_readwrite("name", &Sign::name_)
      .def_readwrite("coordinate", &Sign::coordinate_)
      .def_readonly("id", &Sign::id_);

  py::class_<RoadDB>(m, "RoadDB")
      .def(py::init<>())
      .def("insert", &RoadDB::insert)
      .def("erase", &RoadDB::erase)
      .def("find", &RoadDB::find);

#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
