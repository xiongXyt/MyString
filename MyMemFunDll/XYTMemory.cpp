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
			/* '\0'Ҳ�д�С */
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

		/* �ϰ�û�п����ڴ��ص����°濼�����ڴ��ص����ͺ͡� memmove ��һ���� */
		if (pfrom > pto) {	// Դ��Ŀ����棬���򿽱�����ͷ��ʼ
			for (size_t i = 0; i < count; ++i) {
				pto[i] = pfrom[i];
			}
		}
		else {	// Դ��Ŀ��ǰ�棬���򿽱������Ǵ�ƨ�ɿ�ʼ
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

		/* �ͺͿ������ڴ��ص��� memcpy һ�� */
		if (pfrom > pto) {	// Դ��Ŀ����棬���򿽱�����ͷ��ʼ
			for (size_t i = 0; i < count; ++i) {
				pto[i] = pfrom[i];
			}
		}
		else {	// Դ��Ŀ��ǰ�棬���򿽱�����ƨ�ɿ�ʼ
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

