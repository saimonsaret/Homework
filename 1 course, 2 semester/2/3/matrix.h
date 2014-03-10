#pragma once
#include <string.h>
#include <stdio.h>

///Template, which contains a matrix with necessary type
template<typename type>
class Matrix {
	public:
		Matrix(int size) {
			type **newMatrix = new type*[size];
			for (int i = 0; i < size; i++) {
				type *line = new type[size];
				newMatrix[i] = line;
				memset(newMatrix[i], 0, size * sizeof(type));
			}
			matrixSize = size;
			matrix = newMatrix;
		}
		~Matrix() {
			for (int i = 0; i < matrixSize; i++)
				delete[] matrix[i];
			delete[] matrix;
		}

		type **matrix;
		int matrixSize;
};
