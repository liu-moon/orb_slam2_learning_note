#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 自动类型推导auto命令的使用示例
    // 在没有使用auto命令的情况下进行推导
    for (std::vector<int>::const_iterator itr = vec.cbegin(); itr != vec.cend(); ++itr) {}

    // 使用auto命令进行自动类型推导
    // 由于vec.cbegin()将返回std::vector<int>::const_iterator类型
    // 因此itr也应该是std::vector<int>::const_iterator类型的
    for (auto itr = vec.cbegin(); itr != vec.cend(); ++itr) {}

    // auto命令使用示例
    auto x = 5;     // 正确，auto被推导为int类型
    const auto *v = &x; // 正确，auto被推导为const int* 类型
//    auto int r;         // 错误，auto不能代表一个实际的类型声明
//    auto s; // 错误，auto无法推导出s的类型（必须马上初始化）
}