#include <iostream>
#include <memory>

class Demo
{
public:
    Demo() { std::cout << "Demo 构造函数" << std::endl; }
    ~Demo() { std::cout << "Demo 析构函数" << std::endl; }
    void show() { std::cout << "Hello, 智能指针！" << std::endl; }
};

int main()
{
    // 1. unique_ptr 独占所有权
    std::unique_ptr<Demo> uptr(new Demo());
    uptr->show();
    // std::unique_ptr<Demo> uptr2 = uptr; // 错误，不能拷贝
    std::unique_ptr<Demo> uptr2 = std::move(uptr); // 可以转移所有权

    // 2. shared_ptr 共享所有权
    std::shared_ptr<Demo> sptr1 = std::make_shared<Demo>();
    std::shared_ptr<Demo> sptr2 = sptr1; // 引用计数+1
    std::cout << "sptr1 use_count: " << sptr1.use_count() << std::endl;

    // 3. weak_ptr 弱引用，不增加引用计数
    std::weak_ptr<Demo> wptr = sptr1;
    std::cout << "wptr use_count: " << wptr.use_count() << std::endl;
    if (auto spt = wptr.lock())
    { // 判断对象是否还存在
        spt->show();
    }

    // 离开作用域后，智能指针会自动释放资源
    return 0;
}