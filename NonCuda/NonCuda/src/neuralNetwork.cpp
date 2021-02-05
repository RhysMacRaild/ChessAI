#include "neuralNetwork.h";

void NeuralNetwork::addLayer(Layer* newLayer) {
    if (numberOfLayers == 0) {
        numberOfLayers++;
        layersArray[0] = newLayer;
    }
    else {
        //Resize the layers array
        Layer** tmpArray = (Layer**)malloc(sizeof(Layer) * numberOfLayers);
        for (int i = 0; i < numberOfLayers; i++) {
            tmpArray[i] = layersArray[i];
        }

        free(layersArray);
        numberOfLayers++;
        layersArray = (Layer**)malloc(sizeof(layersArray) * numberOfLayers);

        for (int i = 0; i < numberOfLayers - 1; i++) {
            layersArray[i] = tmpArray[i];
        }

        //Add new layer
        layersArray[numberOfLayers - 1] = newLayer;

        //Generate weights for previous layer
        layersArray[numberOfLayers - 2]->generateArrays(newLayer->getNeuronCount());
    }
}

void NeuralNetwork::addOutputLayer(Layer* newLayer) {
    //Resize the layers array
    Layer** tmpArray = (Layer**)malloc(sizeof(Layer) * numberOfLayers);
    for (int i = 0; i < numberOfLayers; i++) {
        tmpArray[i] = layersArray[i];
    }

    free(layersArray);
    numberOfLayers++;
    layersArray = (Layer**)malloc(sizeof(layersArray) * numberOfLayers);

    for (int i = 0; i < numberOfLayers - 1; i++) {
        layersArray[i] = tmpArray[i];
    }

    //Add new layer
    layersArray[numberOfLayers - 1] = newLayer;

    //Generate weights for previous layer and output
    layersArray[numberOfLayers - 2]->generateArrays(newLayer->getNeuronCount());
    layersArray[numberOfLayers - 1]->generateArrays(newLayer->getNeuronCount());
}

void NeuralNetwork::computeForwardPass(Matrix* input) {
    input->flatten();
    layersArray[0]->activatedOutputMatrix = new Matrix(input);

    for (int i = 1; i < numberOfLayers; i++) {
        layersArray[i]->forwardStep(layersArray[i-1]->activatedOutputMatrix);
    }
}

void NeuralNetwork::printLayerWeights(int layerNumber) {
    this->layersArray[layerNumber]->printWeightsArray();
}

void NeuralNetwork::printLayerBias(int layerNumber) {
    this->layersArray[layerNumber]->printBiasArray();
}

Matrix* NeuralNetwork::getOutput(){
    return this->layersArray[numberOfLayers-1]->activatedOutputMatrix;
}