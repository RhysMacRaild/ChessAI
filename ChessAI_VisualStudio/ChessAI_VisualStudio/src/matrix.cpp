#include "matrix.h";
Matrix::Matrix(float** arr, int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->arr = arr;
}

int Matrix::getCols() {
	return this->cols;
}

int Matrix::getRows() {
	return this->rows;
}