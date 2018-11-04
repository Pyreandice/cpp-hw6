#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class contact
{
private:
	//Number
	//Gender
	//Title
	//GivenName
	//MiddleInitial
	//Surname
	//StreetAddress
	//City
	//State
	//ZipCode
	//EmailAddress
	//Birthday

public:
	contact();
	~contact();

	//setter
	//getter
	//search
		//Number
		//Gender
		//Title
	//GivenName
	string firstName();
		//MiddleInitial
	//Surname
	string lastName();
		//StreetAddress
	//City
	string city();
		//State
		//ZipCode
		//EmailAddress
		//Birthday

};

