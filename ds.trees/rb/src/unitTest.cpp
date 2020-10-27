#include "unitTest.hpp"

bool unitTestFunc() {
  /* DECLARE A PASSMARK FLAG */
  static bool allPassed = true;
  static std::string thisTest = "";

  /* INIT TEST: OUTPUT STRING */
  thisTest = "INIT OUTPUT";
  std::cout << "\n\n";
  std::cout << "TEST #0: " << thisTest << "\n";
  allPassed = []() {
    std::string tString = "\tTHIS IS A TEST STRING.";
    std::cout << tString << std::endl;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CONSTRUCT A RbNode */
  thisTest = "CONSTRUCT A RbNode{5}";
  std::cout << "\n\n";
  std::cout << "TEST #1: " << thisTest << "\n";
  int init_val = 5;
  RbNode<int> nodeA{init_val};
  allPassed = [&]() {
    allPassed = (nodeA.GetColor() == BLACK) ? true : false;
    std::cout << "\tDEFAULT BLACK = 1, COLOR: " << nodeA.GetColor()
              << std::endl;
    allPassed = (nodeA.getData() == 5) ? true : false;
    std::cout << "\tCorrect Init:" << init_val
              << ", returned=" << nodeA.getData() << std::endl;
    return allPassed;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CONSTRUCT A RbT */
  thisTest = "CONSTRUCT A RB TREE";
  std::cout << "\n\n";
  std::cout << "TEST #2: " << thisTest << "\n\t";

  /* TEST: */
  thisTest = "CONSTRUCT A RB TREE";
  std::cout << "\n\n";
  std::cout << "TEST #2: " << thisTest << "\n\t";

  /* TEST: */
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