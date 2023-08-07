#ifndef XYTSTRING_H_
#define XYTSTRING_H_

/* ************************************************************ */
// 功能：函数将字符串【 from 】连接到【 to 】的末端，并返回指针【 to 】。
__declspec (dllexport) char* const XYTStrCat(char* const to, char const* const from);

/* ************************************************************ */
// 功能：将字符串【 from 】中至多【 count 】个字符连接到字符串【 to 】中，
// 追加空值结束符。返回处理完成的字符串。
__declspec (dllexport) char* const XYTStrNCat(char* const to, char const* const from, size_t count);

/* ************************************************************ */
// 功能：函数返回一个指向【 str 】中【 ch 】首次出现的位置，
// 当没有在【 str 】中找【 ch 】到返回【 NULL 】。
__declspec (dllexport) char* const XYTStrChr(char const* const str, int ch);

/* ************************************************************ */
// 功能：函数返回一个指针，它指向字符【 ch 】在字符串【 str 】末次出现的位置，
// 如果匹配失败，返回【 NULL 】。
__declspec (dllexport) char* const XYTStrRChr(char const* const str, int ch);

/* ************************************************************ */
// 比较字符串【 str1 and str2 】
// 返回值大于零：【 str1 >  str2 】
// 返回值等于零：【 str1 == str2 】
// 返回值小于零：【 str1 <  str2 】
__declspec (dllexport) int XYTStrCmp(char const* const str1, char const* const str2);

/* ************************************************************ */
// 比较字符串【 str1 and str2 】，至少【 count 】个字符
// 返回值大于零：【 str1 >  str2 】
// 返回值等于零：【 str1 == str2 】
// 返回值小于零：【 str1 <  str2 】
__declspec (dllexport) int XYTStrNCmp(char const* const str1, char const* const str2, size_t count);

/* ************************************************************ */
// 不知道怎么写
__declspec (dllexport) void XYTStrColl();

/* ************************************************************ */
// 功能：复制字符串【 from 】中的字符到字符串【 to 】，
// 包括空值结束符，返回值为指针【 to 】。
__declspec (dllexport) char* const XYTStrCpy(char* const to, char const* const from);

/* ************************************************************ */
// 功能：将字符串【 from 】中至多【 count 】个字符复制到字符串【 to 】中，
// 如果字符串【 from 】的长度小于【 count 】，其余部分用【 '\0' 】填补，
// 返回处理完成的字符串。
__declspec (dllexport) char* const XYTStrNCpy(char* const to, char const* const from, size_t count);

/* ************************************************************ */
// 功能：函数返回字符串【 str 】中第一个不包含于字符串【 strCharSet 】的字符的索引。
__declspec (dllexport) size_t XYTStrSpn(char const* const str, char const* const strCharSet);

/* ************************************************************ */
// 功能：函数返回【 str 】开头连续【 n 】个字符都不含字符串【 strCharSet 】内字符的字符数。
__declspec (dllexport) size_t XYTStrCSpn(char const* const str, char const* const strCharSet);

/* ************************************************************ */
// 功能：函数返回字符串【 str 】的长度( 即空值结束符之前字符数目)。
__declspec (dllexport) size_t XYTStrLen(char const* const str);

/* ************************************************************ */
// 功能：函数返回一个指针，它指向字符串【 str 】中任意字符在字符串【 strCharSet 】，
// 首次出现的位置，如果不存在返回【 NULL 】。
__declspec (dllexport) char const* const XYTStrPbrk(char const* const str, char const* const strCharSet);

/* ************************************************************ */
// 功能：函数返回一个指针，它指向字符串【 str2 】首次出现于字符串【 str1 】中的位置，
// 如果没有找到，返回【 NULL 】。
__declspec (dllexport) char const* const  XYTStrStr(char const* const str, char const* const strCharSet);

#endif // !XYTSTRING_H_

