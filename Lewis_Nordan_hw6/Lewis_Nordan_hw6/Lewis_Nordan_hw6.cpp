// Lewis_Nordan_hw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "contact.h"
using namespace std;
//works

struct pointsOfInterest {
	vector<int> locals;
	contact list;
	int colum = 0;
	string find = "";
};

string getNewData(pointsOfInterest info) {
	string data = "";
	string temp = "";
	const string fields[12] = { "Number","Gender","Title","GivenName","MiddleInitial","Surname","StreetAddress"
		,"City","State","ZipCode","EmailAddress","Birthday" };
	for (int x = 0; x < 12; x++) {
		cout << "please enter " << fields[x];
		getline(cin, temp);
		if (x != 11) {
			data += temp + ",";
		}
		else {
			data += temp;
		}
	}
	info.find = data;
	return data;
}
//create a way to validate the data

string getSearchRequest(pointsOfInterest info) {
	string find = "";

	return find;
}
void printResults(pointsOfInterest info) {
	vector<string> results;
	results = info.list.getFound(info.locals);
	for (int x = 0; x < results.size(); x++) {
		cout << results[x] << endl;
	}
}
void deleteData(pointsOfInterest info) {
	info.list.deleteContact(info.locals);
}
void daddy(pointsOfInterest info) {

}
int main()
{
	pointsOfInterest info;
	string con = "";
	info.list.setData("FakeNames.csv");
	info.list.addNew(getNewData(info));
	info.list.search(0, getSearchRequest(info));
	deleteData(info);
	cout << info.colum << ", " << info.find << endl;
	info.list.getAll();


	system("pause");
	return 0;
}