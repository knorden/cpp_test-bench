#include "unitTest.hpp"

bool unitTestFunc() {
  /* DECLARE A PASSMARK FLAG */
  static bool allPassed = true;
  static std::string thisTest = "";

  /* INIT TEST: OUTPUT STRING */
  thisTest = "INIT OUTPUT";
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString << std::endl;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CREATE A NODE */
  thisTest = "Construct a Node";
  AvlNode<int> nd{30};
  allPassed = [&]() {
    if (nd.data != NULL) {
      std::cout << "node->data=" << nd.data << std::endl;
      return true;
    } else
      return false;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: */

  return allPassed;
}

void pfCheck(bool check, std::string testName) {
  std::cout << ">>>>> " << testName << ": ";
  if (check)
    std::cout << "PASSED." << std::endl;
  else
    throw "\nERROR: FAILED PASSCHECK ON TEST: " + testName;
}

void errCatch(bool check, std::string testName) {
  try {
    pfCheck(check, testName);
  } catch (std::string msg) {
    std::cout << msg << std::endl;
  }
}