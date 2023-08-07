#include "XYTMemory.h"
#include "pch.h"

__declspec (dllexport) void* const XYTMemChr(void const* const buffer, int ch, size_t count) {
	char ccmpTemp = (char)ch;
	unsigned char* const pbuff = (unsigned char* const)buffer;

	size_t index = 0;
	while (pbuff[index] != '\0' && count > 0) {
		if (pbuff[index] == ccmpTemp) {
			return (pbuff + index);
		}
		++index;
	}

	return nullptr;
}

__declspec (dllexport) int XYTMemCmp(void const* const buf1, void const* const buf2, size_t count) {
	if (buf1 == buf2) {
		return 0;
	}
	else {
		unsigned char const* pcbuf1 = (unsigned char const* const)buf1;
		unsigned char const* pcbuf2 = (unsigned char const* const)buf2;

		for (size_t i = 0; i < count; ++i) {
			/* '\0'也有大小 */
			if (pcbuf1[i] > pcbuf2[i]) {
				return 10;
			}
			if (pcbuf1[i] < pcbuf2[i]) {
				return -10;
			}
		}

		return 0;
	}
}

__declspec (dllexport) void* const XYTMemCpy(void* const to, void const* const from, size_t count) {
	if (to != from) {
		unsigned char* const pto = (unsigned char* const)to;
		unsigned const char* const pfrom = (unsigned const char* const)from;

		/* 老版没有考虑内存重叠，新版考虑了内存重叠，就和【 memmove 】一样了 */
		if (pfrom > pto) {	// 源在目标后面，正向拷贝，从头开始
			for (size_t i = 0; i < count; ++i) {
				pto[i] = pfrom[i];
			}
		}
		else {	// 源在目标前面，反向拷贝，就是从屁股开始
			for (int i = (int)(count - 1); i >= 0; --i) {
				pto[i] = pfrom[i];
			}
		}
	}

	return to;
}

__declspec (dllexport) void* const XYTMemMove(void* const to, void const* const from, size_t count) {
	if (to != from) {
		unsigned char* const pto = (unsigned char* const)to;
		unsigned char const* const pfrom = (unsigned char const* const)from;

		/* 就和考虑了内存重叠的 memcpy 一样 */
		if (pfrom > pto) {	// 源在目标后面，正向拷贝，从头开始
			for (size_t i = 0; i < count; ++i) {
				pto[i] = pfrom[i];
			}
		}
		else {	// 源在目标前面，反向拷贝，从屁股开始
			for (int i = (int)(count - 1); i >= 0; --i) {
				pto[i] = pfrom[i];
			}
		}
	}

	return to;
}

__declspec (dllexport) void* const XYTMemSet(void* const buffer, int ch, size_t count) {
	unsigned char* const pbuf = (unsigned char* const)buffer;
	for (size_t i = 0; i < count; ++i) {
		pbuf[i] = ch;
	}

	return buffer;
}

