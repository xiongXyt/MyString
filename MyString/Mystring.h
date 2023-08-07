#ifndef MYSTRING_H_
#define MYSTRING_H_
#include<iostream>
#include "include/XYTString.h"
#pragma comment(lib,"./lib/XYTString.lib")
using namespace std;

#define CLENGTH 10
#define STRDELETE(p) {if (p!=nullptr) {delete p; p = nullptr;}}
#define STRCLEAR(p) {if (p!=nullptr) {delete[]p; p = nullptr;}}

class MyString {

public:
	MyString();
	~MyString();

	/* ************************************************************ */
	// ���졾 count ������ char cchar ���ַ����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(char cchar, size_t count = 1);

	// ���졾 count ������ short scount ���ַ����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(short scount, size_t count = 1);

	// ���졾 count ������ int icount ���ַ����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(int icount, size_t count = 1);

	// ���졾 count ������ bool bcount ���ַ����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(bool bcount, size_t count = 1);

	// ���졾 count ������ float fcount ���ַ����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(float fcount, size_t count = 1);

	// ���졾 count ������ double dcount ���ַ����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(double dcount, size_t count = 1);

	// ���졾 count ������ char*  pstr ����ָ����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(char const* const pstr, size_t count = 1);

	// ���졾 count ������ fpstr ������ epstr ��֮����ַ������� count ��Ĭ��Ϊ�� 1 ����
	MyString(char const* const fpstr, char const* const epstr, size_t count = 1);

	/* ************************************************************ */
	// ������һ���� Mystring ���Ķ������ù��졣
	MyString(MyString const& other);

	// ������һ���� MyString ���Ķ���ָ�빹�졣
	MyString(MyString const* const pother);

	/* ************************************************************ */
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� char �����͵��ַ���
	MyString& operator+(char cchar);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� short ����ɵ��ַ�����
	MyString& operator+(short scount);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� int ����ɵ��ַ�����
	MyString& operator+(int icount);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� bool ����ɵ��ַ�����
	MyString& operator+(bool bcount);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� float ����ɵ��ַ�����
	MyString& operator+(float fcount);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� double ����ɵ��ַ�����
	MyString& operator+(double dcount);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ����char* pstr ��ָ����ַ�����
	MyString& operator+(char const* const pstr);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� MyString& �����õ��ַ�����
	MyString& operator+(MyString const& other);
	 
	// ���ض�����ַ��������ã��ӷ��������β�����һ���� MyString* ��ָ����ַ�����
	MyString& operator+(MyString const* const pother);

	/* ************************************************************ */
	// ���ض�����ַ��������ã��ӵ����������β�����һ���� char �����͵��ַ���
	MyString& operator+=(char cchar);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� short �����͵��ַ���
	MyString& operator+=(short scount);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� int �����͵��ַ���
	MyString& operator+=(int icount);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� bool �����͵��ַ���
	MyString& operator+=(bool bcount);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� float �����͵��ַ���
	MyString& operator+=(float fcount);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� double �����͵��ַ���
	MyString& operator+=(double dcount);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� char* pstr ��ָ����ַ�����
	MyString& operator+=(char const* const pstr);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� MyString& �����õ��ַ���
	MyString& operator+=(MyString const& other);

	// ���ض�����ַ��������ã��ӵ����������β�����һ���� MyString ��ָ����ַ�����
	MyString& operator+=(MyString const* const pother);

	/* ************************************************************ */
	// ���ض�����ַ��������ã��˷����㷨�ַ������ԭ���ġ� short scount �����ַ���ƴ�ӡ�
	MyString& operator*(short scount);

	// ���ض�����ַ��������ã��˷����㷨�ַ������ԭ���ġ� int icount �����ַ���ƴ�ӡ�
	MyString& operator*(int icount);

	// ���ض�����ַ��������ã��˵������㷨�ַ������ԭ���ġ� short scount �����ַ���ƴ�ӡ�
	MyString& operator*=(short scount);

	// ���ض�����ַ��������ã��˵������㷨�ַ������ԭ���ġ� int icount �����ַ���ƴ�ӡ�
	MyString& operator*=(int icount);

	/* ************************************************************ */
	// ���ض�����ַ��������ã����ڡ� char cchar ���ַ���
	MyString& operator=(char cchar);

	// ���ض�����ַ��������ã����ڡ� short scount ����ɵ��ַ�����
	MyString& operator=(short scount);

	// ���ض�����ַ��������ã����ڡ� int icount ����ɵ��ַ�����
	MyString& operator=(int icount);

