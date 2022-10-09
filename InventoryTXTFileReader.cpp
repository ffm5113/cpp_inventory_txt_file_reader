// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
// https://docs.microsoft.com/en-us/cpp/standard-library/iomanip-functions?view=msvc-170

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <cmath>    // To access power function for calculations
#include <string>   // To implement to_string function
#include <fstream>  // To utilize ifstream, ofstream, fstream
using namespace std;

// Constant Variable Initialization
const string TITLE = "Parts Inventory TXT File Reader";
const string AUTHOR_LINE = "By Forrest Moulin";
const string REPORT_HEADER = "Inventory Classication Report";
const string COUNT_STRING = "Unit Count: ";
const string VAL_STRING = "Inventory Value: ";

const int COL_WIDTH1 = 10;
const int COL_WIDTH2 = AUTHOR_LINE.size(), TOTAL_WIDTH = 50;
const int COL_WIDTH3 = 17, COL_GAP = 3;

int main()
{
  cout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	// Dynamic Variable Initialization
	int totalWidth;
	string headerUnderline = "-";
	
	int countA = 0, countB = 0, countC = 0, countD = 0, countE = 0, 
		countF = 0, minInt = 0, maxInt = 0;
	
	double inventoryValA = 0.0, inventoryValB = 0.0,
		inventoryValC = 0.0, inventoryValD = 0.0,
		inventoryValE = 0.0, inventoryValF = 0.0,
		minDub = 0.0, maxDub = 0.0;
	
	// Objects used during each while iteration
	string partNum;
	char partClass;
	int numUnits;
	double valuePerUnit, valueDub;
	
	// File path using \\ for each \ within the string
	string textFileStr = "C:\\Users\\PATH\\TO\\parts.txt";

	// Initialize ifstream object for reading file
	ifstream theFile;

	// Program Logic
	theFile.open(textFileStr);
	if (theFile.fail())
	{
		cout << "File open failure:" << endl
			<< textFileStr << endl;
		theFile.close();
		// End program in event of file loading failure
		return 0;
	}

	// While there are lines to read in the file,
	// read in values to variables
	while (theFile >> partNum >> partClass >> numUnits >> valuePerUnit)
	{
		// Calculate values for each part classification
		if (partClass == 'A')
		{
			countA += numUnits;
			valueDub = numUnits * valuePerUnit;
			inventoryValA += valueDub;
		}
		else if (partClass == 'B')
		{
			countB += numUnits;
			valueDub = numUnits * valuePerUnit;
			inventoryValB += valueDub;
		}
		else if (partClass == 'C')
		{
			countC += numUnits;
			valueDub = numUnits * valuePerUnit;
			inventoryValC += valueDub;
		}
		else if (partClass == 'D')
		{
			countD += numUnits;
			valueDub = numUnits * valuePerUnit;
			inventoryValD += valueDub;
		}
		else if (partClass == 'E')
		{
			countE += numUnits;
			valueDub = numUnits * valuePerUnit;
			inventoryValE += valueDub;
		}
		else if (partClass == 'F')
		{
			countF += numUnits;
			valueDub = numUnits * valuePerUnit;
			inventoryValF += valueDub;
		}
		
		// Keep track of largest double and largest int to format column widths
		if (valueDub < minDub)
		{
			minDub = valueDub;
		}
		if (valueDub > maxDub)
		{
			maxDub = valueDub;
		}

		if (to_string(countA).length() > to_string(maxInt).length())
		{
			maxInt = countA;
		}
		if (to_string(countB).length() > to_string(maxInt).length())
		{
			maxInt = countB;
		}
		if (to_string(countC).length() > to_string(maxInt).length())
		{
			maxInt = countC;
		}
		if (to_string(countD).length() > to_string(maxInt).length())
		{
			maxInt = countD;
		}
	}

    // Calculate total width of table to format output 
	totalWidth = COL_WIDTH1 + COUNT_STRING.size()
		+ to_string(maxInt).size() + VAL_STRING.size() + COL_GAP
		+ 1 + to_string(maxDub).size() - 3;
	for (int i = 0; i < totalWidth; i++)
	{
		headerUnderline += "-";
	}
	
	// Console table output 
	cout << right 
		<< setw((headerUnderline.length() - REPORT_HEADER.length()) 
			/ 2 + REPORT_HEADER.length()) << REPORT_HEADER
		<< left << setw((headerUnderline.length() - REPORT_HEADER.length())
			/ 2) << " " << endl << headerUnderline << endl
		
		<< left << setw(COL_WIDTH1) << "A Parts" << COUNT_STRING
		<< setw(to_string(maxInt).size()) << countA
		<< right << setw(VAL_STRING.size() + COL_GAP) << VAL_STRING 
		<< "$" << inventoryValA << endl
		
		<< left << setw(COL_WIDTH1) << "B Parts" << COUNT_STRING
		<< setw(to_string(maxInt).size()) << countB
		<< right << setw(VAL_STRING.size() + COL_GAP) << VAL_STRING 
		<< "$" << inventoryValB << endl
		
		<< left << setw(COL_WIDTH1) << "C Parts" << COUNT_STRING
		<< setw(to_string(maxInt).size()) << countC
		<< right << setw(VAL_STRING.size() + COL_GAP) << VAL_STRING 
		<< "$" << inventoryValC << endl
		
		<< left << setw(COL_WIDTH1) << "D Parts" << COUNT_STRING
		<< setw(to_string(maxInt).size()) << countD
		<< right << setw(VAL_STRING.size() + COL_GAP) << VAL_STRING 
		<< "$" << inventoryValD << endl 
		
		<< left << setw(COL_WIDTH1) << "E Parts" << COUNT_STRING
		<< setw(to_string(maxInt).size()) << countE
		<< right << setw(VAL_STRING.size() + COL_GAP) << VAL_STRING
		<< "$" << inventoryValE << endl
		
		<< left << setw(COL_WIDTH1) << "F Parts" << COUNT_STRING
		<< setw(to_string(maxInt).size()) << countF
		<< right << setw(VAL_STRING.size() + COL_GAP) << VAL_STRING
		<< "$" << inventoryValF << endl;
	theFile.close();
}
/*
* CONSOLE OUTPUT
* Parts Inventory TXT File Reader
* By Forrest Moulin
*
*              Inventory Classication Report
* --------------------------------------------------------
* A Parts   Unit Count: 2265   Inventory Value: $191180.07
* B Parts   Unit Count: 1744   Inventory Value: $74764.16
* C Parts   Unit Count: 2167   Inventory Value: $50322.30
* D Parts   Unit Count: 1448   Inventory Value: $22416.49
* E Parts   Unit Count: 137    Inventory Value: $3338.97
* F Parts   Unit Count: 137    Inventory Value: $943.71
*/
