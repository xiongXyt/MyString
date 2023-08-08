#include "XYT_string.h"

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

	m_pstr[count] = '\0';	// 手动补【 '\0' 】
	m_strLen = GetLen();
}

MyString::MyString(short scount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];
		sprintf_s(strTemp, 99, "%d", scount);
		int strlen = GetLen();

		while (m_capacity <= (m_strLen + strlen)) {	// 插入前判断扩容，【 '\0' 】
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}
}

MyString::MyString(int icount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];
		sprintf_s(strTemp, 99, "%d", icount);
		int strlen = GetLen();

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
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

			StrCpy((m_pstr + m_strLen), strTemp);
			m_strLen = GetLen();
		}
	}
	else {
		char strTemp[6] = "false";
		for (size_t i = 0; i < count; ++i) {
			while (m_capacity <= (m_strLen + 5)) {
				AddCapacity();
			}

			StrCpy((m_pstr + m_strLen), strTemp);
			m_strLen = GetLen();
		}
	}
}

MyString::MyString(float fcount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];

		/* 【 float 】的固定字符长度为【 5 】，后续在考虑优化 */
		sprintf_s(strTemp, 99, "%.5f", fcount);
		int strlen = GetLen();

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}
}

MyString::MyString(double dcount, size_t count) {
	Init();

	for (size_t i = 0; i < count; ++i) {
		char strTemp[99];

		/* 【 double 】的固定字符长度为【 8 】，后续在考虑优化 */
		sprintf_s(strTemp, 99, "%.8f", dcount);
		int strlen = GetLen();

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}
}

MyString::MyString(char const* const pstr, size_t count) {
	Init();

	int strlen = StrLen(pstr);
	while (count > 0) {
		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), pstr);
		m_strLen = GetLen();

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

		StrNCpy((m_pstr + m_strLen), fpstr, strlen);
		m_strLen = GetLen();
	}
}

MyString::MyString(MyString const& other) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	while (m_capacity <= (other.m_strLen)) {
		AddCapacity();
	}

	m_pstr = new char[other.m_strLen + 1];
	StrCpy(m_pstr, other.m_pstr);

	m_strLen = GetLen();
}

MyString::MyString(MyString const* const pother) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	while (m_capacity <= (pother->m_strLen)) {
		AddCapacity();
	}

	m_pstr = new char[pother->m_strLen + 1];
	StrCpy(m_pstr, pother->m_pstr);

	m_strLen = GetLen();
}

MyString& MyString::operator+(char cchar) {
	while (m_capacity <= (m_strLen + 1)) {
		AddCapacity();
	}

	m_pstr[m_strLen++] = cchar;
	m_pstr[m_strLen] = '\0';	// 补【 '\0' 】

	return *this;
}

