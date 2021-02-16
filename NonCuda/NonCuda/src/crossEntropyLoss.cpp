#include "lossFunction.h";
#include "computations.h";
float LossFunction::calculateLoss(float realValue, float predictedValue) {
	return -realValue * (1 / predictedValue) + (1 - realValue) * (1 / (1 - predictedValue));
}

//1,N Matrix
void LossFunction::calculateCost(Matrix* realValue, Matrix* predictedValue, float* output) {

}

void LossFunction::calculateDerivativePrediction(Matrix* realValue, Matrix* predictedValue, float* output) {
	int rows = realValue->getRows();
	Matrix* costVector = new Matrix(rows, 1);
	Matrix* tmp = new Matrix(predictedValue);
	Matrix* tmp2 = new Matrix(tmp);
	Computations::matScalarDivision(realValue, -1.f, costVector);
	Computations::vectorInverse(predictedValue, tmp);
	Computations::vectorMult(costVector, tmp, costVector);
	Computations::subtractVector(realValue, 1, tmp);
	Computations::subtractVector(predictedValue, 1, tmp2);
	Computations::vectorInverse(tmp2, tmp2);
	Computations::vectorMult(tmp, tmp2, tmp);
	Computations::matAdd(costVector, tmp, costVector);
	output = (Computations::sumVector(costVector));
	*output = *output / (float)rows;
}