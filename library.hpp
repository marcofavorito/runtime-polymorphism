#pragma once

#include <ostream>
#include <memory>
#include <vector>

void draw(const int& x, std::ostream& out, size_t position){
  out << std::string(position, ' ') << x << std::endl;
}

class object_t{
public:
  object_t(const int& x) : self_(std::make_unique<int_model_t>(x)) {
    std::cout << "ctor" << std::endl;
  }

  // copy constructor - new object equal to and logically disjoint from, the original
  object_t(const object_t& x) : self_(std::make_unique<int_model_t>(*x.self_)) {
    std::cout << "copy" << std::endl;
  }

  // assignment consistent with copy. Satisfies the 'strong exception guarantee'.
  // pass sink arguments by value and swap or move into place
  object_t& operator=(object_t x){
    self_ = std::move(x.self_);
    return *this;
  }

  friend void draw(const object_t& x, std::ostream& out, size_t position){
    x.self_->draw_(out, position);
  }

private:
  struct int_model_t {
    int_model_t(const int& x) : data_(x) { }
    void draw_(std::ostream& out, size_t position) const{
      draw(data_, out, position);
    }
    int data_;
  };
  std::unique_ptr<int_model_t> self_;
};

using document_t = std::vector<object_t>;

void draw(const document_t& x, std::ostream& out, size_t position){
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto& e: x) draw(e, out, position + 2);
  out << std::string(position, ' ') << "</document>" << std::endl;
}
