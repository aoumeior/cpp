#pragma once

#include <fstream>
#include "binarybuffer.h"
class binaryfstream : public std::fstream
{

  public:
	binaryfstream() : std::fstream() {}

	binaryfstream(const char *_Filename, ios_base::openmode _Mode = ios_base::in | ios_base::out, int _Prot = (int)ios_base::_Openprot)
		: std::fstream(_Filename, _Mode, _Prot) {}

	binaryfstream(const std::string &_Str, ios_base::openmode _Mode = ios_base::in | ios_base::out, int _Prot = (int)ios_base::_Openprot)
		: std::fstream(_Str, _Mode, _Prot) {}

	virtual ~binaryfstream() noexcept override {}

	template <typename T, typename... Args>
	binaryfstream &binarys(T t, Args... arg)
	{
		this->write(reinterpret_cast<const char *>(&t), sizeof(t));
		return binarys(arg...);
	}

	template <typename... Args>
	binaryfstream &binarys(const std::string &str, Args... arg)
	{

		this->write(reinterpret_cast<const char *>(str.c_str()), str.length());
		return binarys(arg...);
	}

	template <typename... Args>
	binaryfstream &binarys(const std::wstring &str, Args... arg)
	{

		this->write(reinterpret_cast<const char *>(str.c_str()), str.length() * sizeof(wchar_t));
		return binarys(arg...);
	}

	//end
	template <typename T>
	binaryfstream &binarys(T arg)
	{

		this->write(reinterpret_cast<const char *>(&arg), sizeof(arg));
		return *this;
	}
	template <>
	binaryfstream &binarys<>(const std::string &str)
	{

		this->write(reinterpret_cast<const char *>(str.c_str()), str.length());
		return *this;
	}

	template <>
	binaryfstream &binarys<>(const std::wstring &str)
	{

		this->write(reinterpret_cast<const char *>(str.c_str()), str.length() * sizeof(wchar_t));
		return *this;
	}
};
