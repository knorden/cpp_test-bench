#ifndef HASHING_HPP
#define HASHING_HPP
#include <iostream>

template <typename T>
class hash {
 public:
  size_t operator()(const T& Key) const;
};

template <>
class hash<std::string> {
 public:
  size_t operator()(const std::string& Key) {
    size_t hashVal = 0;

    for (char ch : Key) {
      hashVal = 37 * hashVal + ch;
    }
    return hashVal;
  }
};

// Add a template class hash for specific ADT below:

#endif