	// ���ض�����ַ��������ã����ڡ� bool ccount ����ɵ��ַ�����
	MyString& operator=(bool bcount);

	// ���ض�����ַ��������ã����ڡ� float fcount ����ɵ��ַ�����
	MyString& operator=(float fcount);

	// ���ض�����ַ��������ã����ڡ� double dcount ����ɵ��ַ�����
	MyString& operator=(double dcount);

	// ���ض�����ַ��������ã����ڡ� char* pstr ��ָ����ַ�����
	MyString& operator=(char const* const pstr);

	// ���ض�����ַ��������ã����ڡ� MyString& �����õ��ַ�����
	MyString& operator=(MyString const& other);

	// ���ض�����ַ��������ã����ڡ� MyString* ��ָ����ַ�����
	MyString& operator=(MyString const* const pother);

	/* ************************************************************ */
	// ���ء� char const ������ [] �����ء�
	char const operator[](size_t index);

	// ���ء� char const ������ [] �����ء�
	char const operator[](size_t index)const;

	/* ************************************************************ */
	// ���ز���ֵ���� >  �� �Ƚ������� MyString ������Ĵ�С��
	friend bool operator>(MyString const& str, MyString const& other);

	// ���ز���ֵ���� <  �� �Ƚ������� MyString ������Ĵ�С��
	friend bool operator<(MyString const& str, MyString const& other);

	// ���ز���ֵ���� >= �� �Ƚ������� MyString ������Ĵ�С�����������жϡ�
	friend bool operator>=(MyString const& str, MyString const& other);

	// ���ز���ֵ���� <= �� �Ƚ������� MyString ������Ĵ�С�����������жϡ�
	friend bool operator<=(MyString const& str, MyString const& other);

	// ���ز���ֵ���� == �� �Ƚ������� MyString ���Ƿ���ȡ�
	friend bool operator==(MyString const& str, MyString const& other);

	// ���ز���ֵ���� != �� �Ƚ������� MyString ���Ƿ񲻵��ڡ�
	friend bool operator!=(MyString const& str, MyString const& other);

protected:
	/* ************************************************************ */
	// ��ʼ����
	void Init();
	
	// �����ַ�����
	void ClearStr();

	// ���ݡ�
	void AddCapacity();

public:
	/* ************************************************************ */
	// �����ַ����ȡ�
	int StrLen()const;

	// ���ء� str �����ַ����ȡ�
	int StrLen(char const* const str)const;

	// ���ء� other ��������ַ������ȡ�
	int StrLen(MyString const& other);

	/* ************************************************************ */
	// ���ض�����ַ��������ã�β��������õ��ַ�����
	MyString& Append(char const& const str);

	// ���ض�����ַ��������ã�β�����ָ��ָ����ַ�����
	MyString& Append(char const* const str);

	// ���ض�����ַ��������ã�β������������ַ�������ַ���
	MyString& Append(MyString const& other);

	// ���ض�����ַ��������ã���ӡ� str ����ָ��λ�á� index ��������Ϊ�� len ����������������顣
	MyString& Append(char* str, size_t index, size_t len);

	// ���ض�����ַ��������ã���ӡ� other �����ַ���ָ������Ϊ�� len ����
	MyString& Append(MyString const& other, size_t len);

	// ���ض�����ַ��������ã���ӡ� other ����ָ��λ�á� index ��������Ϊ�� len ����
	MyString& Append(MyString const& other, size_t index, size_t len);

	// ���ض�����ַ��������ã���ӡ� count ������ char ch ���ַ���
	MyString& Append(char ch, size_t count);

	/* ************************************************************ */
	// ���ض�����ַ��������ã�����ַ���֮����ӡ� str �����õ��ַ�����
	MyString& Aassign(char const& const str);

	// ���ض�����ַ��������ã�����ַ���֮����ӡ� str ��ָ����ַ�����
	MyString& Aassign(char const* const str);

	// ���ض�����ַ��������ã�����ַ���֮������ַ������� other �����ַ�����
	MyString& Aassign(MyString const& other);

	// ���ض�����ַ��������ã�����ַ���֮����ӡ� str ��ָ����ַ�����ָ��λ��Ϊ�� index ��������Ϊ�� len ����
	MyString& Aassign(char const* str, size_t index, size_t len);

	// ���ض�����ַ��������ã�����ַ���֮����Ӷ��� other �����ַ���������Ϊ�� len ����
	MyString& Aassign(MyString const& other, size_t len);

	// ���ض�����ַ��������ã�����ַ���֮����Ӷ��� other �����ַ�����ָ��λ��Ϊ�� index ��������Ϊ�� len ����
	MyString& Aassign(MyString const& other, size_t index, size_t len);

