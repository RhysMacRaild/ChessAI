#pragma once
class Matrix {
	int rows;
	int cols;

public:
	float** arr;
	Matrix(float** arr, int rows, int cols);
	int getCols();
	int getRows();
};