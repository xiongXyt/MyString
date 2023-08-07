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
	// 构造【 count 】个【 char cchar 】字符的字符串，【 count 】默认为【 1 】。
	MyString(char cchar, size_t count = 1);

	// 构造【 count 】个【 short scount 】字符的字符串，【 count 】默认为【 1 】。
	MyString(short scount, size_t count = 1);

	// 构造【 count 】个【 int icount 】字符的字符串，【 count 】默认为【 1 】。
	MyString(int icount, size_t count = 1);

	// 构造【 count 】个【 bool bcount 】字符的字符串，【 count 】默认为【 1 】。
	MyString(bool bcount, size_t count = 1);

	// 构造【 count 】个【 float fcount 】字符的字符串，【 count 】默认为【 1 】。
	MyString(float fcount, size_t count = 1);

	// 构造【 count 】个【 double dcount 】字符的字符串，【 count 】默认为【 1 】。
	MyString(double dcount, size_t count = 1);

	// 构造【 count 】个【 char*  pstr 】所指向的字符串，【 count 】默认为【 1 】。
	MyString(char const* const pstr, size_t count = 1);

	// 构造【 count 】个【 fpstr 】到【 epstr 】之间的字符串，【 count 】默认为【 1 】。
	MyString(char const* const fpstr, char const* const epstr, size_t count = 1);

	/* ************************************************************ */
	// 用另外一个【 Mystring 】的对象引用构造。
	MyString(MyString const& other);

	// 用另外一个【 MyString 】的对象指针构造。
	MyString(MyString const* const pother);

	/* ************************************************************ */
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 char 】类型的字符。
	MyString& operator+(char cchar);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 short 】组成的字符串。
	MyString& operator+(short scount);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 int 】组成的字符串。
	MyString& operator+(int icount);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 bool 】组成的字符串。
	MyString& operator+(bool bcount);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 float 】组成的字符串。
	MyString& operator+(float fcount);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 double 】组成的字符串。
	MyString& operator+(double dcount);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【char* pstr 】指向的字符串。
	MyString& operator+(char const* const pstr);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 MyString& 】引用的字符串。
	MyString& operator+(MyString const& other);
	 
	// 返回对象的字符串的引用，加法运算符在尾部添加一个【 MyString* 】指向的字符串。
	MyString& operator+(MyString const* const pother);

	/* ************************************************************ */
	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 char 】类型的字符。
	MyString& operator+=(char cchar);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 short 】类型的字符。
	MyString& operator+=(short scount);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 int 】类型的字符。
	MyString& operator+=(int icount);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 bool 】类型的字符。
	MyString& operator+=(bool bcount);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 float 】类型的字符。
	MyString& operator+=(float fcount);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 double 】类型的字符。
	MyString& operator+=(double dcount);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 char* pstr 】指向的字符串。
	MyString& operator+=(char const* const pstr);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 MyString& 】引用的字符。
	MyString& operator+=(MyString const& other);

	// 返回对象的字符串的引用，加等于运算符在尾部添加一个【 MyString 】指向的字符串。
	MyString& operator+=(MyString const* const pother);

	/* ************************************************************ */
	// 返回对象的字符串的引用，乘法运算法字符串变成原来的【 short scount 】个字符串拼接。
	MyString& operator*(short scount);

	// 返回对象的字符串的引用，乘法运算法字符串变成原来的【 int icount 】个字符串拼接。
	MyString& operator*(int icount);

	// 返回对象的字符串的引用，乘等于运算法字符串变成原来的【 short scount 】个字符串拼接。
	MyString& operator*=(short scount);

	// 返回对象的字符串的引用，乘等于运算法字符串变成原来的【 int icount 】个字符串拼接。
	MyString& operator*=(int icount);

	/* ************************************************************ */
	// 返回对象的字符串的引用，等于【 char cchar 】字符。
	MyString& operator=(char cchar);

	// 返回对象的字符串的引用，等于【 short scount 】组成的字符串。
	MyString& operator=(short scount);

	// 返回对象的字符串的引用，等于【 int icount 】组成的字符串。
	MyString& operator=(int icount);

	// 返回对象的字符串的引用，等于【 bool ccount 】组成的字符串。
	MyString& operator=(bool bcount);

	// 返回对象的字符串的引用，等于【 float fcount 】组成的字符串。
	MyString& operator=(float fcount);

	// 返回对象的字符串的引用，等于【 double dcount 】组成的字符串。
	MyString& operator=(double dcount);

	// 返回对象的字符串的引用，等于【 char* pstr 】指向的字符串。
	MyString& operator=(char const* const pstr);

	// 返回对象的字符串的引用，等于【 MyString& 】引用的字符串。
	MyString& operator=(MyString const& other);

	// 返回对象的字符串的引用，等于【 MyString* 】指向的字符串。
	MyString& operator=(MyString const* const pother);

	/* ************************************************************ */
	// 返回【 char const 】，【 [] 】重载。
	char const operator[](size_t index);

	// 返回【 char const 】，【 [] 】重载。
	char const operator[](size_t index)const;

	/* ************************************************************ */
	// 返回布尔值，【 >  】 比较两个【 MyString 】对象的大小。
	friend bool operator>(MyString const& str, MyString const& other);

	// 返回布尔值，【 <  】 比较两个【 MyString 】对象的大小。
	friend bool operator<(MyString const& str, MyString const& other);

	// 返回布尔值，【 >= 】 比较两个【 MyString 】对象的大小，包括等于判断。
	friend bool operator>=(MyString const& str, MyString const& other);

	// 返回布尔值，【 <= 】 比较两个【 MyString 】对象的大小，包括等于判断。
	friend bool operator<=(MyString const& str, MyString const& other);

	// 返回布尔值，【 == 】 比较两个【 MyString 】是否相等。
	friend bool operator==(MyString const& str, MyString const& other);

	// 返回布尔值，【 != 】 比较两个【 MyString 】是否不等于。
	friend bool operator!=(MyString const& str, MyString const& other);

