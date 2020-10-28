#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>

/* Test Label: */
class Test {
 public:
  int id;
  std::string Name;
  Test() : id{-1}, Name{""} {}
};

/* Unit-Test Utility Functions */
void pfCheck(bool, Test& test);
void errCatch(bool, Test& test);
void TestHeader(Test& test);

#endif