MyString& MyString::operator+(short scount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", scount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+(int icount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", icount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+(bool bcount) {
	if (bcount) {
		char strTemp[5] = "true";
		while (m_capacity <= (m_strLen + 4)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}
	else {
		char strTemp[6] = "false";
		while (m_capacity <= (m_strLen + 5)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator+(float fcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.5f", fcount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+(double dcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.8f", dcount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+(char const* const pstr) {
	size_t strlen = StrLen(pstr);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), pstr);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+(MyString const& other) {
	if (nullptr != other.m_pstr) {
		while (m_capacity <= (m_strLen + other.m_strLen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), other.m_pstr);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator+(MyString const* const pother) {
	if (nullptr != pother->m_pstr) {
		while (m_capacity <= (m_strLen + pother->m_strLen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), pother->m_pstr);
		m_strLen = GetLen();
	}

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
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+=(int icount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", icount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+=(bool bcount) {
	if (bcount) {
		char strTemp[5] = "true";
		while (m_capacity <= (m_strLen + 4)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}
	else {
		char strTemp[6] = "false";
		while (m_capacity <= (m_strLen + 5)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator+=(float fcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.5f", fcount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+=(double dcount) {
	char strTemp[99];
	sprintf_s(strTemp, 99, "%.8f", dcount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator+=(char const* const pstr) {
	if (nullptr != pstr) {
		size_t strlen = StrLen(pstr);

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), pstr);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator+=(MyString const& other) {
	if (nullptr != other.m_pstr) {
		while (m_capacity <= (m_strLen + other.m_strLen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), other.m_pstr);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator+=(MyString const* const pother) {
	if (nullptr != pother->m_pstr) {
		while (m_capacity <= (m_strLen + pother->m_strLen)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), pother->m_pstr);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator*(short scount) {
	if (scount > 0) {
		for (short i = 1; i < scount; ++i) {
			while (m_capacity < (m_strLen * 2 + 1)) {
				AddCapacity();
			}

			StrCpy((m_pstr + m_strLen), m_pstr);
			m_strLen = GetLen();
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

			StrCpy((m_pstr + m_strLen), m_pstr);
			m_strLen = GetLen();
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

			StrCpy((m_pstr + m_strLen), m_pstr);
			m_strLen = GetLen();
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

			StrCpy((m_pstr + m_strLen), m_pstr);
			m_strLen = GetLen();
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
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator=(short scount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", scount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator=(int icount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	char strTemp[99];
	sprintf_s(strTemp, 99, "%d", icount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

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

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
	}
	else {
		char strTemp[6] = "false";
		while (m_capacity <= (m_strLen + 5)) {
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), strTemp);
		m_strLen = GetLen();
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
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator=(double dcount) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	char strTemp[99];
	sprintf_s(strTemp, 99, "%.8f", dcount);
	size_t strlen = StrLen(strTemp);

	while (m_capacity <= (m_strLen + strlen)) {	// 扩容
		AddCapacity();
	}

	StrCpy((m_pstr + m_strLen), strTemp);
	m_strLen = GetLen();

	return *this;
}

MyString& MyString::operator=(char const* const pstr) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	if (nullptr != pstr) {
		size_t strlen = StrLen(pstr);

		while (m_capacity <= (m_strLen + strlen)) {	// 扩容
			AddCapacity();
		}

		StrCpy((m_pstr + m_strLen), pstr);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator=(MyString const& other) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	if (nullptr != other.m_pstr) {
		while (m_capacity <= (other.m_strLen)) {	// 扩容
			AddCapacity();
		}

		StrCpy((m_pstr), other.m_pstr);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::operator=(MyString const* const pother) {
	if (nullptr != m_pstr) {
		ClearStr();
	}

	Init();

	if (nullptr != pother->m_pstr) {
		while (m_capacity <= (pother->m_strLen)) {	// 扩容
			AddCapacity();
		}

		StrCpy((m_pstr), pother->m_pstr);
		m_strLen = GetLen();
	}

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

void MyString::DeleteStr() {
	if (nullptr!=m_pstr) {
		STRCLEAR(m_pstr);
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

		m_capacity = (m_capacity + CLENGTH);	// 扩容大小固定
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
		m_pstr[m_strLen] = '\0';	// 手动补【 '\0' 】
	}
}

size_t MyString::GetLen() {
	size_t index = 0;
	while ('\0' != m_pstr[index]) {
		++index;
	}
	return index;
}

char* const MyString::StrCat(char* const to, char const* const from) {
	// 缺少字符串的被裁剪部分的销毁
	if (to != from) {
		char* const pdest = to;
		char const* const psrc = from;

		/* 内存重叠 */
		if (psrc > pdest) {		// 源在目标后面，正向拷贝，从头开始
			size_t index = 0;
			while ('\0' != psrc[index]) {
				pdest[index] = psrc[index];
				++index;
			}
			pdest[index] = '\0';	// 补【 '\0' 】
		}
		else {
			int index = 0;
			while ('\0' != psrc[index]) {
				++index;
			}

			for (int i = index - 1; i >= 0; --i) {
				pdest[i] = psrc[i];
			}
			pdest[index] = '\0';	// 补【 '\0' 】
		}
	}

	return to;
}

char* const MyString::StrCpy(char* const to, char const* const from) {
	if (to != from) {
		if (from > to) {	// 内存重叠
			size_t index = 0;
			while (to[index] = from[index]) {
				++index;
			}
		}
		else {
			int index = 0;
			while ('\0' != from[index]) {
				++index;
			}

			// 因为有【 '\0' 】，所以是【 i = index 】
			for (int i = index; i >= 0; --i) {
				to[i] = from[i];
			}
		}
	}

	return to;
}

char* const MyString::StrNCpy(char* const to, char const* const from, size_t count) {
	if (to != from) {
		if (from > to) {	// 内存重叠
			for (size_t i = 0; i < count; ++i) {
				to[i] = from[i];
			}
		}
		else {
			for (int i = (int)(count - 1); i >= 0; --i) {
				to[i] = from[i];
			}
		}

		to[count] = '\0';	// 补【 '\0' 】
	}

	return to;
}

int MyString::StrCmp(char const* const str1, char const* const str2) const{
	if (nullptr != str1 && nullptr == str2) {
		return 10;
	}
	if (nullptr == str1 && nullptr != str2) {
		return -10;
	}
	if (nullptr == str1 && nullptr == str2) {
		return 0;
	}

	if (str1 != str2) {
		size_t index = 0;

		while ('\0' != str1[index] && '\0' != str2[index]) {
			if (str1[index] > str2[index]) {
				return 10;
			}
			if (str1[index] < str2[index]) {
				return -10;
			}

			++index;
		}

		if ('\0' != str1[index] && '\0' == str2[index]) {
			return 10;
		}
		if ('\0' == str1[index] && '\0' != str2[index]) {
			return -10;
		}
	}

	return 0;
}

int MyString::StrNCmp(char const* const str1, char const* const str2, size_t count) const{
	if (nullptr != str1 && nullptr == str2) {
		return 10;
	}
	if (nullptr == str1 && nullptr != str2) {
		return -10;
	}
	if (nullptr == str1 && nullptr == str2) {
		return 0;
	}

	if (str1 != str2) {
		size_t index = 0;
		while ('\0' != str1[index] && '\0' != str2[index] && count > 0) {
			if (str1[index] > str2[index]) {
				return 10;
			}
			if (str1[index] < str2[index]) {
				return -10;
			}

			++index;

			--count;
		}
		if (0 != count) {
			if ('\0' != str1[index] && '\0' == str2[index]) {
				return 10;
			}
			if ('\0' == str1[index] && '\0' != str2[index]) {
				return -10;
			}
		}
	}

	return 0;
}

int MyString::StrLen() {
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

int MyString::StrLen(char const* const str) {
	int index = 0;
	if (nullptr != str) {
		while ('\0' != str[index]) {
			++index;
		}
	}
	else {
		return index;
	}
}

int MyString::StrLen(MyString const& other) {
	int index = 0;
	if (nullptr != other.m_pstr) {
		while (other.m_pstr[index] != '\0') {
			++index;
		}
	}
	else {
		return index;
	}
}

MyString& MyString::Append(char const& const str) {
	while (m_capacity <= (m_strLen + 1)) {
		AddCapacity();
	}
	m_pstr[m_strLen++] = str;
	m_pstr[m_strLen] = '\0';	// 补【 '\0' 】

	return *this;
}

MyString& MyString::Append(char const* const str) {
	size_t strlen = StrLen(str);

	while (m_capacity <= (m_strLen + strlen)) {
		AddCapacity();
	}

	m_pstr[m_strLen++] = *str;
	m_pstr[m_strLen] = '\0';	// 补【 '\0' 】

	return *this;
}

MyString& MyString::Append(MyString const& other) {
	if (nullptr != other.m_pstr) {
		while (m_capacity <= (m_strLen + other.m_strLen)) {
			AddCapacity();
		}
		StrCpy((m_pstr + m_strLen), other.m_pstr);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::Append(char const* const str, size_t index, size_t len) {
	if (nullptr != str) {
		size_t strlen = StrLen((str + index));

		while (m_capacity <= (m_strLen + strlen)) {
			AddCapacity();
		}

		StrNCpy((m_pstr + m_strLen), (str + index), len);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::Append(MyString const& other, size_t len) {
	if (nullptr != other.m_pstr) {
		while (m_capacity <= (m_strLen + len)) {
			AddCapacity();
		}

		StrNCpy((m_pstr + m_strLen), other.m_pstr, len);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::Append(MyString const& other, size_t index, size_t len) {
	if (nullptr != other.m_pstr) {
		while (m_capacity <= (m_strLen + len)) {
			AddCapacity();
		}

		StrNCpy((m_pstr + m_strLen), (other.m_pstr + index), len);
		m_strLen = GetLen();
	}

	return *this;
}

MyString& MyString::Append(char ch, size_t count) {
	while (m_capacity <= (m_strLen + count)) {
		AddCapacity();
	}
	for (size_t i = 0; i < count; ++i) {
		m_pstr[m_strLen++] = ch;
	}

	m_pstr[m_strLen] = '\0';

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
	// 缺少异常处理
	if (index<0 && index>m_strLen) {
		throw "Out of range.";
	}
	else {
		return *(m_pstr + index);
	}
}

int MyString::Compare(MyString const& other) {
	return StrCmp(m_pstr, other.m_pstr);
}

int MyString::Compare(char const* str) {
	return StrCmp(m_pstr, str);
}

int MyString::Compare(size_t index, size_t len, MyString const& other, size_t index2, size_t len2) {
	if (nullptr != m_pstr && nullptr == other.m_pstr) {
		return 10;
	}
	if (nullptr == m_pstr && nullptr != other.m_pstr) {
		return -10;
	}
	if (nullptr == m_pstr && nullptr == other.m_pstr) {
		return 0;
	}

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

int MyString::Compare(size_t index, size_t len, char const* str, size_t index2, size_t len2) {
	if (nullptr != m_pstr && nullptr == str) {
		return 10;
	}
	if (nullptr == m_pstr && nullptr != str) {
		return -10;
	}
	if (nullptr == m_pstr && nullptr == m_pstr) {
		return 0;
	}

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
	StrNCpy(str, (m_pstr + index), count);
	return count;
}

bool MyString::Empty() {
	if (!GetLen()) {
		return true;
	}
	else {
		return false;
	}
}

// 这里的删除可能还有一点问题
MyString& MyString::Erase(size_t index, size_t count) {
	if (nullptr != m_pstr && m_strLen > 0) {
		size_t strlen = m_strLen;
		char* pstrTemp = new char[m_strLen];
		StrCpy(pstrTemp, m_pstr);

		if (nullptr != m_pstr) {
			ClearStr();
		}

		while (m_capacity <= (m_strLen + strlen - count)) {
			AddCapacity();
		}

		size_t indexstr = 0;
		size_t indexTemp = 0;
		while ('\0' != pstrTemp[indexTemp]) {
			if ((indexTemp == index)) {
				indexTemp += count + 1;
			}
			m_pstr[indexstr] = pstrTemp[indexTemp];

			++indexstr;
			++indexTemp;
		}

		m_pstr[indexstr] = '\0';
	}

	return *this;
}

int MyString::Find(MyString const& other, size_t index) {
	if (nullptr == m_pstr || nullptr == other.m_pstr) {
		return -1;
	}

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
	if (nullptr == m_pstr || nullptr == str) {
		return -1;
	}

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
	if (nullptr == m_pstr || nullptr == str) {
		return -1;
	}

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
	if (nullptr == m_pstr) {
		return -1;
	}
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
	if (nullptr == m_pstr || nullptr == other.m_pstr) {
		return -1;
	}

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
	if (nullptr == m_pstr || nullptr == str) {
		return -1;
	}

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
	if (nullptr == m_pstr || nullptr == str) {
		return -1;
	}

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
	if (nullptr==m_pstr) {
		return -1;
	}

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
		return -1;
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
		return -1;
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
		return -1;
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
		return -1;
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
		return -1;
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
		return -1;
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
		return -1;
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
		return -1;
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
	if (str.StrCmp(str.m_pstr, other.m_pstr) > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(MyString const& str, MyString const& other) {
	if (str.StrCmp(str.m_pstr, other.m_pstr) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(MyString const& str, MyString const& other) {
	if (str.StrCmp(str.m_pstr, other.m_pstr) >= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(MyString const& str, MyString const& other) {
	if (str.StrCmp(str.m_pstr, other.m_pstr) <= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(MyString const& str, MyString const& other) {
	if (0 == str.StrCmp(str.m_pstr, other.m_pstr)) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(MyString const& str, MyString const& other) {
	if (0 != str.StrCmp(str.m_pstr, other.m_pstr)) {
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

