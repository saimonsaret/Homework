#include <iostream>
#include "matrix.h"
#include "quickSort.h"

using namespace std;

int main()
{
	cout << "Enter size of table\n";
	int size = 0;
	cin >> size;
	cout << "Enter your table\n";

	Matrix<int> *table = new Matrix<int>(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> table->matrix[i][j];

	sortColumns(table);

	cout << "Your array with columns, sorted by first elements:\n";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << table->matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete table;
}
