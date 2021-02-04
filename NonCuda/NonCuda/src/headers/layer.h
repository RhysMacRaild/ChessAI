#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <matrix.h>
#include "activationFunction.h";
#include "computations.h";

class Layer {
private:
    Activation* activationFunc;
    Computations* comp = new Computations();
    int neuronsCurrentLayer = 0; //x
    int neuronsNextLayer = 0;
    int numberOfWeights = 0;
    Matrix* inputMatrix = new Matrix();
    Matrix* weightsMatrix = new Matrix(); //w
    Matrix* biasMatrix = new Matrix(); //b
    Matrix* outputMatrix = new Matrix(); //z
    Matrix* activatedOutputMatrix = new Matrix(); //y_hat

    void swishActivationFunction();

public:
    Layer(int neuronsCurrentLayer);
    void calculateOutput();
    void calculateWeightsBias(Matrix* inputMatrix);
    void CalculateActivationFunction();
    void generateArrays(int neuronsNextLayer);
    int getNeuronCount();
    void printWeightsArray();
    void printBiasArray();
    void setActivationFunction(Activation* func);
};