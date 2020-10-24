#ifndef UNITTEST_HPP
#define UNITTEST_HPP

/* NECCESSARY STL */
#include <iostream>

#include "myavl.hpp"

/* FUNCTION: WRAPPER FOR UNIT TESTS */
bool unitTestFunc();

/* FUNCTION: PASS/FAIL CHECK */
void pfCheck(bool, std::string);

/* FUNCTION: VERY BASIC ERROR CATCHER */
void errCatch(bool, std::string);

#endif
