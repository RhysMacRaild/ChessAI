#pragma once
#include <matrix.h>

class Activation {
public:
	virtual void calculate(Matrix* input, Matrix* output) = 0;
};