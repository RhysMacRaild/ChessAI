#include "fullyConnectedLayer.h";

void FullyConnectedLayer::forwardStep(Matrix* input) {
    calculateWeightsBias(input);
}

void FullyConnectedLayer::calculateWeightsBias(Matrix* input) {
    this->inputMatrix = new Matrix(input);
    comp->matMult(this->inputMatrix, weightsMatrix, outputMatrix);
    comp->matAdd(outputMatrix, biasMatrix, outputMatrix);
    this->calculateActivation();
}

void FullyConnectedLayer::calculateActivation() {
    activationFunc->calculate(outputMatrix, activatedOutputMatrix);
}