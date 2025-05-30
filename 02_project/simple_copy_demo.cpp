#include <iostream>
#include <cstring> // For strlen and strcpy_s

// һ���򵥵��࣬����һ����̬������ַ�����
class MyString {
public:
	char* data;
	size_t length;

	// ���캯��
	MyString(const char* str = nullptr) : data(nullptr), length(0) {
		if (str) {
			length = strlen(str);
			data = new char[length + 1]; // +1 for null terminator
			// ʹ�� strcpy_s���ṩĿ�껺������С
			strcpy_s(data, length + 1, str);
		}
		std::cout << "Constructor called for: " << (data ? data : "nullptr") << std::endl;
	}

	// ��������
	~MyString() {
		if (data) {
			std::cout << "Destructor called for: " << data << std::endl;
			delete[] data; // Release dynamically allocated memory
			data = nullptr;
		}
	}

	// --- ǳ���������� (C++ Ĭ����Ϊ) ---
	// ��������忽�����캯���Ϳ�����ֵ��������ͻ�ʹ��Ĭ�ϵ�ǳ����

	/*
	// Ĭ�ϵ�ǳ�������캯�� (ע�͵����Ա���ʾ���)
	MyString(const MyString& other) : data(other.data), length(other.length) {
		 std::cout << "Shallow Copy Constructor called for: " << (data ? data : "nullptr") << std::endl;
	}

	// Ĭ�ϵ�ǳ������ֵ����� (ע�͵����Ա���ʾ���)
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

	// --- �����ʵ�� ---

	// �������캯�� (ʵ�����)
	MyString(const MyString& other) : data(nullptr), length(other.length) {
		if (other.data) {
			data = new char[length + 1];
			// ʹ�� strcpy_s���ṩĿ�껺������С
			strcpy_s(data, length + 1, other.data);
		}
		std::cout << "Deep Copy Constructor called for: " << (data ? data : "nullptr") << std::endl;
	}

	// ������ֵ����� (ʵ�����)
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
				// ʹ�� strcpy_s���ṩĿ�껺������С
				strcpy_s(data, length + 1, other.data);
			}
			else {
				data = nullptr; // Handle case where other.data is nullptr
			}
		}
		std::cout << "Deep Assignment Operator called for: " << (data ? data : "nullptr") << std::endl;
		return *this;
	}

	// �������ݵķ���
	const char* getData() const {
		return data;
	}
};

int main() {
	// ԭʼ����
	MyString s1("Hello");

	// ʾ�� 1: �������캯�� (Ĭ����ǳ����������������ʵ�ֵ����)
	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
	MyString s2 = s1; // ���ÿ������캯��
	std::cout << "s1 data: " << s1.getData() << ", s2 data: " << s2.getData() << std::endl;
	// �޸� s1 ������ (��� MyString �����޸ĵĻ�, ����ֻ��Ϊ�˸���˵��)
	// ע��: ʵ���������Ҫ�޸�, data Ӧ�ò��� const char*
	// ��������, s1 �� s2 ָ��ͬ���ڴ�, �޸�һ������Ӱ����һ��

	// ʾ�� 2: ������ֵ����� (Ĭ����ǳ����������������ʵ�ֵ����)
	std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
	MyString s3("World");
	std::cout << "Before assignment, s3 data: " << s3.getData() << std::endl;
	s3 = s1; // ���ÿ�����ֵ�����
	std::cout << "After assignment, s1 data: " << s1.getData() << ", s3 data: " << s3.getData() << std::endl;

	// �������ʱ��s1, s2, s3 �ᰴ����˳������������������
	// �����ǳ�������� s1 �����ͷ��ڴ��s2 �� s3 �� data ָ�뽫��Ч (����ָ��)
	// ����������ÿ������� data ָ��ָ��������ڴ棬��������Ӱ��

	std::cout << "\n--- End of main ---" << std::endl;

	return 0;
}
