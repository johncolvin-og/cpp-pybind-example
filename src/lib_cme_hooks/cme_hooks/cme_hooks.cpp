#include "cme_hooks.h"

#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>

#include <iostream>

namespace bts::cme_hooks {

CmeHooks::~CmeHooks() = default;

int add(int i, int j) { return i + j; }

PYBIND11_MODULE(cme_hooks, m) {
   m.doc() = "pybind11 example plugin";
   m.def("add", &add, "A function that adds two numbers");
   pybind11::class_<CmeHooks>(m, "CmeHooks")
       .def(pybind11::init())
       .def("on_depth", &CmeHooks::on_depth)
       .def("on_ticker", &CmeHooks::on_ticker);
}

} // namespace bts::cme_hooks
