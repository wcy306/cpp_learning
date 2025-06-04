#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    // const成员函数，只能读取成员变量，不能修改
    void showInfo() const
    {
        cout << "名字: " << name << ", 年龄: " << age << endl;
        // age = 20; // 这一行如果取消注释，会编译报错
    }

    // 普通成员函数，可以修改成员变量
    void setAge(int a)
    {
        age = a;
    }
};

int main()
{
    const Person p1("小明", 18); // p1是const对象
    p1.showInfo();               // 可以调用const成员函数
    // p1.setAge(20); // 这一行如果取消注释，会编译报错，因为setAge不是const成员函数

    Person p2("小红", 20); // 普通对象
    p2.showInfo();         // 可以调用
    p2.setAge(22);         // 也可以调用
    p2.showInfo();         // 年龄变了

    return 0;
}