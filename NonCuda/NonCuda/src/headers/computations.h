#pragma once
#include "matrix.h"
class Computations {
public:
	static void matMult(Matrix* inputA, Matrix* inputB, Matrix* output);
	static void matAdd(Matrix* inputA, Matrix* inputB, Matrix* output);
	static void matDivision(Matrix* numerator, Matrix* denominator, Matrix* output);
	static void matExponential(Matrix* input, bool posistive, Matrix* output);
	static void matScalarDivision(Matrix* input, float scalar, Matrix* output);
	static void matScalarAdd(Matrix* input, float scalar, Matrix* output);
	static void vectorMult(Matrix* inputA, Matrix* inputB, Matrix* output);
	static void subtractVector(Matrix* input, float valueToSubtractFrom, Matrix* output);
	static void vectorDevision(Matrix* numerator, Matrix* devisor, Matrix* ouput);
	static void vectorInverse(Matrix* input, Matrix* output);
	static void logVector(Matrix* input, Matrix* output);
	static float* sumVector(Matrix* input);
};