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
	void setMatrix(int rows, int cols);
	void setMatrixDims(int rows, int cols);
	int getCols();
	int getRows();
	void printMatrix();

};