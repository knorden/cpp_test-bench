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