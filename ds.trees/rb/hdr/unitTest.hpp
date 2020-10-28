#ifndef UNITTEST_HPP
#define UNITTEST_HPP

/* Local Headers */
// #include "redblack.hpp"
#include "myrb.hpp"

/* NECCESSARY STL */
#include <iostream>

class Test {
 public:
  int id;
  std::string Name;
  Test() : id{-1}, Name{""} {}
};

/* Unit-Test Utility Functions */
bool unitTestFunc();
void pfCheck(bool, Test& test);
void errCatch(bool, Test& test);
void TestHeader(Test& test);

#endif