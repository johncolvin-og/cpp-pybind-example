// binding.cpp
#include <pybind11/pybind11.h>
#include "py_md_writer.h"

namespace py = pybind11;

PYBIND11_MODULE(myplugin, m) {
    py::class_<MdWriter, PyMdWriter>(m, "MdWriter")
        .def(py::init<>())
        .def("write_md", &MdWriter::write_md);
}
