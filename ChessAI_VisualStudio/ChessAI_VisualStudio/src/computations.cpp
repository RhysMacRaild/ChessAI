#include "computations.h";
#include "Matrix.h";

void Computations::matMult(Matrix* inputA, Matrix* inputB, Matrix* output) {
	int outputSize = inputA->getRows() * inputB->getCols();
	float tmp = 0;
	for (int i = 0; i < inputA->getRows(); i++) {
		for (int j = 0; j < inputB->getCols(); j++) {
			for (int k = 0; k < outputSize; k++) {
				tmp += inputA->arr[i][k] * inputB->arr[k][j];
			}
			output->arr[i][j] = tmp;
			tmp = 0;
		}
	}
}