#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    { // 虚函数
        cout << "动物在叫" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak() override
    { // 重写父类方法
        cout << "狗在汪汪叫" << endl;
    }
};

void makeSound(Animal *animal)
{
    animal->speak(); // 调用的是实际对象的speak
}

int main()
{
    Dog d;
    makeSound(&d); // 输出：狗在汪汪叫
    return 0;
}