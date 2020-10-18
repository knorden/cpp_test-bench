#include "unitTest.hpp"

bool unitTestFunc() {

  /* DECLARE A PASSMARK FLAG */
  static bool allPassed = true;
  static std::string thisTest = "";

  /* INIT TEST: OUTPUT STRING */
  thisTest = "INIT OUTPUT";
  std::cout << "\n\n";
  std::cout << "TEST #0: " << thisTest << "\n\t";
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString << std::endl;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CONSTRUCT A RbNode */
  thisTest = "CONSTRUCT A RbNode{5}";
  std::cout << "\n\n";
  std::cout << "TEST #1: " << thisTest << "\n\t";
  RbNode<int> nodeA{5};
  allPassed = [&]() {
    if (&nodeA.data != nullptr) {
      std::cout << "nodeA->data=" << nodeA.data << std::endl;
      return true;
    } else
      return false;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CONSTRUCT A RB TREE */
  thisTest = "CONSTRUCT A RB TREE";
  std::cout << "\n\n";
  std::cout << "TEST #2: " << thisTest << "\n\t";

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