#pragma once
#include <stdio.h>
#include <stdlib.h>

class Layer {
private:
    int neuronsCurrentLayer = 0;
    int neuronsNextLayer = 0;
    int numberOfWeights = 0;
    float** weightsArray;
    float* biasArray;
    float* outputArray;

    void swishActivationFunction();

public:
    Layer(int neuronsCurrentLayer);
    void calculateOutput(int* inputArr);
    void generateArrays(int neuronsNextLayer);
    int getNeuronCount();
    void printWeightsArray();
    void printBiasArray();
};