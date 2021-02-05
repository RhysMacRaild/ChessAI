#include "matrix.h";
#include <stdio.h>;
Matrix::Matrix(float** arr, int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->arr = arr;
}

Matrix::Matrix(int rows, int cols){
	this->rows = rows;
	this->cols = cols;
	this->arr = new float* [rows];
	for (int i = 0; i < rows; i++) {
		this->arr[i] = new float[cols];
	}
}

Matrix::Matrix(Matrix* existingMat) {
	this->rows = existingMat->rows;
	this->cols = existingMat->cols;
	this->arr = new float* [rows];
	for (int row = 0; row < this->getRows(); row++) {
		this->arr[row] = new float[cols];
	}
	for (int row = 0; row < this->getRows(); row++) {
		for (int col = 0; col < this->getCols(); col++) {
			this->arr[row][col] = existingMat->arr[row][col];
		}
	}
}

Matrix::Matrix() {
	this->rows = 0;
	this->cols = 0;
	this->arr = 0;
}

void Matrix::setMatrixDims(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->arr = new float *[rows];
	for (int i = 0; i < rows; i++) {
		this->arr[i] = new float[cols];
	}
}

void Matrix::flatten() {
	int size = rows * cols;
	int index = 0;
	Matrix* flattened = new Matrix(1, size);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			index = (cols * i) + j;
			flattened->arr[0][index] = this->arr[i][j];
		}
	}
	this->setMatrixDims(1, size);
	for (int i = 0; i < size; i++) {
		this->arr[0][i] = flattened->arr[0][i];
	}
}

void Matrix::unFlatten(int rows, int cols) {
	Matrix* unFlattened = new Matrix(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			unFlattened->arr[i][j] = this->arr[0][(i*cols)+j];
		}
	}

	this->setMatrixDims(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			this->arr[i][j] = unFlattened->arr[i][j] ;
		}
	}
}

int Matrix::getCols() {
	return this->cols;
}

int Matrix::getRows() {
	return this->rows;
}


void Matrix::printMatrix() {
	for (int row = 0; row < this->getRows(); row++) {
		for (int col = 0; col < this->getCols(); col++) {
			printf("%f\t", this->arr[row][col]);
		}
		printf("\n");
	}
	printf("\n");
}