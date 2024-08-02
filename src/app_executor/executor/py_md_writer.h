#pragma once
#include "md_writer.h"

#include <pybind11/pybind11.h>

namespace py = pybind11;

class PyMdWriter : public MdWriter {
public:
  using MdWriter::MdWriter;

  ~PyMdWriter() override;

  void write_md(std::string value) override {
    PYBIND11_OVERLOAD_PURE(void,     /* Return type */
                           MdWriter, /* Parent class */
                           write_md, /* Function name */
                           value     /* Argument */
    );
  }
};
