// #include <iostream>
//
// int main() {
//
//     // 列表初始化
//     double b = double {12.12};
//     int arr[3]{1, 2, 3};
//     // 打印输出
//     std::cout << b << std::endl;
//
//     for(auto n:arr)
//         std::cout << n << std::endl;
//
//
//     return 0;
// }

// #include <iostream>
// #include <tuple>
//
// int main()
// {
//     // tuple 使用示例
//
//     // 不同数据类型的组合
//     // tup1
//     std::tuple<float,std::string> tup1(3.14,"pi");
//     std::cout << "tup1 = " << std::endl;
//     std::cout << std::get<0>(tup1) << std::endl;
//     std::cout << std::get<1>(tup1) << std::endl;
//
//     // tup2
//     std::tuple<int,char> tup2(10,'a');
//     std::cout << "tup2 = " << std::endl;
//     std::cout << std::get<0>(tup2) << std::endl;
//     std::cout << std::get<1>(tup2) << std::endl;
//
//     // tup3
//     // tuple_cat 连接两个 tuple
//     auto tup3 = std::tuple_cat(tup1,tup2);
//     std::cout << "tup3 = " << std::endl;
//     std::cout << std::get<0>(tup3) << std::endl;
//     std::cout << std::get<1>(tup3) << std::endl;
//     std::cout << std::get<2>(tup3) << std::endl;
//     std::cout << std::get<3>(tup3) << std::endl;
//
//     // tup4
//     // make_tuple 创建 tuple并初始化
//     auto tup4 = std::make_tuple("Hello World!",'a',3.14,0);
//     std::cout << "tup4 = " << std::endl;
//     std::cout << std::get<0>(tup4) << std::endl;
//     std::cout << std::get<1>(tup4) << std::endl;
//     std::cout << std::get<2>(tup4) << std::endl;
//     std::cout << std::get<3>(tup4) << std::endl;
//
//     // tup5
//     // tie 解包：tuple拆分
//     // tie 用于将 tuple 中的元素解包到变量中
//     auto tup5 = std::make_tuple(3.14,1,'a');
//     double a; int b; char c;
//     // 结果是 a=3.14，b=1，c='a'
//     std::tie(a,b,c) = tup5;
//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "c = " << c << std::endl;
//
//     return 0;
// }





#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

bool cmp(Point2i pt1, Point2i pt2){
    if(pt1.x != pt2.x){
        return (pt1.x < pt2.x);
    }
    if(pt1.y != pt2.y){
        return (pt1.y < pt2.y);
    }
}

int main()
{
    vector<Point2i> vec;
    vec.push_back(Point2i(2,1));
    vec.push_back(Point2i(3,3));
    vec.push_back(Point2i(2,3));
    vec.push_back(Point2i(3,2));
    vec.push_back(Point2i(3,1));
    vec.push_back(Point2i(1,3));
    vec.push_back(Point2i(1,1));
    vec.push_back(Point2i(2,2));
    vec.push_back(Point2i(1,2));

    cout << "Before sort:" << endl;
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }

    sort(vec.begin(),vec.end(),cmp);

    cout << "After sort:" << endl;
    for (int i=0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }
    return 0;


}



