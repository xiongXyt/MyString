#ifndef MYSTRINGTEST_H_
#define MYSTRINGTEST_H_

class MyStringTest {
private:
	char* m_Data;
	int m_DataLen;

public:
	// 普通构造函数
	MyStringTest(char const* str = nullptr);

	// 拷贝构造函数
	MyStringTest(MyStringTest const* other);

	// 析构函数
	~MyStringTest();

	// 赋值函数
	MyStringTest& operator=(MyStringTest const& other);

	char* const GetStr() {
		return m_Data;
	}

	int GetStrLen() {
		return m_DataLen;
	}
};

#endif // !MYSTRINGTEST_H_
