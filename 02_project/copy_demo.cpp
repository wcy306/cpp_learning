#include <iostream>
#include <cstring>

class Student
{
private:
    char *name; // 使用指针成员来演示拷贝问题
    int age;

public:
    // 构造函数
    Student(const char *n, int a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
        std::cout << "构造函数被调用" << std::endl;
    }

    // 析构函数
    ~Student()
    {
        delete[] name;
        std::cout << "析构函数被调用" << std::endl;
    }

    // 显示学生信息
    void display()
    {
        std::cout << "姓名: " << name << ", 年龄: " << age << std::endl;
    }

    // 修改姓名
    void setName(const char *n)
    {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
};

int main()
{
    // 创建第一个学生对象
    Student s1("张三", 20);
    std::cout << "s1的信息：" << std::endl;
    s1.display();

    // 浅拷贝（默认拷贝构造函数）
    Student s2 = s1; // 这里会发生浅拷贝
    std::cout << "\n浅拷贝后s2的信息：" << std::endl;
    s2.display();

    // 修改s2的姓名
    std::cout << "\n修改s2的姓名后：" << std::endl;
    s2.setName("李四");
    s2.display();

    // 查看s1的信息是否受到影响
    std::cout << "\n修改s2后s1的信息：" << std::endl;
    s1.display();

    return 0;
}