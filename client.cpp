#include <iostream>
#include <algorithm>
#include "library.hpp"

class my_class_t {

};

void draw(const my_class_t&, std::ostream& out, size_t position){
  out << std::string(position, ' ') << "my_class_t" << std::endl;
}

int main(){
  document_t document;
  document.reserve(5);

  document.emplace_back(0);
  document.emplace_back("Hello!");
  document.emplace_back(document);
  document.emplace_back(my_class_t());

  draw(document, std::cout, 0);
}