protected:
	/* ************************************************************ */
	// 初始化。
	void Init();
	
	// 清理字符串。
	void ClearStr();

	// 扩容。
	void AddCapacity();

public:
	/* ************************************************************ */
	// 返回字符长度。
	int StrLen()const;

	// 返回【 str 】的字符长度。
	int StrLen(char const* const str)const;

	// 返回【 other 】对象的字符串长度。
	int StrLen(MyString const& other);

	/* ************************************************************ */
	// 返回对象的字符串的引用，尾部添加引用的字符串。
	MyString& Append(char const& const str);

	// 返回对象的字符串的引用，尾部添加指针指向的字符串。
	MyString& Append(char const* const str);

	// 返回对象的字符串的引用，尾部添加其他的字符串类的字符。
	MyString& Append(MyString const& other);

	// 返回对象的字符串的引用，添加【 str 】的指定位置【 index 】，长度为【 len 】，这里有索引检查。
	MyString& Append(char* str, size_t index, size_t len);

	// 返回对象的字符串的引用，添加【 other 】的字符，指定长度为【 len 】。
	MyString& Append(MyString const& other, size_t len);

	// 返回对象的字符串的引用，添加【 other 】的指定位置【 index 】，长度为【 len 】。
	MyString& Append(MyString const& other, size_t index, size_t len);

	// 返回对象的字符串的引用，添加【 count 】个【 char ch 】字符。
	MyString& Append(char ch, size_t count);

	/* ************************************************************ */
	// 返回对象的字符串的引用，清空字符串之后添加【 str 】引用的字符串。
	MyString& Aassign(char const& const str);

	// 返回对象的字符串的引用，清空字符串之后添加【 str 】指向的字符串。
	MyString& Aassign(char const* const str);

	// 返回对象的字符串的引用，清空字符串之后添加字符串对象【 other 】的字符串。
	MyString& Aassign(MyString const& other);

	// 返回对象的字符串的引用，清空字符串之后添加【 str 】指向的字符串，指定位置为【 index 】，长度为【 len 】。
	MyString& Aassign(char const* str, size_t index, size_t len);

	// 返回对象的字符串的引用，清空字符串之后添加对象【 other 】的字符串，长度为【 len 】。
	MyString& Aassign(MyString const& other, size_t len);

	// 返回对象的字符串的引用，清空字符串之后添加对象【 other 】的字符串，指定位置为【 index 】，长度为【 len 】。
	MyString& Aassign(MyString const& other, size_t index, size_t len);

	// 返回对象的字符串的引用，清空字符串之后添加【 count 】个【 ch 】字符。
	MyString& Aassign(char ch, size_t count);

	/* ************************************************************ */
	// 返回一个【 char 】引用，指向在【 index 】位置的字符. 如果【 index 】不在字符串范围内。
	char& At(size_t index);

	// 与【 other 】比较的字符串大小：
	// 返回为【 10 】表示大于【 other 】，
	// 返回为【 -10 】表示小于【 other 】，
	// 返回为【 10 】表示等于【 other 】。
	int Compare(MyString const& other);

	// 与【 char* str 】指向的字符串比较的字符串大小：
	// 返回为【 10 】表示大于【 str 】，
	// 返回为【 -10 】表示小于【 str 】，
	// 返回为【 10 】表示等于【 str 】。
	int Compare(char const* str);

	// 指定位置【 index 】和长度【 len 】与【 other 】指定位置【 index2 】和长度【 len2 】，比较的字符串大小：
	// 默认值：【 index2 】：0 ，【 len2 】：0 。
	// 返回为【 10 】表示大于【 other 】，
	// 返回为【 -10 】表示小于【 other 】，
	// 返回为【 10 】表示等于【 other 】。
	int Compare(size_t index, size_t len, MyString const& other, 
		size_t index2 = 0, size_t len2 = 0);

	// 指定位置【 index 】和长度【 len 】与【 char const* str 】指定位置【 index2 】和长度【 len2 】，比较的字符串大小：
	// 默认值：【 index2 】：0 ，【 len2 】：0 。
	// 返回为【 10 】表示大于【 str 】，
	// 返回为【 -10 】表示小于【 str 】，
	// 返回为【 10 】表示等于【 str 】。
	int Compare(size_t index, size_t len, char const* str, size_t index2 = 0, size_t len2 = 0);

	/* ************************************************************ */
	// 复制【 str 】的自【 index 】开始，【 count 】个字符。
	// 默认值：【 count 】：1 ，【 index 】：0 。
	size_t Copy(char* const str, size_t count = 1, size_t index = 0);

	// 返回布尔值，字符串判空
	bool Empty()const;

	// 返回字符串对象的引用，删除【 index 】开始，【 count 】个字符。
	// 默认值：【index】：0 ，【 count 】：0 。
	MyString& Erase(size_t index = 0, size_t count = 0);

	/* ************************************************************ */
	// 返回【 other 】字符串第一次出来的位置，从【 index 】开始查找。
	// 默认值：【index】：0 。
	int Find(MyString const& other, size_t index = 0);

	// 返回【 str 】指向的字符串第一次出来的位置，从【 index 】开始查找。
	// 默认值：【index】：0 。
	int Find(char const* str, size_t index = 0);

	// 返回【 str 】引用的字符串第一次出来的位置，从【 index 】开始查找，长度为【 len 】。
	// 默认值：【index】：0 。
	int Find(char const* str, size_t index, size_t len);

	// 返回【 ch 】字符第一次出来的位置，从【 index 】开始查找。
	// 默认值：【 index 】：0 。
	int Find(char ch, size_t index = 0);

	/* ************************************************************ */
	// 返回最后一个与【 other 】中的某个字符匹配的字符位置，从【 index 】开始查找。
	// 默认值：【 index 】：0 。
	size_t RFind(MyString const& other, size_t index = 0);

	// 返回最后一个与【 str 】指向的某个字符匹配的字符位置，从【 index 】开始查找。
	// 默认值：【 index 】：0 。
	size_t RFind(char const* str, size_t index = 0);

	// 返回最后一个与【 str 】引用的某个字符匹配的字符位置，从【 index 】开始查找，长度为【 len 】。
	size_t RFind(char const* str, size_t index, size_t len);

	// 返回最后一个与【 ch 】字符匹配的字符位置，从【 index 】开始查找。
	size_t RFind(char ch, size_t index);

	/* ************************************************************ */
	// 返回字符匹配的位置，查找在字符串中第一个与字符串对象【 other 】中的某个字符匹配的字符，指定从【 index 】开始。
	// 默认值：【 index 】：0 。
	size_t FindFirst(MyString const& other, size_t index = 0);

	// 返回字符匹配的位置，查找在字符串中第一个与【 str 】指向的字符串匹配的字符，指定从【 index 】开始。
	// 默认值：【 index 】：0 。
	size_t FindFirst(char const* str, size_t index = 0);

	// 返回字符匹配的位置，查找在字符串中第一个与【 str 】指向的字符串匹配的字符，
	// 指定从【 index 】开始，长度为len。
	size_t FindFirst(char const* str, size_t index, size_t len);

	// 返回字符匹配的位置，查找在字符串中第一个与字符【 ch 】匹配的字符，指定从【 index 】开始。
	// 默认值：【 index 】：0 。
	size_t FindFirst(char ch, size_t index = 0);

	/* ************************************************************ */
	// 返回字符匹配的位置，查找在字符串中最后一个与【 str 】指向的字符串匹配的字符，指定从【 index 】开始。
	// 默认值：【 index 】：0 。
	size_t FindFirstNot(MyString const& other, size_t index = 0);

	// 返回字符匹配的位置，查找在字符串中最后一个与【 str 】指向的字符串匹配的字符，指定从【 index 】开始。
	// 默认值：【 index 】：0 。
	size_t FindFirstNot(char const* str, size_t index = 0);

	// 返回字符匹配的位置，查找在字符串中最后一个与【 str 】指向的字符串匹配的字符，指定从【 index 】开始。
	// 默认值：【 index 】：0 。
	size_t FindFirstNot(char const* str, size_t index, size_t len);

	// 返回字符匹配的位置，查找在字符串中最后一个与【 str 】指向的字符串匹配的字符，指定从【 index 】开始。
	// 默认值：【 index 】：0 。
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

