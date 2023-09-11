#include <iostream>
#include <vector>
#include <map>

int main()
{
    // 不同数据类型的列表初始化方法示例
    // 定义变量b并用列表初始化的方式初始化为3.14
    double b = double{3.14};

    // 定义int类型数组arr并用列表初始化的方式初始化为1,2,3
    int arr[3]{1, 2, 3};

    // 定义int类型容器iv并用列表初始化的方式初始化为1,2,3
    std::vector<int> iv{1,2,3};

    // 定义<int,string>类型map容器m并用列表初始化的方式初始化为{1,"a"},{2,"b"}
    std::map<int,std::string> m{{1, "a"}, {2, "b"}};

    // 定义string类型变量str并用列表初始化的方式初始化为"Hello World!"
    std::string str{"Hello World!"};

    // 定义int类型指针a并用列表初始化的方式初始化为3
    int* a = new int{3};

    // 定义int类型数组指针Arr并用列表初始化的方式初始化为1,2,3
    int* Arr = new int[]{1,2,3};

    return 0;
}