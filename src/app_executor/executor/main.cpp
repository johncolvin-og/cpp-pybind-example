#include "executor/py_md_writer.h"
#include "pybind11/embed.h"
#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

int main() {
   py::scoped_interpreter guard{}; // Start the Python interpreter

   try {
      py::module sys = py::module::import("sys");
      sys.attr("path").attr("append")("/home/bts/cpp-pybind-example/py");
      py::module myplugin = py::module::import("myplugin");
      py::module my_implementation = py::module::import("md_writer_impl");
      py::object impl = my_implementation.attr("MdWriterImpl")();
      MdWriter* instance = impl.cast<MdWriter*>();
      instance->write_md("let us write the market data");
   } catch (const py::error_already_set& e) {
      std::cerr << "Error: " << e.what() << std::endl;
   }

   return 0;
}
