#pragma once

#include <ostream>
#include <memory>
#include <vector>

class object_t{
public:
  virtual ~object_t() {}
  virtual void draw(std::ostream&, size_t) const = 0;
};

using document_t = std::vector<std::shared_ptr<object_t>>;

void draw(const document_t& x, std::ostream& out, size_t position){
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto& e: x) e->draw(out, position + 2);
  out << std::string(position, ' ') << "</document>" << std::endl;
}
