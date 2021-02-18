#pragma once
#include <matrix.h>

class Activation {
public:
	virtual void calculate(Matrix* input, Matrix* output) = 0;
	virtual void calculateDerivateWithRespectToInput(Matrix* input, Matrix* ouput) = 0;
};