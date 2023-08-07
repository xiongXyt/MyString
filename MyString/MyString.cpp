#include"Mystring.h"

MyString::MyString() {
	Init();
}

MyString::~MyString() {
	if (m_pstr != nullptr) {
		STRCLEAR(m_pstr);
		m_strLen = 0;
		m_capacity = 0;
	}
}

MyString::MyString(char cchar, size_t count) {
	Init();

	while (m_capacity <= count) {	// 扩容
		AddCapacity();
	}

	for (size_t i = 0; i < count; ++i) {
		m_pstr[i] = cchar;
	}

	m_pstr[count] = '\0';	// 手动补齐【 '\0' 】
	m_strLen = XYTStrLen(m_pstr);
}

MyString::MyString(short scount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];
		sprintf_s(strTemp, 99, "%d", scount);
		int strlen = XYTStrLen(strTemp);

		while (m_capacity <= (m_strLen + strlen)) {	// 插入前判断扩容，【 '\0' 】
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}
}

MyString::MyString(int icount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];
		sprintf_s(strTemp, 99, "%d", icount);
		int strlen = XYTStrLen(strTemp);

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}
}

MyString::MyString(bool bcount, size_t count) {
	Init();

	if (bcount) {
		char strTemp[5] = "true";
		for (size_t i = 0; i < count; ++i) {
			while (m_capacity <= (m_strLen + 4)) {
				AddCapacity();
			}

			XYTStrCat((m_pstr + m_strLen), strTemp);
			m_strLen = XYTStrLen(m_pstr);
		}
	}
	else {
		char strTemp[6] = "false";
		for (size_t i = 0; i < count; ++i) {
			while (m_capacity <= (m_strLen + 5)) {
				AddCapacity();
			}

			XYTStrCat((m_pstr + m_strLen), strTemp);
			m_strLen = XYTStrLen(m_pstr);
		}
	}
}

MyString::MyString(float fcount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];
		sprintf_s(strTemp, 99, "%.5f", fcount);	// 这里把零也插入了
		int strlen = XYTStrLen(strTemp);

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}
}

MyString::MyString(double dcount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];
		sprintf_s(strTemp, 99, "%.8f", dcount);	// 这里把零也插入了
		int strlen = XYTStrLen(strTemp);

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}

}

MyString::MyString(char const* const pstr, size_t count) {
	Init();

	int strlen = XYTStrLen(pstr);
	while (count > 0) {
		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), pstr);
		m_strLen = XYTStrLen(m_pstr);

		--count;
	}
}

MyString::MyString(char const* const fpstr, char const* const epstr, size_t count) {
	Init();

	int strlen = epstr - fpstr;
	for (size_t i = 0; i < count; ++i) {
		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		XYTStrNCat((m_pstr + m_strLen), fpstr, strlen);
		m_strLen = XYTStrLen(m_pstr);
	}
}

MyString::MyString(MyString const& other) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	while (m_capacity <= (m_strLen + other.m_strLen)) {
		AddCapacity();
	}

	m_pstr = new char[other.m_strLen + 1];
	XYTStrCpy(m_pstr, other.m_pstr);

	m_strLen = XYTStrLen(m_pstr);
}

MyString::MyString(MyString const* const pother) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	while (m_capacity <= (m_strLen + pother->m_strLen)) {
		AddCapacity();
	}

	m_pstr = new char[pother->m_strLen + 1];
	XYTStrCpy(m_pstr, pother->m_pstr);

	m_strLen = XYTStrLen(m_pstr);
}

MyString& MyString::operator+(char cchar) {
	while (m_capacity <= (m_strLen + 1)) {
		AddCapacity();
	}

	m_pstr[m_strLen++] = cchar;
	m_pstr[m_strLen] = '\0';

	return *this;
}

