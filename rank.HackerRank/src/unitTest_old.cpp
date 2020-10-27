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
  /* TEST_BODY STARTS BELOW */
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString;
    return true;
  }();
  errCatch(allPassed, thisTest);

  // TEST_ID: 01
  thisTest = "FizzBuzz";
  ++testNum;
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "--------------------------------------------------------\n";
  /* TEST_BODY STARTS BELOW */
  std::string fizzbuzz = "";
  allPassed = [&]() {
    for (int i = 0; i < 10; ++i) {
      fizzbuzz +=
          (i % 3 == 0 && i % 5 == 0)
              ? "FizzBuzz"
              : (i % 3 == 0)
                    ? "Fizz"
                    : (i % 5 == 0) ? "Buzz" : " " + std::to_string(i) + " ";
    }
    std::cout << fizzbuzz;
    return true;
  }();
  errCatch(allPassed, thisTest);

  // TEST_ID: 03
  thisTest = "";
  std::cout << "\n\nTEST #" << testNum << ": " + thisTest << std::endl;
  std::cout << "--------------------------------------------------------\n";
  /* TEST_BODY STARTS BELOW */

  // std::vector<std::vector<int>> vec{{1,2,3}, {4,5,6}, {7,8,9}};

  // int sum = [&]() {
  //   int s = 0, j = vec.size() - 1, sdown = 0, sup = 0;
  //   for (int i = 0; i < vec.size(); ++i) {
  //     sdown += vec[i][i];
  //     sup += vec[j][i];
  //     --j;
  //   }
  //   std::cout << sdown << " " << sup;
  //   abs(s = sdown - sup);
  //   return s;
  // }();
  // std::cout << "\nall sum=" << sum;

  // std::vector<int> arr{-4, 3, -9, 0, 4, 1};

  // float pos = 0, neg = 0, zero = 0;
  // for (auto i : arr) {
  //   zero += (i == 0) ? 1 : 0;
  //   pos += (i > 0) ? 1 : 0;
  //   neg += (i < 0) ? 1 : 0;
  // }
  // std::cout << std::fixed << std::setprecision(6) << (pos / arr.size())
  //           << std::endl;
  // std::cout << std::fixed << std::setprecision(6) << (neg / arr.size())
  //           << std::endl;
  // std::cout << std::fixed << std::setprecision(6) << (zero / arr.size())
  //           // << std::endl;
  

  // call the unit test function,
  // unitTestFunc();
  // staircase(6);
  // std::cout << "\n";
  // stairrecur(6);
  // std::cout << "\n";
  // stairrecur2(6);
  std::vector<int> arr{44, 53, 31, 27, 77, 60, 66, 77, 26, 36};

  // miniMaxSum(arr);
  std::cout << birthdayCakeCandles(arr);
  return allPassed;
}

void pfCheck(bool check, std::string testName) {
  std::cout << "\n>>>>> " << testName << ": ";
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
