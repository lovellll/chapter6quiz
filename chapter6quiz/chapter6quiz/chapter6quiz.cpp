// chapter6quiz.cpp : �������̨Ӧ�ó������ڵ㡣
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

