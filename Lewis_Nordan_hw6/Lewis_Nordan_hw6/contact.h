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
	//file size checker
	int checkSize(string fileName);
	void resize(int change);

public:
	contact();
	~contact();

	
	//setter
	void setData(string fileName);
	//getters
	void getAll();
	vector<string> getFound(vector<int> locations);
	//find
	vector<int> search(int colum, string get);
	//delete
	void deleteContact(vector<int> locations);
	//add new
	void addNew(string Ncontact);
	//sort the data
	void sortall();
};

