#include <pybind11/pybind11.h>

#include <iostream>
#include <string>

#include "pet.h"

namespace py = pybind11;

class cat : public pet {
 public:
  cat(std::string name) : name_(name) {}

  void speak() override { std::cout << "Meow! " << name_ << '\n'; }

 private:
  std::string name_;
};

PYBIND11_MODULE(cats, m) {
  py::class_<pet>(m, "Pet", py::module_local()).def("speak", &pet::speak);
  py::class_<cat, pet>(m, "Cat").def(py::init<std::string>());
}