	// ���ض�����ַ��������ã�����ַ���֮����ӡ� count ������ ch ���ַ���
	MyString& Aassign(char ch, size_t count);

	/* ************************************************************ */
	// ����һ���� char �����ã�ָ���ڡ� index ��λ�õ��ַ�. ����� index �������ַ�����Χ�ڡ�
	char& At(size_t index);

	// �롾 other ���Ƚϵ��ַ�����С��
	// ����Ϊ�� 10 ����ʾ���ڡ� other ����
	// ����Ϊ�� -10 ����ʾС�ڡ� other ����
	// ����Ϊ�� 10 ����ʾ���ڡ� other ����
	int Compare(MyString const& other);

	// �롾 char* str ��ָ����ַ����Ƚϵ��ַ�����С��
	// ����Ϊ�� 10 ����ʾ���ڡ� str ����
	// ����Ϊ�� -10 ����ʾС�ڡ� str ����
	// ����Ϊ�� 10 ����ʾ���ڡ� str ����
	int Compare(char const* str);

	// ָ��λ�á� index ���ͳ��ȡ� len ���롾 other ��ָ��λ�á� index2 ���ͳ��ȡ� len2 �����Ƚϵ��ַ�����С��
	// Ĭ��ֵ���� index2 ����0 ���� len2 ����0 ��
	// ����Ϊ�� 10 ����ʾ���ڡ� other ����
	// ����Ϊ�� -10 ����ʾС�ڡ� other ����
	// ����Ϊ�� 10 ����ʾ���ڡ� other ����
	int Compare(size_t index, size_t len, MyString const& other, 
		size_t index2 = 0, size_t len2 = 0);

	// ָ��λ�á� index ���ͳ��ȡ� len ���롾 char const* str ��ָ��λ�á� index2 ���ͳ��ȡ� len2 �����Ƚϵ��ַ�����С��
	// Ĭ��ֵ���� index2 ����0 ���� len2 ����0 ��
	// ����Ϊ�� 10 ����ʾ���ڡ� str ����
	// ����Ϊ�� -10 ����ʾС�ڡ� str ����
	// ����Ϊ�� 10 ����ʾ���ڡ� str ����
	int Compare(size_t index, size_t len, char const* str, size_t index2 = 0, size_t len2 = 0);

	/* ************************************************************ */
	// ���ơ� str �����ԡ� index ����ʼ���� count �����ַ���
	// Ĭ��ֵ���� count ����1 ���� index ����0 ��
	size_t Copy(char* const str, size_t count = 1, size_t index = 0);

	// ���ز���ֵ���ַ����п�
	bool Empty()const;

	// �����ַ�����������ã�ɾ���� index ����ʼ���� count �����ַ���
	// Ĭ��ֵ����index����0 ���� count ����0 ��
	MyString& Erase(size_t index = 0, size_t count = 0);

	/* ************************************************************ */
	// ���ء� other ���ַ�����һ�γ�����λ�ã��ӡ� index ����ʼ���ҡ�
	// Ĭ��ֵ����index����0 ��
	int Find(MyString const& other, size_t index = 0);

	// ���ء� str ��ָ����ַ�����һ�γ�����λ�ã��ӡ� index ����ʼ���ҡ�
	// Ĭ��ֵ����index����0 ��
	int Find(char const* str, size_t index = 0);

	// ���ء� str �����õ��ַ�����һ�γ�����λ�ã��ӡ� index ����ʼ���ң�����Ϊ�� len ����
	// Ĭ��ֵ����index����0 ��
	int Find(char const* str, size_t index, size_t len);

	// ���ء� ch ���ַ���һ�γ�����λ�ã��ӡ� index ����ʼ���ҡ�
	// Ĭ��ֵ���� index ����0 ��
	int Find(char ch, size_t index = 0);

	/* ************************************************************ */
	// �������һ���롾 other ���е�ĳ���ַ�ƥ����ַ�λ�ã��ӡ� index ����ʼ���ҡ�
	// Ĭ��ֵ���� index ����0 ��
	size_t RFind(MyString const& other, size_t index = 0);

	// �������һ���롾 str ��ָ���ĳ���ַ�ƥ����ַ�λ�ã��ӡ� index ����ʼ���ҡ�
	// Ĭ��ֵ���� index ����0 ��
	size_t RFind(char const* str, size_t index = 0);

