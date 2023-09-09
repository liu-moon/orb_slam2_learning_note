#include <iostream>
#include <map>

int main()
{
    std::map<int,char> m{{10,'a'},{99,'-'},{-100,'0'}};
    /*
    m[10] = 'a';
    m[99] = '-';
    m[-100] = '0';
    */

    std::cout << m.size() << std::endl;
    if (m.count(99)==1){
        std::cout << m[99] << std::endl;
    }

    m.erase(99);

    if (m.count(99)!=1){
        std::cout << "not found" << std::endl;
    }

    m[6] = '\\';
    m[-5] = '|';

    for (auto iv = m.begin();iv != m.end(); iv++){
        std::cout << iv->first << " " << iv->second << std::endl;
    }

    return 0;
}