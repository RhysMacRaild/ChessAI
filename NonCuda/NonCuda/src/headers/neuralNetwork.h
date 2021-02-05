#pragma once
#include "layer.h"
class NeuralNetwork {
private:
    int numberOfLayers = 0;
    Layer** layersArray = (Layer**)malloc(sizeof(Layer));


public:
    void addLayer(Layer* newLayer);
    void addOutputLayer(Layer* newLayer);
    void computeForwardPass(Matrix* input);
    void printLayerWeights(int layerNumber);
    void printLayerBias(int layerNumber);
    Matrix* getOutput();
};
