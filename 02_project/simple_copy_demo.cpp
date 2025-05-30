#include <iostream>
#include <cstring> // For strlen and strcpy_s

// 一个简单的类，包含一个动态分配的字符数组
class MyString {
public:
	char* data;
	size_t length;

	// 构造函数
	MyString(const char* str = nullptr) : data(nullptr), length(0) {
		if (str) {
			length = strlen(str);
			data = new char[length + 1]; // +1 for null terminator
			// 使用 strcpy_s，提供目标缓冲区大小
			strcpy_s(data, length + 1, str);
		}
		std::cout << "Constructor called for: " << (data ? data : "nullptr") << std::endl;
	}

	// 析构函数
	~MyString() {
		if (data) {
			std::cout << "Destructor called for: " << data << std::endl;
			delete[] data; // Release dynamically allocated memory
			data = nullptr;
		}
	}

	// --- 浅拷贝的例子 (C++ 默认行为) ---
	// 如果不定义拷贝构造函数和拷贝赋值运算符，就会使用默认的浅拷贝

	/*
	// 默认的浅拷贝构造函数 (注释掉，以便演示深拷贝)
	MyString(const MyString& other) : data(other.data), length(other.length) {
		 std::cout << "Shallow Copy Constructor called for: " << (data ? data : "nullptr") << std::endl;
	}

	// 默认的浅拷贝赋值运算符 (注释掉，以便演示深拷贝)
	MyString& operator=(const MyString& other) {
		if (this != &other) { // Protect against self-assignment
			// Note: In default shallow copy, you might not deallocate 'this->data' here,
			// which can lead to memory leaks if 'this->data' was pointing to something.
			// The main issue with shallow copy is the shared pointer itself.
			data = other.data;
			length = other.length;
		}
		std::cout << "Shallow Assignment Operator called for: " << (data ? data : "nullptr") << std::endl;
		return *this;
	}
	*/

	// --- 深拷贝的实现 ---

	// 拷贝构造函数 (实现深拷贝)
	MyString(const MyString& other) : data(nullptr), length(other.length) {
		if (other.data) {
			data = new char[length + 1];
			// 使用 strcpy_s，提供目标缓冲区大小
			strcpy_s(data, length + 1, other.data);
		}
		std::cout << "Deep Copy Constructor called for: " << (data ? data : "nullptr") << std::endl;
	}

	// 拷贝赋值运算符 (实现深拷贝)
	MyString& operator=(const MyString& other) {
		if (this != &other) { // Protect against self-assignment
			// 1. Release old memory
			if (data) {
				delete[] data;
				data = nullptr; // Good practice to set to nullptr after deleting
			}

			// 2. Copy data from other
			length = other.length;
			if (other.data) {
				data = new char[length + 1];
				// 使用 strcpy_s，提供目标缓冲区大小
				strcpy_s(data, length + 1, other.data);
			}
			else {
				data = nullptr; // Handle case where other.data is nullptr
			}
		}
		std::cout << "Deep Assignment Operator called for: " << (data ? data : "nullptr") << std::endl;
		return *this;
	}

	// 访问数据的方法
	const char* getData() const {
		return data;
	}
};

int main() {
	// 原始对象
	MyString s1("Hello");

	// 示例 1: 拷贝构造函数 (默认是浅拷贝，这里是我们实现的深拷贝)
	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	MyString s2 = s1; // 调用拷贝构造函数
	std::cout << "s1 data: " << s1.getData() << ", s2 data: " << s2.getData() << std::endl;
	// 修改 s1 的数据 (如果 MyString 允许修改的话, 这里只是为了概念说明)
	// 注意: 实际中如果需要修改, data 应该不是 const char*
	// 如果是深拷贝, s1 和 s2 指向不同的内存, 修改一个不会影响另一个

	// 示例 2: 拷贝赋值运算符 (默认是浅拷贝，这里是我们实现的深拷贝)
	std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
	MyString s3("World");
	std::cout << "Before assignment, s3 data: " << s3.getData() << std::endl;
	s3 = s1; // 调用拷贝赋值运算符
	std::cout << "After assignment, s1 data: " << s1.getData() << ", s3 data: " << s3.getData() << std::endl;

	// 程序结束时，s1, s2, s3 会按创建顺序的逆序调用析构函数
	// 如果是浅拷贝，当 s1 析构释放内存后，s2 和 s3 的 data 指针将无效 (悬空指针)
	// 如果是深拷贝，每个对象的 data 指针指向独立的内存，析构互不影响

	std::cout << "\n--- End of main ---" << std::endl;

	return 0;
}
