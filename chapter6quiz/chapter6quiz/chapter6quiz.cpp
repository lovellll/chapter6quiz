// chapter6quiz.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

enum class Item
{
	POTION,
	TORCHE,
	ARROW,
	MAXITEMS,
};

int countTotalItems(int array[])
{
	int count = 0;
	for (int i = 0; i < static_cast<int>(Item::MAXITEMS); ++i)
	{
		count += array[i];
	}
	return count;
}

int main()
{
	int array[static_cast<int>(Item::MAXITEMS)]{ 2,5,10 };
	int sum = countTotalItems(array);
	std::cout << "sum of items is " << sum << "\n";


    return 0;
}

