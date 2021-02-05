#include "swishActivation.h";
#include <math.h>;

void Swish::calculate(Matrix* input, Matrix* output) {
    Matrix* denominator = new Matrix(input->getRows(), input->getCols());
    comp->matExponential(input, false, denominator);
    comp->matScalarAdd(denominator, 1.0f, denominator);
    comp->matDivision(input, denominator, output);
}