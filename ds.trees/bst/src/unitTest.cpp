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

  /* TEST: CREATE A BinNode */
  thisTest = "Construct a BinNode";
  BinNode<int> nd{5};
  // Node<int> nd{5};
  allPassed = [&]() {
    if (nd.data != NULL) {
      // if (nd.value != NULL) {
      return true;
    } else
      return false;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CREATE A BST */
  thisTest = "Insert into a BST";
  BST<int> testBST;
  testBST.insert(3);
  testBST.insert(5);
  testBST.insert(6);
  testBST.insert(1);
  testBST.printOrder_IN();

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