// chapter6quiz.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

void pirintCstring(char *ptr)
{
	do
	{
		std::cout << *ptr;
	} while (*(++ptr) != '\0');
	std::cout << "\n";

	
}


int main()
{
	char string[]{ "Hello, world!" };
	pirintCstring(string);

    return 0;
}

