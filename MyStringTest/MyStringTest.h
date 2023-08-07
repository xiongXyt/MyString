#ifndef MYSTRINGTEST_H_
#define MYSTRINGTEST_H_

class MyStringTest {
private:
	char* m_Data;
	int m_DataLen;

public:
	// ��ͨ���캯��
	MyStringTest(char const* str = nullptr);

	// �������캯��
	MyStringTest(MyStringTest const* other);

	// ��������
	~MyStringTest();

	// ��ֵ����
	MyStringTest& operator=(MyStringTest const& other);

	char* const GetStr() {
		return m_Data;
	}

	int GetStrLen() {
		return m_DataLen;
	}
};

#endif // !MYSTRINGTEST_H_
