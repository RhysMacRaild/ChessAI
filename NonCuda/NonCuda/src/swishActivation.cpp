#include "swishActivation.h";
#include <math.h>;

void Swish::calculate(Matrix* input, Matrix* output) {
    Matrix* denominator = new Matrix(input->getRows(), input->getCols());
    comp->matExponential(input, false, denominator);
    comp->matScalarAdd(denominator, 1.0f, denominator);
    comp->matDivision(input, denominator, output);
}

void Swish::calculateDerivateWithRespectToInput(Matrix* input, Matrix* output) {
    Matrix* tmp = new Matrix(input);
    Matrix* tmp2 = new Matrix(input);
    Matrix* exp = new Matrix(input);

    Computations::matExponential(input, true, exp);
    Computations::matAdd(input, exp, tmp);
    Computations::matScalarAdd(tmp, 1.f, tmp);
    Computations::vectorMult(exp, tmp, tmp);

    Computations::matScalarAdd(exp, 1.f, tmp2);
    Computations::vectorMult(tmp2, tmp2, tmp2);

    Computations::vectorDevision(tmp, tmp2, output);
}