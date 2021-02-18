#pragma once
#include "activationFunction.h";
#include "computations.h";
class Swish :public Activation {

public:
	Computations* comp = new Computations();
	void Activation::calculate(Matrix* input, Matrix* output);
	void Activation::calculateDerivateWithRespectToInput(Matrix* input, Matrix* output);
};