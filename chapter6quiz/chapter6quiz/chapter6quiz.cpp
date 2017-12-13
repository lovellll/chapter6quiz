// chapter6quiz.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

}


int main()
{
	int x = 3, y = 4;
	std::cout << "origin: " << x << y << "\n";
	swap(x, y);
	std::cout << "then " << x << y << "\n";


    return 0;
}

