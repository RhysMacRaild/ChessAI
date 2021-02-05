#pragma once
class Matrix {
	int rows;
	int cols;

public:
	float** arr;
	Matrix(float** arr, int rows, int cols);
	Matrix(int rows, int cols);
	Matrix(Matrix* matrix);
	Matrix();
	void setMatrixDims(int rows, int cols);
	int getCols();
	int getRows();
	void printMatrix();
	void flatten();
	void unFlatten(int rows, int cols);

};