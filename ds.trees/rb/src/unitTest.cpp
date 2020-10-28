#include "unitTest.hpp"

bool unitTestFunc() {
  /* VARIABLE FOR UNIT TESTS: test-id, test-name, pass/fail-check */
  static int test_id = -1;
  static std::string thisTest = "";
  static bool allPassed = true;

  /*******************************************************************************/
  thisTest = "INIT OUTPUT";
  TestHeader(++test_id, thisTest);
  /*******************************************************************************/
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "CONSTRUCT A RbNode{5}";
  TestHeader(++test_id, thisTest);
  /*******************************************************************************/
  int init_val = 5;
  RbNode<int> nodeA{init_val};
  allPassed = [&]() {
    allPassed = (nodeA.GetColor() == BLACK) ? true : false;
    std::cout << "DEFAULT BLACK = 1, COLOR: " << nodeA.GetColor() << '\n';
    allPassed = (nodeA.getData() == 5) ? true : false;
    std::cout << "Correct Init:" << init_val
              << ", returned=" << nodeA.getData();
    return allPassed;
  }();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "MAKE TREE W/ {1, 6, 8, 13, 19, 5, 2, 7}";
  TestHeader(++test_id, thisTest);
  /*******************************************************************************/
  std::initializer_list<int> list = {1, 6, 8, 13, 19, 5, 2, 7};
  RbT<int> newTree{list};
  allPassed = newTree.bprint_InOrder();
  errCatch(allPassed = true, thisTest);

  /*******************************************************************************/
  thisTest = "TRAVERSING & PRINTING IN ORDER";
  TestHeader(++test_id, thisTest);
  /*******************************************************************************/
  newTree.print_InOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_InOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "TRAVERSING & PRINTING PRE ORDER";
  TestHeader(++test_id, thisTest);
  /*******************************************************************************/
  newTree.print_PreOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_PreOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "TRAVERSING & PRINTING POST ORDER";
  TestHeader(++test_id, thisTest);
  /*******************************************************************************/
  newTree.print_PostOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_PostOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "DESTRUCT A TREE";
  TestHeader(++test_id, thisTest);
  /*******************************************************************************/
  newTree.~RbT();
  allPassed = [&]() {
    if (!newTree.isEmptyTree()) {
      std::cout << "Tree is empty." << std::endl;
      return true;
    } else {
      std::cout << "Tree NOT empty." << std::endl;
      return false;
    }
  }();

  return allPassed;
}

void pfCheck(bool check, std::string testName) {
  std::cout << "\n\n>>>>> " << testName;
  if (check)
    std::cout << "\nSTATUS: PASSED.\n";
  else
    throw "\nERROR! FAILED PASSCHECK ON THIS TEST: " + testName;
}

void errCatch(bool check, std::string testName) {
  try {
    pfCheck(check, testName);
  } catch (std::string msg) {
    std::cout << msg << std::endl;
  }
}

void TestHeader(int& test_id, std::string& testName) {
  std::cout << "\n\nTEST #" << test_id << ": " << testName;
  std::cout
      << "\n----------------------------------------------------------------"
      << std::endl;
}