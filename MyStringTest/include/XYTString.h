#ifndef XYTSTRING_H_
#define XYTSTRING_H_

/* ************************************************************ */
// ���ܣ��������ַ����� from �����ӵ��� to ����ĩ�ˣ�������ָ�롾 to ����
__declspec (dllexport) char* const XYTStrCat(char* const to, char const* const from);

/* ************************************************************ */
// ���ܣ����ַ����� from �������ࡾ count �����ַ����ӵ��ַ����� to ���У�
// ׷�ӿ�ֵ�����������ش�����ɵ��ַ�����
__declspec (dllexport) char* const XYTStrNCat(char* const to, char const* const from, size_t count);

/* ************************************************************ */
// ���ܣ���������һ��ָ�� str ���С� ch ���״γ��ֵ�λ�ã�
// ��û���ڡ� str �����ҡ� ch �������ء� NULL ����
__declspec (dllexport) char* const XYTStrChr(char const* const str, int ch);

/* ************************************************************ */
// ���ܣ���������һ��ָ�룬��ָ���ַ��� ch �����ַ����� str ��ĩ�γ��ֵ�λ�ã�
// ���ƥ��ʧ�ܣ����ء� NULL ����
__declspec (dllexport) char* const XYTStrRChr(char const* const str, int ch);

/* ************************************************************ */
// �Ƚ��ַ����� str1 and str2 ��
// ����ֵ�����㣺�� str1 >  str2 ��
// ����ֵ�����㣺�� str1 == str2 ��
// ����ֵС���㣺�� str1 <  str2 ��
__declspec (dllexport) int XYTStrCmp(char const* const str1, char const* const str2);

/* ************************************************************ */
// �Ƚ��ַ����� str1 and str2 �������١� count �����ַ�
// ����ֵ�����㣺�� str1 >  str2 ��
// ����ֵ�����㣺�� str1 == str2 ��
// ����ֵС���㣺�� str1 <  str2 ��
__declspec (dllexport) int XYTStrNCmp(char const* const str1, char const* const str2, size_t count);

/* ************************************************************ */
// ��֪����ôд
__declspec (dllexport) void XYTStrColl();

/* ************************************************************ */
// ���ܣ������ַ����� from ���е��ַ����ַ����� to ����
// ������ֵ������������ֵΪָ�롾 to ����
__declspec (dllexport) char* const XYTStrCpy(char* const to, char const* const from);

/* ************************************************************ */
// ���ܣ����ַ����� from �������ࡾ count �����ַ����Ƶ��ַ����� to ���У�
// ����ַ����� from ���ĳ���С�ڡ� count �������ಿ���á� '\0' �����
// ���ش�����ɵ��ַ�����
__declspec (dllexport) char* const XYTStrNCpy(char* const to, char const* const from, size_t count);

/* ************************************************************ */
// ���ܣ����������ַ����� str ���е�һ�����������ַ����� strCharSet �����ַ���������
__declspec (dllexport) size_t XYTStrSpn(char const* const str, char const* const strCharSet);

/* ************************************************************ */
// ���ܣ��������ء� str ����ͷ������ n �����ַ��������ַ����� strCharSet �����ַ����ַ�����
__declspec (dllexport) size_t XYTStrCSpn(char const* const str, char const* const strCharSet);

/* ************************************************************ */
// ���ܣ����������ַ����� str ���ĳ���( ����ֵ������֮ǰ�ַ���Ŀ)��
__declspec (dllexport) size_t XYTStrLen(char const* const str);

/* ************************************************************ */
// ���ܣ���������һ��ָ�룬��ָ���ַ����� str ���������ַ����ַ����� strCharSet ����
// �״γ��ֵ�λ�ã���������ڷ��ء� NULL ����
__declspec (dllexport) char const* const XYTStrPbrk(char const* const str, char const* const strCharSet);

/* ************************************************************ */
// ���ܣ���������һ��ָ�룬��ָ���ַ����� str2 ���״γ������ַ����� str1 ���е�λ�ã�
// ���û���ҵ������ء� NULL ����
__declspec (dllexport) char const* const  XYTStrStr(char const* const str, char const* const strCharSet);

#endif // !XYTSTRING_H_

