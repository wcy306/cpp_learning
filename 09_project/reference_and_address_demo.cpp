#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    // 取地址符：获取变量a的地址
    int *p = &a;
    cout << "a的值: " << a << endl;
    cout << "a的地址: " << &a << endl;
    cout << "p的值(即a的地址): " << p << endl;
    cout << "通过指针p访问a的值: " << *p << endl;

    // 引用：ref是a的别名
    int &ref = a;
    ref = 20; // 修改ref其实就是修改a
    cout << "通过ref修改后的a的值: " << a << endl;

    // 引用作为函数参数
    auto addOne = [](int &x)
    {
        x = x + 1;
    };
    addOne(a);
    cout << "addOne后a的值: " << a << endl;

    return 0;
}