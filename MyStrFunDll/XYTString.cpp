#include "XYTString.h"
#include "pch.h"

__declspec (dllexport) char* const XYTStrCat(char* const to, char const* const from) {
	if (to != from) {
		char* const pdest = to;
		char const* const psrc = from;

		/* 考虑内存重叠 */
		if (psrc > pdest) {	// 源在目标后面，正向拷贝，从头开始
			size_t index = 0;
			while (psrc[index]) {
				pdest[index] = psrc[index];
				++index;
			}
			pdest[index] = '\0';	// 上方的【 while 】并没有把【 '\0' 】拷贝进来
		}
		else {
			int index = 0;
			while ('\0' != psrc[index]) {
				++index;
			}

			for (int i = index - 1; i >= 0; --i) {
				pdest[i] = psrc[i];
			}
			pdest[index] = '\0';	// 上方的【 for 】并没有把【 '\0' 】拷贝进来
		}
	}

	return to;
}

__declspec (dllexport) char* const XYTStrNCat(char* const to, char const* const from, size_t count) {
	if (to != from) {
		char* const pdest = to;
		char const* const psrc = from;

		/* 考虑内存重叠 */
		if (psrc > pdest) {
			for (size_t i = 0; i < count; ++i) {	// 已知使用 for
				pdest[i] = psrc[i];
			}
		}
		else {
			for (int i = (int)(count - 1); i >= 0; --i) {
				pdest[i] = psrc[i];
			}
		}

		pdest[count] = '\0';	// 补【 '\0' 】
	}

	return to;
}

__declspec (dllexport) char* const XYTStrChr(char const* const str, int ch) {
	size_t index = 0;
	char* const pstr = (char* const)str;

	while ('\0' != pstr[index]) {
		if (str[index] == ch) {
			return (pstr + index);
		}

		++index;
	}

	return nullptr;
}

__declspec (dllexport) char* const XYTStrRChr(char const* const str, int ch) {
	size_t rindex = 0;
	while ('\0' != str[rindex]) {
		++rindex;
	}
	char* const pstr = (char* const)str;

	// 也有可能是【 '\0' 】，所以【 i = rindex 】
	for (int i = (int)rindex; i >= 0; --i) {
		if (pstr[i] == ch) {
			return pstr + i;
		}
	}

	return nullptr;
}

__declspec (dllexport) int XYTStrCmp(char const* const str1, char const* const str2) {
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
	}	// end if

	return 0;
}

__declspec (dllexport) int XYTStrNCmp(char const* const str1, char const* const str2, size_t count) {
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

__declspec (dllexport) void XYTStrColl() {

}


__declspec (dllexport) char* const XYTStrCpy(char* const to, char const* const from) {
	if (to != from) {
		if (from > to) {
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

__declspec (dllexport) char* const XYTStrNCpy(char* const to, char const* const from, size_t count) {
	if (to != from) {
		if (from > to) {
			for (size_t i = 0; i < count; ++i) {
				to[i] = from[i];
			}
		}
		else {
			for (int i = (int)(count - 1); i >= 0; --i) {
				to[i] = from[i];
			}
		}
		to[count] = '\0';//手动添加【 '\0' 】，就是这么豪横~
	}

	return to;
}

__declspec (dllexport) size_t XYTStrSpn(char const* const str, char const* const strCharSet) {
	size_t count = 0;

	size_t indexStr = 0;
	while ('\0' != str[indexStr]) {
		size_t indexStrSet = 0;
		while ('\0' != strCharSet[indexStrSet]) {
			if (str[indexStr] == strCharSet[indexStrSet]) {		// 存在str2中就长度加一
				++count;
				break;
			}

			++indexStrSet;
		}

		if ('\0' == strCharSet[indexStrSet]) {		// 出现了没在【 str2 】中的字符了
			break;
		}

		++indexStr;
	}

	return count;
}

__declspec (dllexport) size_t XYTStrCSpn(char const* const str, char const* const strCharSet) {
	size_t count = 0;	// 本可以不用【 count 】的，只是为了	清楚一点那个在计数

	size_t indexStr = 0;
	while ('\0' != str[indexStr]) {
		size_t indexStrSet = 0;
		while ('\0' != strCharSet[indexStrSet]) {
			if (str[indexStr] == strCharSet[indexStrSet]) {
				return count;
			}

			++indexStrSet;
		}

		++count;
		++indexStr;
	}

	return count;
}

__declspec (dllexport) size_t XYTStrLen(char const* const str) {
	size_t index = 0;
	while ('\0' != str[index]) {
		++index;
	}

	return index;
}

__declspec (dllexport) char const* const XYTStrPbrk(char const* const str, char const* const strCharSet) {
	size_t indexStr = 0;
	while ('\0' != str[indexStr]) {
		size_t indexStrSet = 0;
		while ('\0' != strCharSet[indexStrSet]) {
			if (str[indexStr] == strCharSet[indexStrSet]) {
				return (char const* const)(str + indexStr);
			}

			++indexStrSet;
		}

		++indexStr;
	}

	return nullptr;
}

__declspec (dllexport) char const* const XYTStrStr(char const* const str, char const* const strCharSet) {
	char const* const pstr = nullptr;

	size_t indexStr = 0;
	while ('\0' != str[indexStr]) {
		if (str[indexStr] == strCharSet[0]) {
			size_t indexTemp = indexStr;

			size_t indexStrSet = 0;
			while ('\0' != str[indexTemp] && '\0' != strCharSet[indexStrSet]) {
				if (str[indexTemp] != strCharSet[indexStrSet]) {
					break;
				}

				++indexTemp;
				++indexStrSet;
			}

			if ('\0' == strCharSet[indexStrSet]) {		// 返回第一个匹配的字符首地址
				return (char const* const)(str + indexStr);
			}
			if ('\0' == str[indexTemp]) {		// 剩下的都不可能是了
				return nullptr;
			}
		}

		++indexStr;
	}

	return nullptr;
}

