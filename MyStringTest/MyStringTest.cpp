#include "MyStringTest.h"

MyStringTest::MyStringTest(char const* str) {
	if (nullptr == str) {
		m_Data = nullptr;
		m_DataLen = 0;
	}
	else {
		size_t indexlen = 0;
		while ('\0'!=str[indexlen]) {
			++indexlen;
		}
		m_Data = new char[indexlen + 1];	// 长度不包含【 '\0' 】

		size_t index = 0;
		while (m_Data[index]=str[index]) {
			++index;
		}
		m_DataLen = indexlen;
	}
}

MyStringTest::MyStringTest(MyStringTest const* other) {
	// 构造函数里面不用判断【 m_Data 】。
	if (nullptr!=other->m_Data) {
		m_Data = new char[other->m_DataLen + 1];	// 长度不包含【 '\0' 】

		size_t index = 0;
		while (m_Data[index]=other->m_Data[index]) {
			++index;
		}
		m_DataLen = other->m_DataLen;
	}
	else {
		m_Data = nullptr;
		m_DataLen = 0;
	}
}

MyStringTest::~MyStringTest() {
	if (m_Data != nullptr) {
		delete[]m_Data;
		m_Data = nullptr;
		m_DataLen = 0;
	}
}

MyStringTest& MyStringTest::operator=(MyStringTest const& other) {
	if (nullptr != m_Data) {
		delete[]m_Data;
		m_DataLen = 0;
	}
	if (nullptr!=other.m_Data) {
		m_Data = new char[other.m_DataLen + 1];		// 长度不包含【 '\0' 】

		size_t index = 0;
		while (m_Data[index]=other.m_Data[index]) {
			++index;
		}
		m_DataLen = other.m_DataLen;
	}
	else {
		m_Data = nullptr;
		m_DataLen = 0;
	}

	return *(this);
}
