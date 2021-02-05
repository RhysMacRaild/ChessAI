#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <matrix.h>
#include "activationFunction.h";
#include "computations.h";

class Layer {
private:
    int neuronsCurrentLayer = 0; //x
    int neuronsNextLayer = 0;
    //int numberOfWeights = 0;

public:
    Activation* activationFunc = 0;
    Computations* comp = new Computations();
    Matrix* inputMatrix = new Matrix();
    Matrix* weightsMatrix = new Matrix(); //w
    Matrix* biasMatrix = new Matrix(); //b
    Matrix* outputMatrix = new Matrix(); //z
    Matrix* activatedOutputMatrix = new Matrix(); //y_hat

    Layer(int neuronsCurrentLayer);
    Layer(int neuronsCurrentLayer, Activation* activation);
    virtual void forwardStep(Matrix* input) = 0;
    void generateArrays(int neuronsNextLayer);
    int getNeuronCount();
    void printWeightsArray();
    void printBiasArray();
    void setActivationFunction(Activation* func);
};