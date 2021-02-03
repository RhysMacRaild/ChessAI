#include "layer.h";

    void Layer::swishActivationFunction() {

    }

    Layer::Layer(int neuronsCurrentLayer) {
        this->neuronsCurrentLayer = neuronsCurrentLayer;
    }

    void Layer::calculateOutput(int* inputArr) {

    }

    void Layer::generateArrays(int neuronsNextLayer) {
        this->neuronsNextLayer = neuronsNextLayer;

        //Allocate Memory for weightArray
        this->numberOfWeights = neuronsCurrentLayer * neuronsNextLayer;
        weightsArray = (float**)malloc(sizeof(float*) * neuronsCurrentLayer);
        for (int i = 0; i < neuronsNextLayer; i++) {
            weightsArray[i] = (float*)malloc(sizeof(float) * neuronsNextLayer);
        }

        //Allocate Memory for biasArray
        biasArray = (float*)malloc(sizeof(float) * neuronsNextLayer);

        //Initialise weights and bias to 0
        for (int j = 0; j < neuronsNextLayer; j++) {
            for (int i = 0; i < neuronsCurrentLayer; i++) {
                weightsArray[i][j] = 0;
            }
            biasArray[j] = 0;
        }
    }

    int Layer::getNeuronCount() {
        return neuronsCurrentLayer;
    }

    void Layer::printWeightsArray() {
        for (int i = 0; i < neuronsCurrentLayer; i++) {
            for (int j = 0; j < neuronsNextLayer; j++) {
                printf("%d\t", weightsArray[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    void Layer::printBiasArray() {
        for (int i = 0; i < neuronsNextLayer; i++) {
            printf("%d\n", biasArray[i]);
        }
        printf("\n");
    }
