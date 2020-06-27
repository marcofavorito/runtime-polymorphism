#include <iostream>
#include <algorithm>
#include "library.hpp"

int main(){
  document_t document;
  document.reserve(5);

  document.emplace_back(0);
  document.emplace_back("Hello!");
  document.emplace_back(2);
  document.emplace_back(3);

  draw(document, std::cout, 0);
}