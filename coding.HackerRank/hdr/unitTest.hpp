#ifndef UNITTEST_HPP
#define UNITTEST_HPP

/* Headers: */
#include "easy.hpp"

// Tested functions

/* FUNCTION: WRAPPER FOR UNIT TESTS */
bool unitTestFunc();
/* FUNCTION: PASS/FAIL CHECK */
void pfCheck(bool, std::string);
/* FUNCTION: VERY BASIC ERROR CATCHER */
void errCatch(bool, std::string);

#endif