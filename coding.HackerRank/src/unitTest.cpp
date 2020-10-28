#include "unitTest.hpp"

using namespace std;
bool unitTestFunc() {
  //   int a = 5, b = 12;
  //   for (int i = a; i <= b; ++i) {
  //     cout << "test" << i  << ":" << pairWithString(i) << "\n";
  //   }
  //   std::cout << "max = " << max_of_four(5, 2, 3, 4);

  // WIP:
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
