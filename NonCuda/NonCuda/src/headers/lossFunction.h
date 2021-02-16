#pragma once
#include "matrix.h"
class LossFunction {
public:
	virtual float calculateLoss(float realValue, float predictedValue) = 0;
	virtual void calculateCost(Matrix* realVaules, Matrix* predictedValues, float* output) = 0;
	virtual void calculateDerivativeBias() = 0;
	virtual void calculateDerivativeWeights() = 0;
	virtual void calculateDerivativePrediction(Matrix* realValue, Matrix* predictedValue, float* output) = 0;
};
