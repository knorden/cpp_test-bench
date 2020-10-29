#include "unitTest.hpp"

int main() {
  // call the unit test function
  bool passed = unitTestFunc();
  if (passed) std::cout << "\n\nALL TESTS HAVE PASSED.\n";

  return 0;
}