	// �������һ���롾 str �����õ�ĳ���ַ�ƥ����ַ�λ�ã��ӡ� index ����ʼ���ң�����Ϊ�� len ����
	size_t RFind(char const* str, size_t index, size_t len);

	// �������һ���롾 ch ���ַ�ƥ����ַ�λ�ã��ӡ� index ����ʼ���ҡ�
	size_t RFind(char ch, size_t index);

	/* ************************************************************ */
	// �����ַ�ƥ���λ�ã��������ַ����е�һ�����ַ������� other ���е�ĳ���ַ�ƥ����ַ���ָ���ӡ� index ����ʼ��
	// Ĭ��ֵ���� index ����0 ��
	size_t FindFirst(MyString const& other, size_t index = 0);

	// �����ַ�ƥ���λ�ã��������ַ����е�һ���롾 str ��ָ����ַ���ƥ����ַ���ָ���ӡ� index ����ʼ��
	// Ĭ��ֵ���� index ����0 ��
	size_t FindFirst(char const* str, size_t index = 0);

	// �����ַ�ƥ���λ�ã��������ַ����е�һ���롾 str ��ָ����ַ���ƥ����ַ���
	// ָ���ӡ� index ����ʼ������Ϊlen��
	size_t FindFirst(char const* str, size_t index, size_t len);

	// �����ַ�ƥ���λ�ã��������ַ����е�һ�����ַ��� ch ��ƥ����ַ���ָ���ӡ� index ����ʼ��
	// Ĭ��ֵ���� index ����0 ��
	size_t FindFirst(char ch, size_t index = 0);

	/* ************************************************************ */
	// �����ַ�ƥ���λ�ã��������ַ��������һ���롾 str ��ָ����ַ���ƥ����ַ���ָ���ӡ� index ����ʼ��
	// Ĭ��ֵ���� index ����0 ��
	size_t FindFirstNot(MyString const& other, size_t index = 0);

	// �����ַ�ƥ���λ�ã��������ַ��������һ���롾 str ��ָ����ַ���ƥ����ַ���ָ���ӡ� index ����ʼ��
	// Ĭ��ֵ���� index ����0 ��
	size_t FindFirstNot(char const* str, size_t index = 0);

	// �����ַ�ƥ���λ�ã��������ַ��������һ���롾 str ��ָ����ַ���ƥ����ַ���ָ���ӡ� index ����ʼ��
	// Ĭ��ֵ���� index ����0 ��
	size_t FindFirstNot(char const* str, size_t index, size_t len);

	// �����ַ�ƥ���λ�ã��������ַ��������һ���롾 str ��ָ����ַ���ƥ����ַ���ָ���ӡ� index ����ʼ��
	// Ĭ��ֵ���� index ����0 ��
	size_t FindFirstNot(char ch, size_t index = 0);

	/* ************************************************************ */
	size_t FindLast(MyString const& other, size_t index = 0);
	size_t FindLast(char const* str, size_t index = 0);
	size_t FindLast(char const* str, size_t index, size_t len);
	size_t FindLast(char ch, size_t index = 0);

	/* ************************************************************ */
	size_t FindLastNot(MyString const& other, size_t index = 0);
	size_t FindLastNot(char const* str, size_t index = 0);
	size_t FindLastNot(char const* str, size_t index, size_t len);
	size_t FindLastNot(char ch, size_t index = 0);

	/* ************************************************************ */
	MyString& Insert(size_t index, MyString const& other);
	MyString& Insert(size_t index, char const* str);
	MyString& Insert(size_t index1, MyString const& other, size_t index2, size_t count);
	MyString& Insert(size_t index, char const* str, size_t count);
	MyString& Insert(size_t index, size_t count, char ch);

	/* ************************************************************ */
	MyString& Replace(size_t index, size_t count, MyString const& other);
	MyString& Replace(size_t index1, size_t count1, MyString const& other, size_t index2, size_t count2);
	MyString& Replace(size_t index, size_t count, char const* str);
	MyString& Replace(size_t index, size_t count1, char const* str, size_t count2);
	MyString& Replace(size_t index, size_t count1, size_t count2, char ch);

	/* ************************************************************ */
	void Resize(size_t count);
	void Resize(size_t count, char ch);

	MyString Substr(size_t index, size_t count = 0);

	void Swap(MyString& other);

	/* ************************************************************ */
	char const* const GetString();
	size_t GetStrLen();
	size_t GetStrCap();
	size_t GetMaxStr();

protected:
	/* ************************************************************ */
	char* m_pstr;
	unsigned int m_strLen;
	unsigned int m_capacity;
};

void XYT_TestString();
	
#endif // !MYSTRING_H_

