#include "unitTest.hpp"

bool unitTestFunc() {
  /* VARIABLE FOR UNIT TESTS: test-id, test-name, pass/fail-check */
  static int testNum = 0;
  static std::string thisTest = "";
  static bool allPassed = true;

  // TEST_ID: 00
  thisTest = "INIT OUTPUT";
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "--------------------------------------------------------\n";
  /* TEST_BODY STARTS BEOW */
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString << std::endl;
    return true;
  }();
  errCatch(allPassed, thisTest);

  // TEST_ID: 01
  thisTest = "Construct AvlNode, val=20";
  ++testNum;
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "--------------------------------------------------------\n";
  /* TEST_BODY STARTS BEOW */
  AvlNode<int> node_A{20};
  allPassed = [&]() {
    if (node_A.getData()) {
      std::cout << "node_A->data=" << node_A.getData() << std::endl;
      std::cout << "node_A->height=" << node_A.get_Hyt() << std::endl;
      std::cout << "\nvalue of nullptr: " << static_cast<void*>(nullptr)
                << std::endl;
      std::cout << "\tnode_A->left=" << node_A.GetL() << std::endl;
      std::cout << "\tnode_A->right=" << node_A.GetR() << std::endl;
      return true;
    } else
      return false;
  }();
  errCatch(allPassed, thisTest);

  // TEST_ID: 02
  thisTest = "Construct AVLT, {30, 10, 5, 12, 7, 8}";
  ++testNum;
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "--------------------------------------------------------\n";
  /* TEST_BODY STARTS BEOW */
  std::initializer_list<int> testList = {30, 10, 5, 12, 7, 8};
  AVLT<int> treeA{testList};
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
