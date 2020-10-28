#include "easy.hpp"

void staircase(int n) {
  for (int line = 0; line < n; ++line) {
    for (int space = 1; space < n - line; ++space) {
      std::cout << ' ';
    }
    for (int pound = 0; pound < line + 1; ++pound) {
      std::cout << '#';
    }
    std::cout << '\n';
  }
}

void stairrecur(int n) {
  if (n <= 0) return;

  stairrecur(n - 1);
  for (int pound = 0; pound < n; ++pound) {
    std::cout << '#';
  }
  for (int space = n; space > 0; --space) {
    std::cout << ' ';
  }

  std::cout << '\n';
}

void stairrecur2(int n) {
  static int size = n;
  if (n >= 0) {
    for (int space = n; space > 0; --space) {
      std::cout << ' ';
    }
    for (int pound = 0; pound < size - n; ++pound) {
      std::cout << '#';
    }
    std::cout << '\n';
    stairrecur2(n - 1);
  }
}

void miniMaxSum(std::vector<int> arr) {
  int min, max;
  min = max = arr[0];
  int summin = 0, summax = 0;
  for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
    summin += arr[i];
    summax += arr[i];
  }
  summin -= max;
  summax -= min;
  std::cout << min << " " << max << std::endl;
  std::cout << summin << " " << summax << std::endl;
}

int birthdayCakeCandles(std::vector<int> candles) {
  int max = candles[0], count = 0;
  for (auto i : candles) {
    if (i > max) {
      max = i;
      count = 0;
    }
    if (i == max) ++count;
  }
  return count;
}

int max_of_four(int a, int b, int c, int d) {
  int arr[] = {a, b, c, d};
  int max = arr[0];
  for (int i = 0; i < 4; ++i)
    if (max < arr[i]) max = arr[i];

  return max;
}

std::string pairWithString(int n) {
  std::string str;
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

void varArr() {
  // Rewrite:
  /*
    first line is n q: n=number of rows, q= number of queries
    The best way to think about this is problem is that it has 3 main steps:
    step 1: get vector size and number of queries
    step 2: construct the vector with variable-sized vector members
    step 3: access random elements q times

    First I got the input step done, cin read into n and q.
    The next part is incomplete. Let's go back and examine it carefully.

   */
  int n = 0, q = 0, input = 0, size = 0;
  // Step 1: Get n and q:
  cin >> n >> q;

  // Step 2: Construct the vector of vectors
  vector<vector<int>> vec_Big;
  vector<int>* vec_Small;
  // Loop to construct the vector of vectors:
  for (int i = 0; i < n; ++i) {
    // from the first input, construct a new <int> vector of size=input
    cin >> size;
    vec_Small = new vector<int>;
    // then add new elements to that <int>:
    for (int j = 0; j < size; ++j) {
      cin >> input;
      vec_Small->push_back(input);
    }

    // then push *buff to vec_Big;
    vec_Big.push_back(*vec_Small);
    delete vec_Small;
  }

  // Loop to access random vector elements q times:
  vec_Small = new vector<int>;
  for (int i = 0; i < q; ++i) {
    int r, c;
    cin >> r >> c;
    vec_Small->push_back(r);
    vec_Small->push_back(c);
  }

  for (int i = 0; i < (q * 2); i += 2) {
    cout << vec_Big[(*vec_Small)[i]][(*vec_Small)[i + 1]] << '\n';
  }
}