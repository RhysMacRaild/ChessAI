#pragma once
#include "matrix.h"
class Computations {
public:
	void matMult(Matrix* inputA, Matrix* inputB, Matrix* output);
	void matAdd(Matrix* inputA, Matrix* inputB, Matrix* output);
	void matDivision(Matrix* numerator, Matrix* denominator, Matrix* output);
	void matExponential(Matrix* input, bool posistive, Matrix* output);
	void matScalarDivision(Matrix* input, float scalar, Matrix* output);
	void matScalarAdd(Matrix* input, float scalar, Matrix* output);
};