#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
#include "hashtable.h"
#include "testHashtable.h"

const int defaultMaxHash = 1003;
const int defaultHashBase = 31;
const char enter = 10;

enum queries {
	none = -1,
	quit = 0,
	addValue = 1,
	deleteValue = 2,
	findValue = 3,
	showStats = 4,
	chooseHashFunction = 5,
	help = 6
};

using namespace std;

const int maxLength = 1000;

bool exists(const char *filename)
{
	return ifstream(filename) != nullptr;
}

bool isLetter(char symbol) {
	return ((symbol >= 'a') && (symbol <= 'z')) || ((symbol >= 'A') && (symbol <= 'Z'));
}

void deleteEnter(char *line) {
	int lineLength = strlen(line);
	if (line[lineLength - 1] == enter)
		line[lineLength - 1] = 0;
}

void printHelp() {
	cout << "Command list:\n";
	cout << "Type 1 to add a value to the hashtable\n";
	cout << "Type 2 to delete a value from the hashtable\n";
	cout << "Type 3 to find out if there is such value in the hashtable\n";
	cout << "Type 4 to show the hashtable's statistics\n";
	cout << "Type 5 to choose hash function\n";
	cout << "Type 6 to print help\n";
	cout << "Type 0 to quit\n";
}


int main() {

	TestHashTable test;
	QTest::qExec(&test);

	HashTable *table = new HashTable(defaultMaxHash, defaultHashBase);
	printHelp();

	char *line = new char[maxLength];
	memset(line, 0, maxLength * sizeof(char));

	int state = none;
	char tempString[maxLength];

	while (state != quit) {

		cout << "Enter your command\n";
		cin >> state;
		fgets(tempString, maxLength, stdin);

		switch (state) {
			case quit:
				break;
			case addValue: {
				cout << "Enter your value\n";
				fgets(line, maxLength, stdin);
				deleteEnter(line);
				ExpandingString *newString = ExpandingString::conversionToExpandingString(line);
				table->addToHashTable(newString);
				cout << "Your data was successfully added\n";
				break;
			}
			case deleteValue: {
				cout << "Enter your value\n";
				fgets(line, maxLength, stdin);
				deleteEnter(line);
				ExpandingString *newString = ExpandingString::conversionToExpandingString(line);
				bool flag = table->deleteFromHashTable(newString);
				if (flag)
					cout << "Your value was successfully deleted\n";
				else
					cout << "There is no such value in the hashtable\n";
				delete newString;
				break;
			}
			case findValue: {
				cout << "Enter your value\n";
				fgets(line, maxLength, stdin);
				deleteEnter(line);
				ExpandingString *newString = ExpandingString::conversionToExpandingString(line);
				if (table->findPrevInHashTable(newString) != nullptr)
					cout << "There is such valie in the hashtable\n";
				else
					cout << "There is no such value in the hashtable\n";
				delete newString;
				break;
			}
			case showStats: {
				table->printStatistics();
				break;
			}
			case chooseHashFunction: {
				cout << "Enter hash module and hash base of new hashtable (natural numbers no more than 10000)\n";
				HashFunction newFunction(0, 0);
				cin >> newFunction.maxHash >> newFunction.hashBase;
				while ((newFunction.maxHash < 1 || newFunction.maxHash > 10000)
					|| (newFunction.hashBase < 1 || newFunction.hashBase > 10000)) {
						cout << "Your numbers are not acceptable. Enter new ones\n";
						cin >> newFunction.maxHash >> newFunction.hashBase;
				}
				table->remakeTable(newFunction);
				break;
			}
			case help: {
				printHelp();
				break;
			}
		}


	}

	delete table;
	delete[] line;

	return 0;
}
