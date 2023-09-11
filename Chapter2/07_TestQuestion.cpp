/*
 * 目标：请使用 C++ 新特性改写下面代码。该函数功能：将一组无序的坐标按照"Z"字形排序，并输出
 *
 * 本程序学习目标：熟悉 C++ 新特性（简单循环、自动类型推导、列表初始化和 Lambda 函数）
 * */


#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

bool cmp(Point2i pt1, Point2i pt2) {
  if (pt1.x != pt2.x) {
    return (pt1.x < pt2.x);
  }
  if (pt1.y != pt2.y) {
    return (pt1.y < pt2.y);
  }
}

int main() {
  vector<Point2i> vec;
  vec.push_back(Point2i(2, 1));
  vec.push_back(Point2i(3, 3));
  vec.push_back(Point2i(2, 3));
  vec.push_back(Point2i(3, 2));
  vec.push_back(Point2i(3, 1));
  vec.push_back(Point2i(1, 3));
  vec.push_back(Point2i(1, 1));
  vec.push_back(Point2i(2, 2));
  vec.push_back(Point2i(1, 2));

  cout << "Before sort:" << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }

  sort(vec.begin(), vec.end(), cmp);

  cout << "After sort:" << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
  return 0;

}



