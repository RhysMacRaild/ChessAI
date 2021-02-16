#include "computations.h";
#include "Matrix.h";
#include <math.h>;

void Computations::vectorInverse(Matrix* input, Matrix* output){
	for (int i = 0; i < input->getRows(); i++) {
		output->arr[i][0] = 1 / input->arr[i][0];
	}
}

void Computations::vectorDevision(Matrix* numerator, Matrix* devisor, Matrix* output) {
	for (int i = 0; i < numerator->getRows(); i++) {
		output->arr[i][0] = numerator->arr[i][0] / devisor->arr[i][0];
	}
}

void Computations::matMult(Matrix* inputA, Matrix* inputB, Matrix* output) {
	float tmp = 0;
	for (int i = 0; i < inputA->getRows(); i++) {
		for (int j = 0; j < inputB->getCols(); j++) {
			for (int k = 0; k < inputA->getRows(); k++) {
				tmp += inputA->arr[i][k] * inputB->arr[k][j];
			}
			output->arr[i][j] = tmp;
			tmp = 0;
		}
	}
}

void Computations::matScalarDivision(Matrix* input, float scalar, Matrix* output) {
	for (int i = 0; i < input->getRows(); i++) {
		for (int j = 0; j < input->getCols(); j++) {
			output->arr[i][j] = (input->arr[i][j] / scalar);
		}
	}
}

void Computations::matExponential(Matrix* input, bool positive, Matrix* output) {
	float sign = -1.0;
	if (positive) {
		sign = 1.0;
	}

	for (int i = 0; i < input->getRows(); i++) {
		for (int j = 0; j < input->getCols(); j++) {
			output->arr[i][j] = expf(sign*input->arr[i][j]);
		}
	}
}

void Computations::matAdd(Matrix* inputA, Matrix* inputB, Matrix* output) {
	for (int i = 0; i < inputA->getRows(); i++) {
		for (int j = 0; j < inputA->getCols(); j++) {
			output->arr[i][j] = inputA->arr[i][j] + inputB->arr[i][j];
		}
	}
}

	void Computations::matDivision(Matrix* numerator, Matrix* denominator, Matrix * output) {
		for (int i = 0; i < numerator->getRows(); i++) {
			for (int j = 0; j < numerator->getCols(); j++) {
				output->arr[i][j] = numerator->arr[i][j] / denominator->arr[i][j];
			}
		}
	}

	void Computations::matScalarAdd(Matrix* inputA, float scalar, Matrix* output) {
		for (int i = 0; i < inputA->getRows(); i++) {
			for (int j = 0; j < inputA->getCols(); j++) {
				output->arr[i][j] = inputA->arr[i][j] + scalar;
			}
		}
	}

	void Computations::subtractVector(Matrix* input, float valueToSubtractFrom, Matrix* output) {
		for (int i = 0; i < input->getRows(); i++) {
			output->arr[i][0] = valueToSubtractFrom - input->arr[i][0];
		}
	}