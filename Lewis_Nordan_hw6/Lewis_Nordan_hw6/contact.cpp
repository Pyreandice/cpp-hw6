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

void contact::resize(int change)
{
	string ** temp = new string * [columNum];
	for (int x = 0; x < columNum; x++) {
		temp[x] = new string[(fileSize + change)];
	}
	int counter = 0;
	bool test = true;

	// coppy all the data into a temp holder removing any lines marked for deletion
	for (int x = 0; x < (fileSize + change); x++) {
		for (int y = 0; y < columNum; y++) {
			if (data[y][counter] != "N/A") {
				if (counter >= fileSize) {
					counter = -1;
					break;
				}
				temp[y][x] = data[y][counter];
				test = true;
			}
			else {
				test = false;
				break;
			}
		}
		counter++;
		if (counter == -1) {
			break;
		}
		else if (test == false) {
			x--;
		}
	}
	//update the size of the file
	fileSize = fileSize + change;
	// reallocate the memory to fit the data properly and replace the data
	for (int x = 0; x < columNum; x++) {
		delete[] data[x];
		data[x] = new string[fileSize];
		data[x] = temp[x];
	}
	// deallocate the holder
	delete[] temp;
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
		
		getline(myFile, line);
		istringstream s(line);
		int x = 0;
		while (getline(s, dataPoint, ',')) {
			data[x][y] = dataPoint;
			x++;
		}
	}
	myFile.close();
}

void contact::getAll()
{
	ofstream outFile;
	outFile.open("fuck this shit.csv");
	for (int y = 0; y < fileSize; y++) {
		for (int x = 0; x < columNum; x++) {
			if (x < columNum-1) {
				if (data[x][y] != "N/A") {
					outFile << data[x][y] << ",";
				}
			}
			else if (x == columNum-1) {
				if (data[x][y] != "N/A") {
					outFile << data[x][y];
				}
			}
		}
		if (data[columNum-1][y] != "N/A") {
			outFile << endl;
		}
	}
	outFile.close();
}

vector<string> contact::getFound(vector<int> locations)
{
	vector<string> results;
	string glue = "";
	for (int x = 0; x < locations.size(); x++) {
		for (int y = 0; y < columNum; y++) {
			
			if (y < columNum - 1) {
				glue += data[y][locations[x]] +", ";
			}
			else if (y == columNum - 1) {
				glue+= data[y][locations[x]];
			}
		}
		results.push_back(glue);
		glue = "";
	}
	return results;
}

vector<int> contact::search(int colum, string get)
{
	vector<int> rows;
	for (int x = 0; x < fileSize; x++) {
		if (data[colum][x] == get) {
			rows.push_back(x);
		}
	}
	//getFound(rows);
	return rows;
}

void contact::deleteContact(vector<int> locations)
{
	int numDeleted = 0;
	for (int y = 0; y < locations.size(); y++) {
		for (int x = 0; x < columNum; x++) {
			data[x][y].replace(0,data[x][y].length(),"N/A");
		}
		numDeleted--;
	}
	resize(numDeleted);
	cout << abs(numDeleted) << " contacts deleted." << endl;
}

 void contact::addNew(string Ncontact){
	cout << "making room" << endl;
	resize(1);
	
	for (int x = 0; x < fileSize; x++) {
		cout << data[0][x] << "--" << endl;;
	}
	cout << "new size = " << fileSize << endl;
	string temp = "";
	istringstream s(Ncontact);
	for (int x = 0; x < columNum; x++) {
		getline(s, temp, ',');
		data[x][(fileSize - 1)] = temp;
	}
}

 void contact::sortall()
 {
 }

