#include "converter.h"

std::string Converter::UnicodeToANSI(const std::wstring& src)
{
	std::string dst;
	int len = WideCharToMultiByte(CP_ACP, 0, src.c_str(), -1, NULL, 0, NULL, NULL);			// 获取转换后的长度（包括结尾 \0）
	dst.resize(len);																		// 调整 dst 容量
	WideCharToMultiByte(CP_ACP, 0, src.c_str(), -1, &dst[0], (int)dst.size(), NULL, NULL);	// 转换
	return dst;
}