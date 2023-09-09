#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec{0, 11, 3, 19, 22, 7, 1, 5};

  auto f = [](int a, int b) {
    return a < b;
  };

  sort(vec.begin(), vec.end(), f);

  for (auto i : vec) {
    cout << i << " ";
  }
}