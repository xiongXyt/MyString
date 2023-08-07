#ifndef XYTMEMORY_H_
#define XYTMEMORY_H_

/* ************************************************************ */
// 功能：函数在【 buffer 】指向的数组的【 count 】个字符的字符串里查找【 ch 】
// 首次出现的位置。返回一个指针，指向【 ch 】在字符串中首次出现的位置，
// 如果【 ch 】没有在字符串中找到，返回【 NULL 】。
__declspec (dllexport) void* const XYTMemChr(void const* const buffer, int ch, size_t count);

/* ************************************************************ */
// 功能：函数比较【 buf1 】和【 buf2 】的前【 count 】个字符。
// 返回值大于零：【 buf1 >  buf2 】
// 返回值等于零：【 buf1 == buf2 】
// 返回值小于零：【 buf1 <  buf2 】
__declspec (dllexport) int XYTMemCmp(void const* const buf1, void const* const buf2, size_t count);

/* ************************************************************ */
// 功能：函数从【 from 】中复制【 count 】个字符到【 to 】中，
// 并返回【 to 】指针。 如果【to 】和【 from 】重叠，则函数行为也确定。
__declspec (dllexport) void* const XYTMemCpy(void* const to, void const* const from, size_t count);

/* ************************************************************ */
// 功能: 与【 mencpy 】相同，不同的是当【 to 】和【 from 】重叠，函数正常仍能工作。
__declspec (dllexport) void* const XYTMemMove(void* const to, void const* const from, size_t count);

/* ************************************************************ */
// 功能: 函数拷贝【 ch 】到【 buffer 】从头开始的【 count 】个字符里，
// 并返回【 buffer 】指针，可以应用在将一段内存初始化为某个值。
__declspec (dllexport) void* const XYTMemSet(void* const buffer, int ch, size_t count);

#endif // !XYTMEMORY_H_

