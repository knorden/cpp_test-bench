#include "unitTest.hpp"

bool unitTestFunc() {
  /* VARIABLE FOR UNIT TESTS: test-id, test-name, pass/fail-check */
  static Test thisTest;
  static bool allPassed = true;

  /*******************************************************************************/
  thisTest.Name = "INIT OUTPUT";
  TestHeader(thisTest);
  /*******************************************************************************/
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest.Name = "CONSTRUCT A RbNode{5}";
  TestHeader(thisTest);
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
  thisTest.Name = "MAKE TREE W/ {1, 6, 8, 13, 19, 5, 2, 7}";
  TestHeader(thisTest);
  /*******************************************************************************/
  std::initializer_list<int> list = {1, 6, 8, 13, 19, 5, 2, 7};
  RbT<int> newTree{list};
  allPassed = newTree.bprint_InOrder();
  errCatch(allPassed = true, thisTest);

  /*******************************************************************************/
  thisTest.Name = "TRAVERSING & PRINTING IN ORDER";
  TestHeader(thisTest);
  /*******************************************************************************/
  newTree.print_InOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_InOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest.Name = "TRAVERSING & PRINTING PRE ORDER";
  TestHeader(thisTest);
  /*******************************************************************************/
  newTree.print_PreOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_PreOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest.Name = "TRAVERSING & PRINTING POST ORDER";
  TestHeader(thisTest);
  /*******************************************************************************/
  newTree.print_PostOrder();
  std::cout << '\n';
  allPassed = newTree.bprint_PostOrder();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest.Name = "UPDATING THE TREE";
  TestHeader(thisTest);
  /*******************************************************************************/

  // /*******************************************************************************/
  // thisTest.Name = "CLEAR A TREE";
  // TestHeader(thisTest);
  // /*******************************************************************************/
  // newTree.clearTree();
  // allPassed = [&]() {
  //   if (!newTree.isEmptyTree()) {
  //     std::cout << "Tree is empty." << std::endl;
  //     return true;
  //   } else {
  //     std::cout << "Tree NOT empty." << std::endl;
  //     return false;
  //   }
  // }();
  // errCatch(allPassed, thisTest);

  // /*******************************************************************************/
  // thisTest.Name = "DESTRUCT A TREE";
  // TestHeader(thisTest);
  // /*******************************************************************************/
  // newTree.~RbT();
  // allPassed = [&]() {
  //   if (!newTree.isEmptyTree()) {
  //     std::cout << "Tree is empty." << std::endl;
  //     return true;
  //   } else {
  //     std::cout << "Tree NOT empty." << std::endl;
  //     return false;
  //   }
  // }();
  // errCatch(allPassed, thisTest);

  return allPassed;
}

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