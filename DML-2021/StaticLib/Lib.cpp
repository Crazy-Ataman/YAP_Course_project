#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <ctime>

extern "C"
{
	char* Date()
	{
		const time_t tm = time(nullptr);
		char buf[64];
		strftime(buf, std::size(buf), "%d.%m.%Y", localtime(&tm));
		return buf;
	}

	char* Time()
	{
		const time_t tm = time(nullptr);
		char buf[64];
		strftime(buf, std::size(buf), "%H:%M:%S", localtime(&tm));
		return buf;
	}

	void OutputInt(unsigned int a) {
		std::cout << a << std::endl;
	}

	void OutputStr(char* ptr) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (ptr == nullptr) {
			std::cout << '\n';
			return;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];

		std::cout << '\n';
	}
}
