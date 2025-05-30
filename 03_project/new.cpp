#include <iostream>

int main() {
	int size;

	// 提示用户输入数组的大小
	std::cout << "请输入您想要创建的整数数组的大小: ";
	std::cin >> size;

	// 检查输入的大小是否有效
	if (size <= 0) {
		std::cerr << "数组大小必须是正数！" << std::endl;
		return 1; // 退出程序并报错
	}

	// 使用 new 分配一个整数数组的内存
	// int* intArrayPtr = new int[size]; 会在堆上分配 size 个整数的连续内存空间
	// 并返回指向数组第一个元素的指针
	int* intArrayPtr = new int[size];

	// 检查内存分配是否成功
	if (intArrayPtr == nullptr) {
		std::cerr << "内存分配失败！" << std::endl;
		return 1; // 退出程序并报错
	}

	// 使用循环为数组元素赋值
	std::cout << "请为数组的每个元素输入一个整数值:" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << "元素 " << i << ": ";
		std::cin >> intArrayPtr[i]; // 通过指针和索引访问数组元素
	}

	// 使用循环输出数组元素的值
	std::cout << "\n您输入的数组元素如下:" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << "元素 " << i << ": " << intArrayPtr[i] << std::endl; // 通过指针和索引访问数组元素
	}

	// 使用 delete[] 释放动态分配的数组内存
	// 对于用 new[] 分配的内存，必须使用 delete[] 释放
	delete[] intArrayPtr;
	intArrayPtr = nullptr; // 将指针设置为 nullptr，避免成为悬空指针

	std::cout << "\n动态分配的内存已释放。" << std::endl;

	// 程序结束
	return 0;
}