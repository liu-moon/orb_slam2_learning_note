#include <iostream>
#include <map>

int main() {

  // 简单高效的for循环使用示例
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // 原来的循环方式
  for (int i = 0; i < 10; i++)
    std::cout << arr[i] << std::endl;

  // 使用auto命令后的循环方式
  for (auto n : arr)
    std::cout << n << std::endl;

  // 而且这种循环方式支持大部分数据类型，如数组、容器、字符串和迭代器等
  std::map<std::string, int> m{{"a", 1},
                               {"b", 2},
                               {"c", 3}};

  for (auto p : m) {
    std::cout << p.first << ":" << p.second << std::endl;
  }
}
