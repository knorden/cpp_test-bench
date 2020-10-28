#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include "easy.hpp"
/* FUNCTION: WRAPPER FOR UNIT TESTS */
bool unitTestFunc();
/* FUNCTION: PASS/FAIL CHECK */
void pfCheck(bool, std::string);
/* FUNCTION: VERY BASIC ERROR CATCHER */
void errCatch(bool, std::string);

std::string pairWithString(int n);

int max_of_four(int a, int b, int c, int d);

void varArr();

#endif