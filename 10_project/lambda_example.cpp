#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // 1. 最简单的lambda：无参数、无返回值
    auto hello = []()
    {
        std::cout << "Hello, Lambda!" << std::endl;
    };
    hello();

    // 2. 带参数和返回值的lambda
    auto add = [](int a, int b)
    {
        return a + b;
    };
    std::cout << "2 + 3 = " << add(2, 3) << std::endl;

    // 3. 捕获外部变量
    int x = 10;
    int y = 20;
    auto printSum = [x, &y]()
    {
        std::cout << "x + y = " << x + y << std::endl;
    };
    y = 30;     // 修改y的值
    printSum(); // x=10, y=30, 输出 x + y = 40

    // 4. 在STL算法中使用lambda
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "原始数组: ";
    std::for_each(nums.begin(), nums.end(), [](int n)
                  { std::cout << n << " "; });
    std::cout << std::endl;

    // 5. 使用lambda排序
    std::sort(nums.begin(), nums.end(), [](int a, int b)
              {
                  return a > b; // 降序排列
              });
    std::cout << "降序排序后: ";
    for (int n : nums)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}