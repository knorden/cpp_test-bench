#include "unitTest.hpp"

bool unitTestFunc() {
  /* Declare parameters for Passmark Flag & Test IDs */
  static bool allPassed = true;
  static std::string thisTest = "";
  static int testNum = 0;

  /* INIT TEST: OUTPUT STRING */
  thisTest = "INIT OUTPUT";
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "---------------------------------------------------\n";
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString << std::endl;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: */
  thisTest = "";
  ++testNum;
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "---------------------------------------------------\n";
  BSTNode *root = nullptr;
  root->insert(root, 3);
  root->insert(root, 5);
  root->insert(root, 7);
  root->insert(root, 1);
  root->insert(root, 2);
  root->insert(root, 9);
  
  /* TEST: */
  thisTest = "";
  ++testNum;
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "---------------------------------------------------\n";
  bool isB = true;
  isB = root->isBalanced(root, isB);
  std::cout << isB;
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
