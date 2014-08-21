// Santos Solorzano
// CSCE 206-301
// A4/8.11

// This program uses a file containing names
// and reads them in as strings; it then sorts
// and displays the array of names in 
// alphabetical order

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// function prototypes
void getNames(string, vector<string>);
void selectionSort(int, vector<string>);

int main()
{
	vector<string> unsortedNames; // empty vector of strings initialized
	string filename; // string variable needed to specify file name that we open

	// user inputs the name of the file
	cout << "Enter the name of the file: ";
	cin >> filename;

	// function call to retrieve names from our file
	getNames(filename, unsortedNames);

	return 0;
}

// function that reads in the names from our file
void getNames(string filename, vector<string> names)
{
	string name; // string variable required to read lines from our file

	// ifstream object created to read data from a file
	ifstream inputFile;

	// opens the file with the file name specified by the user
	inputFile.open(filename.c_str());

	// reads in the names from the file into our vector
	while(getline(inputFile, name))
	{
		names.push_back(name); // pushes each individual name onto our vector
	}

	cout << "Here are the unsorted names:" << endl;
	cout << "----------------------------" << endl;
	cout << " " << endl; // formatting

	// for loop to display our unsorted array
	for (int count = 0; count < names.size(); count++)
		cout << names[count] << "\n";

	// closes the file
	inputFile.close();

	cout << " " << endl; // formatting

	// function call to sort and display the 'names' array
	selectionSort(names.size(), names);
}

// function that sorts the names in alphabetical order
void selectionSort(int size, vector<string> vect)
{
	int startScan, minIndex;
	string minValue;
    
    // for loop that sorts 'names' array in ascending order; 
	// after making a pass and setting the smallest value in 
	// the first element, it starts at the second element and 
	// continues the procedure, making one less pass each time
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = vect[startScan];
        
        for (int index = startScan + 1; index < size; index++)
        {
            if (vect[index] < minValue)
            {
                minValue = vect[index];
                minIndex = index;
            }
        }
        vect[minIndex] = vect[startScan];
        vect[startScan] = minValue;
    }

	cout << "Here are the sorted names:" << endl;
	cout << "--------------------------" << endl;
	cout << " " << endl; // formatting

	// displays sorted names
	for (int count = 0; count < size; count++)
		cout << vect[count] << endl;
}