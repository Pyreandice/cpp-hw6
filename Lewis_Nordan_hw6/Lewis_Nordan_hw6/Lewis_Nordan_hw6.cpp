// Lewis_Nordan_hw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "contact.h"
using namespace std;
//works
int main()
{
	contact list;
	list.setData("FakeNames.csv");
	string con = "7000,male,Mr.,Lewis,E,Nordan,1008 West Bob Place #8,AR,72701,nordanlewis@gmail.com,3/13/1998";
	list.addNew(con);
	list.search(0, "7000");
	
	
	system("pause");
	return 0;
}