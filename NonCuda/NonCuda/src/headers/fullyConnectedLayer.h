#pragma once
#include "layer.h"
class FullyConnectedLayer : public Layer {
public:
    FullyConnectedLayer(int neurons) : Layer(neurons) {}
    FullyConnectedLayer(int neurons, Activation* func) : Layer(neurons, func) {}
    void forwardStep(Matrix* input);
    void calculateWeightsBias(Matrix* inputMatrix); //z
    void calculateActivation(); //y_hat

    void calculateDerivatives();

};