// Lewis_Nordan_hw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "contact.h"
using namespace std;

int main()
{
	contact list;
	list.setData("FakeNames.csv");
	list.getAll();
	list.search(2, "Dr.");

	system("pause");
	return 0;
}
