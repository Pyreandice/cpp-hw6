#include "pch.h"
#include "contact.h"


contact::contact()
{
	fileSize = 0;
}


contact::~contact()
{
	delete data;
}

int contact::checkSize(string fileName)
{
	int lineNum = 0;
	string line;
	ifstream myfile;
	myfile.open(fileName);
	while (getline(myfile, line)) {
		lineNum++;
		//cout << line << endl;
	}
	

	myfile.close();
	cout << "Number of lines in text file: " << lineNum << endl;
	return lineNum;
}
/*
the first index value is the location of each type of data.(given name, surname, DOB, etc)
the second number indicates the persons place in the list
*/
void contact::setData(string fileName)
{
	string dataPoint = "";
	string line = "";
	fileSize = checkSize(fileName);
	try {
		for (int x = 0; x < columNum; x++) {
			data[x] = new string[fileSize];
		}
	}
	catch (exception ex) {
		cout << "we encountered a problem, there was a " << ex.what() << endl;
		system("pause");
	}
	ifstream myFile;
	myFile.open(fileName);
	for (int y = 0; y < fileSize; y++) {
		//cout << "currently on row number: " << y << " of " << fileSize << endl;
		getline(myFile, line);
		istringstream s(line);
		int x = 0;
		while (getline(s, dataPoint, ',')) {
			data[x][y] = dataPoint;
			//cout << data[x][y];
			x++;
		}
		//cout << endl;
	}
	myFile.close();
}
void contact::getAll()
{
	ofstream outFile;
	outFile.open("fuck this shit.csv");
	for (int y = 0; y < fileSize; y++) {
		for (int x = 0; x < columNum; x++) {
			//cout << data[x][y];
			if (x < columNum-1) {
				outFile << data[x][y]<<",";
			}
			else if (x == columNum-1) {
				outFile << data[x][y];
			}
			//cout << "(" << x << " , " << y << ") ";
		}
		//cout << endl;
		outFile << endl;
	}
	outFile.close();
}

void contact::getFound(vector<int> locations)
{
	for (int x = 0; x < locations.size(); x++) {
		for (int y = 0; y < columNum; y++) {
			
			if (y < columNum - 1) {
				cout << data[y][locations[x]]<<", ";
			}
			else if (y == columNum - 1) {
				cout << data[y][locations[x]];
			}
		}
		cout << endl;
	}
	cout << "there are " << locations.size() << " results." << endl;
}

void contact::search(int colum, string get)
{
	vector<int> rows;
	for (int x = 0; x < fileSize; x++) {
		if (data[colum][x] == get) {
			rows.push_back(x);
		}
	}
	getFound(rows);
}

