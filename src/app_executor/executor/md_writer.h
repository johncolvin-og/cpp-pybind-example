#pragma once

#include <string>

class MdWriter {
public:
  virtual ~MdWriter() = 0;
  virtual void write_md(std::string value) = 0;
};
