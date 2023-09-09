#include <iostream>
#include <tuple>
int main() {

  // tuple使用示例

  std::tuple<float, std::string> tup1(3.14, "pi");
  std::tuple<int, char> tup2(10, 'a');
  auto tup3 = tuple_cat(tup1, tup2);
  auto tup4 = std::make_tuple("Hello World!", 'a', 3.14, 0);

  // 方便拆分
  auto tup5 = std::make_tuple(3.14, 1, 'a');
  double a;
  int b;
  char c;
  std::tie(a, b, c) = tup5;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  return 0;
}