#ifndef UNITTEST_HPP
#define UNITTEST_HPP

/* Local Headers */
// #include "redblack.hpp"
#include "myrb.hpp"

/* NECCESSARY STL */
#include <iostream>

/* Unit-Test Utility Functions */
bool unitTestFunc();
void pfCheck(bool, std::string);
void errCatch(bool, std::string);
void TestHeader(int& test_id, std::string& testName);
#endif