MyString& MyString::operator+(short scount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", scount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+(int icount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", icount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+(bool bcount) {
	if (bcount) {
		char strTemp[5] = "true";
		while (m_capacity <= (m_strLen + 4)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}
	else {
		char strTemp[6] = "false";
		while (m_capacity <= (m_strLen + 5)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}

	return *this;
}

MyString& MyString::operator+(float fcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.5f", fcount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+(double dcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.8f", dcount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+(char const* const pstr) {
	size_t strlen = XYTStrLen(pstr);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+(MyString const& other) {
	while (m_capacity <= (m_strLen + other.m_strLen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), other.m_pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+(MyString const* const pother) {
	while (m_capacity <= (m_strLen + pother->m_strLen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), pother->m_pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+=(char cchar) {
	while (m_capacity <= (m_strLen + 1)) {
		AddCapacity();
	}

	m_pstr[m_strLen++] = cchar;
	m_pstr[m_strLen] = '\0';

	return *this;
}

MyString& MyString::operator+=(short scount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", scount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+=(int icount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", icount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+=(bool bcount) {
	if (bcount) {
		char strTemp[5] = "true";
		while (m_capacity <= (m_strLen + 4)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}
	else {
		char strTemp[6] = "false";
		while (m_capacity <= (m_strLen + 5)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}

	return *this;
}

MyString& MyString::operator+=(float fcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.5f", fcount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+=(double dcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.8f", dcount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+=(char const* const pstr) {
	size_t strlen = XYTStrLen(pstr);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+=(MyString const& other) {
	while (m_capacity <= (m_strLen + other.m_strLen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), other.m_pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator+=(MyString const* const pother) {
	while (m_capacity <= (m_strLen + pother->m_strLen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), pother->m_pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator*(short scount) {
	if (scount > 0) {
		for (short i = 1; i < scount; ++i) {
			while (m_capacity < (m_strLen * 2 + 1)) {
				AddCapacity();
			}

			XYTStrCat((m_pstr + m_strLen), m_pstr);
			m_strLen = XYTStrLen(m_pstr);
		}
	}
	else {
		ClearStr();
	}

	return *this;
}

MyString& MyString::operator*(int icount) {
	if (icount > 0) {
		for (short i = 1; i < icount; ++i) {
			while (m_capacity < (m_strLen * 2 + 1)) {
				AddCapacity();
			}

			XYTStrCat((m_pstr + m_strLen), m_pstr);
			m_strLen = XYTStrLen(m_pstr);
		}
	}
	else {
		ClearStr();
	}

	return *this;
}

MyString& MyString::operator*=(short scount) {
	if (scount > 0) {
		for (short i = 1; i < scount; ++i) {
			while (m_capacity < (m_strLen * 2 + 1)) {
				AddCapacity();
			}

			XYTStrCat((m_pstr + m_strLen), m_pstr);
			m_strLen = XYTStrLen(m_pstr);
		}
	}
	else {
		ClearStr();
	}

	return *this;
}

MyString& MyString::operator*=(int icount) {
	if (icount > 0) {
		for (short i = 1; i < icount; ++i) {
			while (m_capacity < (m_strLen * 2 + 1)) {
				AddCapacity();
			}

			XYTStrCat((m_pstr + m_strLen), m_pstr);
			m_strLen = XYTStrLen(m_pstr);
		}
	}
	else {
		ClearStr();
	}

	return *this;
}

MyString& MyString::operator=(char cchar) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	while (m_capacity <= 1) {	// 扩容
		AddCapacity();
	}

	m_pstr[0] = cchar;
	m_pstr[1] = '\0';	// 手动补齐【 '\0' 】
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator=(short scount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", scount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator=(int icount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", icount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator=(bool bcount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	if (bcount) {
		char strTemp[5] = "true";
		while (m_capacity <= (m_strLen + 4)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}
	else {
		char strTemp[6] = "false";
		while (m_capacity <= (m_strLen + 5)) {
			AddCapacity();
		}

		XYTStrCat((m_pstr + m_strLen), strTemp);
		m_strLen = XYTStrLen(m_pstr);
	}

	return *this;
}

MyString& MyString::operator=(float fcount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	char strTemp[99];
	sprintf_s(strTemp, 99, "%.5f", fcount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator=(double dcount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	char strTemp[99];
	sprintf_s(strTemp, 99, "%.8f", dcount);
	size_t strlen = XYTStrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), strTemp);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator=(char const* const pstr) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	size_t strlen = XYTStrLen(pstr);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator=(MyString const& other) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	while (m_capacity <= (m_strLen + other.m_strLen)) {	// 扩容
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), other.m_pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::operator=(MyString const* const pother) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	while (m_capacity <= (m_strLen + pother->m_strLen)) {	// 扩容
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), pother->m_pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

char const MyString::operator[](size_t index) {
	return m_pstr[index];
}

char  const MyString::operator[](size_t index) const {
	return m_pstr[index];
}

void MyString::Init() {
	m_pstr = nullptr;
	m_strLen = 0;
	m_capacity = 0;
	AddCapacity();
}

void MyString::ClearStr() {
	if (nullptr != m_pstr) {
		m_pstr[0] = '\0';
		m_strLen = 0;
	}
}

void MyString::AddCapacity() {
	if (m_pstr != nullptr) {
		char* strTemp = new char[m_capacity];
		for (int i = 0; i < (m_strLen + 1); ++i) {
			strTemp[i] = m_pstr[i];
		}

		m_capacity = (m_capacity + CLENGTH);
		STRCLEAR(m_pstr);

		m_pstr = new char[m_capacity];
		for (int i = 0; i < m_strLen + 1; ++i) {
			m_pstr[i] = strTemp[i];
		}

		STRCLEAR(strTemp);
	}
	else {
		m_pstr = new char[CLENGTH];
		m_strLen = 0;
		m_capacity = CLENGTH;
		m_pstr[m_strLen] = '\0';
	}
}

int MyString::StrLen() const {
	int index = 0;
	if (m_pstr != nullptr) {
		while ('\0' != m_pstr[index]) {
			++index;
		}
		return index;
	}
	else {
		return index;
	}
}

int MyString::StrLen(char const* const str) const {
	int index = 0;
	while (str[index] != '\0') {
		++index;
	}
	return index;
}

int MyString::StrLen(MyString const& other) {
	int index = 0;
	while (other.m_pstr[index] != '\0') {
		++index;
	}
	return index;
}

MyString& MyString::Append(char const& const str) {
	while (m_capacity <= (m_strLen + 1)) {
		AddCapacity();
	}
	m_pstr[m_strLen++] = str;

	return *this;
}

MyString& MyString::Append(char const* const str) {
	size_t strlen = XYTStrLen(str);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), str);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::Append(MyString const& other) {
	while (m_capacity <= (m_strLen + other.m_strLen)) {
		AddCapacity();
	}

	XYTStrCat((m_pstr + m_strLen), other.m_pstr);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::Append(char* str, size_t index, size_t len) {
	size_t strlen = XYTStrLen((str + index));

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	XYTStrNCat((m_pstr + m_strLen), (str + index), len);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::Append(MyString const& other, size_t len) {
	while (m_capacity <= (m_strLen + len)) {
		AddCapacity();
	}

	XYTStrNCat((m_pstr + m_strLen), other.m_pstr, len);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::Append(MyString const& other, size_t index, size_t len) {
	while (m_capacity <= (m_strLen + len)) {
		AddCapacity();
	}

	XYTStrNCat((m_pstr + m_strLen), (other.m_pstr + index), len);
	m_strLen = XYTStrLen(m_pstr);

	return *this;
}

MyString& MyString::Append(char ch, size_t count) {
	while (m_capacity <= (m_strLen + count)) {
		AddCapacity();
	}
	for (size_t i = 0; i < count; ++i) {
		m_pstr[m_strLen++] = ch;
	}

	return *this;
}

MyString& MyString::Aassign(char const& const str) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Append(str);

	return *this;
}

MyString& MyString::Aassign(char const* const str) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Append(str);

	return *this;
}

MyString& MyString::Aassign(MyString const& other) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Append(other);

	return *this;
}

MyString& MyString::Aassign(char const* str, size_t index, size_t len) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Append(str, index, len);

	return *this;
}

MyString& MyString::Aassign(MyString const& other, size_t len) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Append(other, len);

	return *this;
}

MyString& MyString::Aassign(MyString const& other, size_t index, size_t len) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Append(other, index, len);

	return *this;
}

MyString& MyString::Aassign(char ch, size_t count) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Append(ch, count);

	return 	*this;
}

char& MyString::At(size_t index) {
	if (index<0 && index>m_strLen) {
		throw "Out of range.";
	}
	else {
		return *(m_pstr + index);
	}
}

int MyString::Compare(MyString const& other) {
	return XYTStrCmp(m_pstr, other.m_pstr);
}

int MyString::Compare(char const* str) {
	return XYTStrCmp(m_pstr, str);
}

int MyString::Compare(size_t index, size_t len,
	MyString const& other, size_t index2, size_t len2) {
	char const* const str1 = m_pstr;
	char const* const str2 = other.m_pstr;

	if (str1 != str2) {
		while ('\0' != str1[index] && '\0' != str2[index2] && len > 0 && len2 > 0) {
			if (str1[index] > str2[index2]) {
				return 10;
			}
			if (str1[index] < str2[index2]) {
				return -10;
			}

			++index;
			++index2;

			--len;
			--len2;
		}

		if (0 != len && 0 != len2) {
			if ('\0' != str1[index] && '\0' == str2[index2]) {
				return 10;
			}
			if ('\0' == str1[index] && '\0' != str2[index2]) {
				return -10;
			}
		}

		if ('\0' != str1[index] && '\0' != str2[index2]) {
			if (len > len2) {
				return 10;
			}
			if (len < len2) {
				return -10;
			}
		}
	}

	return 0;
}

int MyString::Compare(size_t index, size_t len,
	char const* str, size_t index2, size_t len2) {
	char const* const str1 = m_pstr;
	char const* const str2 = str;

	if (str1 != str2) {
		while ('\0' != str1[index] && '\0' != str2[index2] && len > 0 && len2 > 0) {
			if (str1[index] > str2[index2]) {
				return 10;
			}
			if (str1[index] < str2[index2]) {
				return -10;
			}

			++index;
			++index2;

			--len;
			--len2;
		}

		if (0 != len && 0 != len2) {
			if ('\0' != str1[index] && '\0' == str2[index2]) {
				return 10;
			}
			if ('\0' == str1[index] && '\0' != str2[index2]) {
				return -10;
			}
		}

		if ('\0' != str1[index] && '\0' != str2[index2]) {
			if (len > len2) {
				return 10;
			}
			if (len < len2) {
				return -10;
			}
		}
	}

	return 0;
}

size_t MyString::Copy(char* const str, size_t count, size_t index) {
	XYTStrNCpy(str, (m_pstr + index), count);
	return count;
}

bool MyString::Empty() const {
	if (!StrLen()) {
		return true;
	}
	else {
		return false;
	}
}

MyString& MyString::Erase(size_t index, size_t count) {
	size_t strlen = m_strLen;
	char* pstrTemp = new char[m_strLen];
	XYTStrCpy(pstrTemp, m_pstr);

	if (nullptr != m_pstr) {
		ClearStr();
	}

	while (m_capacity <= (m_strLen + strlen - count)) {
		AddCapacity();
	}

	size_t indexstr = 0;
	size_t indexTemp = 0;
	while ('\0' != pstrTemp[indexTemp]) {
		if ((indexTemp >= index && indexTemp <= count)) {
			m_pstr[indexstr] = pstrTemp[indexTemp];
			++indexstr;
		}

		++indexTemp;
	}

	m_pstr[indexstr] = '\0';

	return *this;
}

int MyString::Find(MyString const& other, size_t index) {
	size_t indexStr = 0;
	while ('\0' != m_pstr[indexStr]) {
		if (m_pstr[indexStr] == other.m_pstr[0]) {
			size_t indexTemp = indexStr;

			size_t indexStrSet = 0;
			while ('\0' != m_pstr[indexTemp] && '\0' != other.m_pstr[indexStrSet]) {
				if (m_pstr[indexTemp] != other.m_pstr[indexStrSet]) {
					break;
				}

				++indexTemp;
				++indexStrSet;
			}

			if ('\0' == other.m_pstr[indexStrSet]) {	// 返回第一个匹配的字符索引
				return indexStr;
			}
			if ('\0' == m_pstr[indexTemp]) {		// 剩下的都不可能是了
				return -1;
			}
		}

		++indexStr;
	}

	return -1;
}

int MyString::Find(char const* str, size_t index) {
	size_t indexStr = 0;
	while ('\0' != m_pstr[indexStr]) {
		if (m_pstr[indexStr] == str[0]) {
			size_t indexTemp = indexStr;

			size_t indexStrSet = 0;
			while ('\0' != m_pstr[indexTemp] && '\0' != str[indexStrSet]) {
				if (m_pstr[indexTemp] != str[indexStrSet]) {
					break;
				}

				++indexTemp;
				++indexStrSet;
			}

			if ('\0' == str[indexStrSet]) {		// 返回第一个匹配的字符索引
				return indexStr;
			}
			if ('\0' == m_pstr[indexTemp]) {		// 剩下的都不可能是了
				return -1;
			}
		}

		++indexStr;
	}

	return -1;
}

int MyString::Find(char const* str, size_t index, size_t len) {
	size_t indexStr = 0;
	while ('\0' != m_pstr[indexStr] && len > 0) {
		if (m_pstr[indexStr] == str[0]) {
			size_t indexTemp = indexStr;

			size_t indexStrSet = 0;
			while ('\0' != m_pstr[indexTemp] && indexTemp > len && '\0' != str[indexStrSet]) {
				if (m_pstr[indexTemp] != str[indexStrSet]) {
					break;
				}

				++indexTemp;
				++indexStrSet;
			}

			if ('\0' == str[indexStrSet]) {		// 返回第一个匹配的字符索引
				return indexStr;
			}
			if ('\0' == m_pstr[indexTemp] || indexTemp > len) {		// 剩下的都不可能是了
				return -1;
			}
		}

		++indexStr;
		--len;
	}

	return -1;
}

int MyString::Find(char ch, size_t index) {
	size_t indexStr = 0;
	while ('\0' != m_pstr[indexStr]) {
		if (m_pstr[indexStr] == ch) {
			return indexStr;
		}

		++indexStr;
	}

	return -1;
}

size_t MyString::RFind(MyString const& other, size_t index) {
	size_t count = 0;
	while ('\0' != m_pstr[index]) {
		size_t indexStr = 0;
		while ('\0' != other.m_pstr[indexStr]) {
			if (m_pstr[index] == other.m_pstr[indexStr]) {
				count = index;
			}

			++indexStr;
		}

		++index;
	}
	return count;
}

size_t MyString::RFind(char const* str, size_t index) {
	size_t count = 0;
	while ('\0' != m_pstr[index]) {
		size_t indexStr = 0;
		while ('\0' != str[indexStr]) {
			if (m_pstr[index] == str[indexStr]) {
				count = index;
			}

			+ indexStr;
		}

		++index;
	}
	return count;
}

size_t MyString::RFind(char const* str, size_t index, size_t len) {
	size_t count = 0;
	while ('\0' != m_pstr[index] && len > 0) {
		size_t indexStr = 0;
		while ('\0' != str[indexStr]) {
			if (m_pstr[index] == str[indexStr]) {
				count = index;
			}

			++indexStr;
		}

		++index;
		--len;
	}
	return count;
}

size_t MyString::RFind(char ch, size_t index) {
	size_t count = 0;
	while ('\0' != m_pstr[index]) {
		if (m_pstr[index] == ch) {
			count = index;
		}

		++index;
	}
	return count;
}

size_t MyString::FindFirst(MyString const& other, size_t index) {
	if (nullptr != m_pstr && nullptr != other.m_pstr) {
		while ('\0' != m_pstr[index]) {
			size_t indexStr = 0;
			while ('\0' != other.m_pstr[indexStr]) {
				if (m_pstr[index] == other.m_pstr[indexStr]) {
					return indexStr;
				}

				++indexStr;
			}

			++index;
		}

		return 0;
	}
	else {
		return 0;
	}
}

size_t MyString::FindFirst(char const* str, size_t index) {
	if (nullptr != m_pstr && nullptr != str) {
		while ('\0' != m_pstr[index]) {
			size_t indexStr = 0;
			while ('\0' != str[indexStr]) {
				if (m_pstr[index] == str[indexStr]) {
					return indexStr;
				}

				++indexStr;
			}

			++index;
		}

		return 0;
	}
	else {
		return 0;
	}
}

size_t MyString::FindFirst(char const* str, size_t index, size_t len) {
	if (nullptr != m_pstr && nullptr != str) {
		while ('\0' != m_pstr[index] && len > 0) {
			size_t indexStr = 0;
			while ('\0' != str[indexStr]) {
				if (m_pstr[index] == str[indexStr]) {
					return indexStr;
				}

				++indexStr;
			}

			++index;
			--len;
		}

		return 0;
	}
	else {
		return 0;
	}
}

size_t MyString::FindFirst(char ch, size_t index) {
	if (nullptr != m_pstr) {
		while ('\0' != m_pstr[index]) {
			if (m_pstr[index] == ch) {
				return index;
			}

			++index;
		}
	}
	else {
		return 0;
	}
}

size_t MyString::FindFirstNot(MyString const& other, size_t index) {
	if (nullptr != m_pstr && nullptr != other.m_pstr) {
		size_t count = 0;
		while ('\0' != m_pstr[index]) {
			size_t indexStr = 0;
			while ('\0' != other.m_pstr[index]) {
				if (m_pstr[index] == other.m_pstr[indexStr]) {
					count = index;
				}

				++indexStr;
			}

			++index;
		}

		return count;
	}
	else {
		return 0;
	}
}

size_t MyString::FindFirstNot(char const* str, size_t index) {
	if (nullptr != m_pstr) {
		size_t count = 0;
		while ('\0' != m_pstr[index]) {
			size_t indexStr = 0;
			while ('\0' != str[indexStr]) {
				if (m_pstr[index] == str[indexStr]) {
					count = index;
				}

				++indexStr;
			}

			++index;
		}

		return count;
	}
	else {
		return 0;
	}
}

size_t MyString::FindFirstNot(char const* str, size_t index, size_t len) {
	if (nullptr != m_pstr) {
		size_t count = 0;
		while ('\0' != m_pstr[index] && len > 0) {
			size_t indexStr = 0;
			while ('\0' != str[indexStr]) {
				if (m_pstr[index] == str[indexStr]) {
					count = index;
				}

				++indexStr;
			}

			++index;
			--len;
		}

		return count;
	}
	else {
		return 0;
	}
}

size_t MyString::FindFirstNot(char ch, size_t index) {
	if (nullptr!=m_pstr) {
		size_t count = 0;
		while ('\0'!=m_pstr[index]) {
			if (m_pstr[index]==ch) {
				count = index;
			}

			++index;
		}

		return count;
	}
	else {
		return 0;
	}
}

char const* const MyString::GetString() {
	return m_pstr;
}

size_t MyString::GetStrLen() {
	return m_strLen;
}

size_t MyString::GetStrCap() {
	return m_capacity;
}

size_t MyString::GetMaxStr() {
	return m_capacity;
}

bool operator>(MyString const& str, MyString const& other) {
	if (XYTStrCmp(str.m_pstr, other.m_pstr) > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(MyString const& str, MyString const& other) {
	if (XYTStrCmp(str.m_pstr, other.m_pstr) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(MyString const& str, MyString const& other) {
	if (XYTStrCmp(str.m_pstr, other.m_pstr) >= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(MyString const& str, MyString const& other) {
	if (XYTStrCmp(str.m_pstr, other.m_pstr) <= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(MyString const& str, MyString const& other) {
	if (0 == XYTStrCmp(str.m_pstr, other.m_pstr)) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(MyString const& str, MyString const& other) {
	if (0 != XYTStrCmp(str.m_pstr, other.m_pstr)) {
		return true;
	}
	else {
		return false;
	}
}

void XYT_TestString() {
	char const*  num01 = "abc";
	char const*  num02 = "abc";
	MyString MyStr001(num01);
	MyString MyStr002("qwe");
	 int num = 10;
	MyStr001= &MyStr002;

	cout << MyStr001[1] << endl;
	cout << MyStr001.GetStrCap() << endl;
	cout << MyStr001.GetStrLen() << endl;

	cout << MyStr001.GetString() << endl;
	cout << MyStr001.GetStrCap() << endl;
	cout << MyStr001.GetStrLen() << endl;
}

