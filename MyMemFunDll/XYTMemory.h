#ifndef XYTMEMORY_H_
#define XYTMEMORY_H_

/* ************************************************************ */
// ���ܣ������ڡ� buffer ��ָ�������ġ� count �����ַ����ַ�������ҡ� ch ��
// �״γ��ֵ�λ�á�����һ��ָ�룬ָ�� ch �����ַ������״γ��ֵ�λ�ã�
// ����� ch ��û�����ַ������ҵ������ء� NULL ����
__declspec (dllexport) void* const XYTMemChr(void const* const buffer, int ch, size_t count);

/* ************************************************************ */
// ���ܣ������Ƚϡ� buf1 ���͡� buf2 ����ǰ�� count �����ַ���
// ����ֵ�����㣺�� buf1 >  buf2 ��
// ����ֵ�����㣺�� buf1 == buf2 ��
// ����ֵС���㣺�� buf1 <  buf2 ��
__declspec (dllexport) int XYTMemCmp(void const* const buf1, void const* const buf2, size_t count);

/* ************************************************************ */
// ���ܣ������ӡ� from ���и��ơ� count �����ַ����� to ���У�
// �����ء� to ��ָ�롣 �����to ���͡� from ���ص���������ΪҲȷ����
__declspec (dllexport) void* const XYTMemCpy(void* const to, void const* const from, size_t count);

/* ************************************************************ */
// ����: �롾 mencpy ����ͬ����ͬ���ǵ��� to ���͡� from ���ص��������������ܹ�����
__declspec (dllexport) void* const XYTMemMove(void* const to, void const* const from, size_t count);

/* ************************************************************ */
// ����: ���������� ch ������ buffer ����ͷ��ʼ�ġ� count �����ַ��
// �����ء� buffer ��ָ�룬����Ӧ���ڽ�һ���ڴ��ʼ��Ϊĳ��ֵ��
__declspec (dllexport) void* const XYTMemSet(void* const buffer, int ch, size_t count);

#endif // !XYTMEMORY_H_

