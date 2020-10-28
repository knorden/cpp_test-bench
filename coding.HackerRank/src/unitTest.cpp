#include "unitTest.hpp"

using namespace std;
bool unitTestFunc() {
  //   int a = 5, b = 12;
  //   for (int i = a; i <= b; ++i) {
  //     cout << "test" << i  << ":" << pairWithString(i) << "\n";
  //   }

  //   std::cout << "max = " << max_of_four(5, 2, 3, 4);
  varArr();
  return true;
}

void varArr() {
  // Rewrite:
  /*
    first line is n q: n=number of rows, q= number of queries
  */
  int n = 0, q = 0, input = 0;
  cin >> n >> q;
  vector<vector<int>> vec;
  vector<int>* inp;
  vector<int>* buff;
  for (int i = 0; i < n; ++i) {
    int j = i;
    inp = new vector<int>[i];
    while (cin >> input && i == j) {
      inp->push_back(input);
    }
    ++j;
    buff = new vector<int>[(*inp)[0]];
    for (int i = 1; i < static_cast<int>(inp->size()); ++i)
      buff->push_back((*inp)[i]);
  }
  for (int i = 0; i < q; ++i) {
    while (cin >> n >> input) {
      cout << vec[n][input];
    }
  }
}

int max_of_four(int a, int b, int c, int d) {
  int arr[] = {a, b, c, d};
  int max = arr[0];
  for (int i = 0; i < 4; ++i)
    if (max < arr[i]) max = arr[i];

  return max;
}

string pairWithString(int n) {
  string str;
  str = (n == 1)
            ? "one"
            : (n == 2)
                  ? "two"
                  : (n == 3)
                        ? "three"
                        : (n == 4)
                              ? "four"
                              : (n == 5)
                                    ? "five"
                                    : (n == 6)
                                          ? "six"
                                          : (n == 7)
                                                ? "seven"
                                                : (n == 8)
                                                      ? "eight"
                                                      : (n == 9)
                                                            ? "nine"
                                                            : (n > 9)
                                                                  ? (n % 2 == 0)
                                                                        ? "even"
                                                                        : "odd"
                                                                  : "";
  return str;
}