#pragma once

#include <ostream>
#include <memory>
#include <vector>
#include <cassert>

template <typename T>
void draw(const T& x, std::ostream& out, size_t position){
  out << std::string(position, ' ') << x << std::endl;
}

class object_t{
public:
  template <typename T>
  object_t(T x) : self_(std::make_shared<model<T>>(std::move(x))) { }

  friend void draw(const object_t& x, std::ostream& out, size_t position){
    x.self_->draw_(out, position);
  }

private:
  struct concept_t {
    virtual ~concept_t() = default;
    virtual void draw_(std::ostream&, size_t) const = 0;
  };
  template <typename T>
  struct model final : concept_t {
    model(T x) : data_(std::move(x)) { }
    void draw_(std::ostream& out, size_t position) const override {
      draw(data_, out, position);
    }
    T data_;
  };

  // shared pointer to immutable object has value semantics
  std::shared_ptr<const concept_t> self_;
};

using document_t = std::vector<object_t>;

void draw(const document_t& x, std::ostream& out, size_t position){
  out << std::string(position, ' ') << "<document>" << std::endl;
  for (const auto& e: x) draw(e, out, position + 2);
  out << std::string(position, ' ') << "</document>" << std::endl;
}

using history_t = std::vector<document_t>;

void commit(history_t& x) { assert(x.size()); x.push_back(x.back());}
void undo(history_t& x) { assert(x.size()); x.pop_back();}
document_t& current(history_t& x) { assert(x.size()); return x.back(); }
