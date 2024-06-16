#include "converter.h"

std::string Converter::UnicodeToANSI(const std::wstring& src)
{
	std::string dst;
	int len = WideCharToMultiByte(CP_ACP, 0, src.c_str(), -1, NULL, 0, NULL, NULL);			// ��ȡת����ĳ��ȣ�������β \0��
	dst.resize(len);																		// ���� dst ����
	WideCharToMultiByte(CP_ACP, 0, src.c_str(), -1, &dst[0], (int)dst.size(), NULL, NULL);	// ת��
	return dst;
}