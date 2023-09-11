/*
 * 目标：请使用 C++ 新特性改写下面代码。该函数功能：将一组无序的坐标按照"Z"字形排序，并输出
 *
 * 本程序学习目标：熟悉 C++ 新特性（简单循环、自动类型推导、列表初始化和 Lambda 函数）
 * */


#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
  vector<Point2i> vec{{2, 1}, {3, 3}, {2, 3}, {3, 2}, {3, 1}, {1, 3}, {1, 1}, {2, 2}, {1, 2}};

  cout << "Before sort:" << endl;
  for (auto point : vec) {
    cout << point << endl;
  }

  auto cmp = [](Point2i pt1, Point2i pt2) -> bool {
    if (pt1.x != pt2.x) {
      return (pt1.x < pt2.x);
    }
    if (pt1.y != pt2.y) {
      return (pt1.y < pt2.y);
    }
  };

  sort(vec.begin(), vec.end(), cmp);

  cout << "After sort:" << endl;
  for (auto point : vec) {
    cout << point << endl;
  }

  return 0;

}



