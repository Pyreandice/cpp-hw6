#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class contact
{
private:
	const int columNum = 12;
	int fileSize;
	string** data = new string *[columNum];

public:
	contact();
	~contact();

	//file size checker
	int checkSize(string fileName);

	//setter
	void setData(string fileName);
	//getters
	void getAll();
	void getFound(vector<int> locations);
	//sort into alphabetical order
	void search(int colum, string get);
};

