
#include "utilities.hpp"

void pfCheck(bool check, Test& test) {
  std::cout << "\n\n>>>>> " << test.Name;
  if (check)
    std::cout << "\nSTATUS: PASSED." << std::endl;
  else
    throw "\nERROR! FAILED PASSCHECK ON TEST#" + std::to_string(test.id) +
        ": " + test.Name;
}

void errCatch(bool check, Test& test) {
  try {
    pfCheck(check, test);
  } catch (std::string msg) {
    std::cout << msg << std::endl;
  }
}

void TestHeader(Test& test) {
  ++test.id;
  std::cout << "\n\nTEST #" << test.id << ": " << test.Name;
  std::cout
      << "\n----------------------------------------------------------------"
      << std::endl;
}