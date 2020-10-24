#include "unitTest.hpp"

bool unitTestFunc() {
  /* DECLARE A PASSMARK FLAG */
  static bool allPassed = true;
  static std::string thisTest = "";
  int testNum = 0;

  /* INIT TEST: OUTPUT STRING */
  thisTest = "INIT OUTPUT";
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "---------------------------------------------------\n";
  allPassed = []() {
    std::string tString = "\tTHIS IS A TEST STRING.";
    std::cout << tString << std::endl;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CREATE A NODE */
  thisTest = "Construct Node from value 30";
  ++testNum;
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "---------------------------------------------------\n";
  AvlNode<int> nd{30};
  allPassed = [&]() {
    if (nd.data != nullptr) {
      std::cout << "\t&node->data=" << nd.data << std::endl;
      std::cout << "\tnode->data=" << *nd.data << std::endl;
      return true;
    } else
      return false;
  }();
  errCatch(allPassed, thisTest);

  /* TEST: CONSTRUCT A LIST */
  thisTest = "Construct Tree from list {30, 10, 5, 12, 7, 8}";
  ++testNum;
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "---------------------------------------------------\n";
  std::initializer_list<int> list = {30, 10, 5, 12, 7, 8};
  AVL<int> treeA{list};
  treeA.printOrder_In();
  errCatch(allPassed = true, thisTest);

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