#include <pybind11/pybind11.h>

#include <iostream>
#include <string>

#include "pet.h"

namespace py = pybind11;

class dog : public pet {
 public:
  dog(std::string name) : name_(name) {}

  void speak() override { std::cout << "Woof! " << name_ << '\n'; }

 private:
  std::string name_;
};

PYBIND11_MODULE(dogs, m) {
  py::class_<pet>(m, "Pet", py::module_local()).def("speak", &pet::speak);
  py::class_<dog, pet>(m, "Dog").def(py::init<std::string>());
}
