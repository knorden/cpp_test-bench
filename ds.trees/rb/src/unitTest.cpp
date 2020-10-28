#include "unitTest.hpp"

bool unitTestFunc() {
  /* DECLARE A PASSMARK FLAG */
  static bool allPassed = true;
  static std::string thisTest = "";
  static int test_id = 0;

  /*******************************************************************************/
  thisTest = "INIT OUTPUT";
  TestHeader(test_id, thisTest);
  /*******************************************************************************/
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "CONSTRUCT A RbNode{5}";
  ++test_id;
  TestHeader(test_id, thisTest);
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
  ++test_id;
  TestHeader(test_id, thisTest);
  /*******************************************************************************/
  std::initializer_list<int> list = {1, 6, 8, 13, 19, 5, 2, 7};
  RbT<int> newTree{list};
  allPassed = newTree.bprint_InOrder();
  errCatch(allPassed = true, thisTest);

  /*******************************************************************************/
  thisTest = "TRAVERSING & PRINTING IN ORDER";
  ++test_id;
  TestHeader(test_id, thisTest);
  /*******************************************************************************/
  newTree.print_InOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_InOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "TRAVERSING & PRINTING PRE ORDER";
  ++test_id;
  TestHeader(test_id, thisTest);
  /*******************************************************************************/
  newTree.print_PreOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_PreOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "TRAVERSING & PRINTING POST ORDER";
  ++test_id;
  TestHeader(test_id, thisTest);
  /*******************************************************************************/
  newTree.print_PostOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_PostOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest = "DESTRUCT A TREE";
  ++test_id;
  TestHeader(test_id, thisTest);
  /*******************************************************************************/
  newTree.clearTree();
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
  std::cout << "\n\n>>>>> " << testName << "\n";
  if (check)
    std::cout << "STATUS: PASSED." << std::endl;
  else
    throw "\nERROR! FAILED PASSCHECK ON TEST: " + testName;
}

void errCatch(bool check, std::string testName) {
  try {
    pfCheck(check, testName);
  } catch (std::string msg) {
    std::cout << msg << std::endl;
  }
}

void TestHeader(int test_id, std::string thisTest) {
  std::cout << "\n\n";
  std::cout << "TEST #" << test_id << ": " << thisTest << "\n";
  std::cout
      << "----------------------------------------------------------------\n";
}