#include <iostream>
#include <vector>

int main()
{
    // 创建一个int类型的vector
    std::vector<int> v;

    // 添加元素
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 输出所有元素
    std::cout << "vector中的元素: ";
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // 删除最后一个元素
    v.pop_back();

    // 使用范围for循环遍历
    std::cout << "删除最后一个元素后: ";
    for (int num : v)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 判断vector是否为空
    if (v.empty())
    {
        std::cout << "vector是空的" << std::endl;
    }
    else
    {
        std::cout << "vector不是空的，当前大小: " << v.size() << std::endl;
    }

    // 清空vector
    v.clear();
    std::cout << "清空后，vector大小: " << v.size() << std::endl;

    return 0;
}