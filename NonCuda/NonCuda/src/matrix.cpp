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