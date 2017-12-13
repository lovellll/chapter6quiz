// chapter6quiz.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

struct Student
{
	std::string name;
	int			score;

};

void sortAndPrint(Student *ptr,int length)
{
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int biggestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if ((ptr+currentIndex)->score > (ptr + biggestIndex)->score )
				biggestIndex = currentIndex;
		}
		std::swap(*(ptr+startIndex), *(ptr+biggestIndex));
	}


	for (int i = 0; i < length; ++i)
	{
		std::cout << (ptr + i)->name << " got a grade of " << (ptr + i)->score<<"\n";

		
	}
}

void getStudent(Student *ptr,int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << "Please input a student name \n";
		std::getline(std::cin, (ptr + i)->name );
		std::cout << "Please input the student's score \n";
		std::cin >> (ptr + i)->score;
		std::cin.ignore(32767, '\n');
	}
	
}




int main()
{
	std::cout << "please input the number of students\n";
	int numberOfStudent;
	std::cin >> numberOfStudent;
	std::cin.ignore(32767, '\n');

	Student *ptr = new Student[numberOfStudent];
	getStudent(ptr, numberOfStudent);

	sortAndPrint(ptr, numberOfStudent);

	delete[] ptr;
	ptr = nullptr;

    return 0;
}

