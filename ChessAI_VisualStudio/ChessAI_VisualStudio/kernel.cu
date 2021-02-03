
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include "board.h";
#include "layer.h";
#include "matrix.h";


class FullyConnectedLayer : public Layer {
public:
    FullyConnectedLayer(int neurons) : Layer(neurons){}
};

class NeuralNetwork {
private:
    int numberOfLayers = 0;
    Layer** layersArray = (Layer**)malloc(sizeof(Layer));


public:
    void addLayer(Layer* newLayer) {
        if (numberOfLayers == 0) {\
            numberOfLayers++;
            layersArray[0] = newLayer;
        }
        else {
            //Resize the layers array
            Layer** tmpArray = (Layer**)malloc(sizeof(Layer)*numberOfLayers);
            for (int i = 0; i < numberOfLayers; i++) {
                tmpArray[i] = layersArray[i];
            }

            free(layersArray);
            numberOfLayers++;
            layersArray = (Layer**)malloc(sizeof(layersArray) * numberOfLayers);

            for (int i = 0; i < numberOfLayers-1; i++) {
                    layersArray[i] = tmpArray[i];
            }

            //Add new layer
            layersArray[numberOfLayers-1] = newLayer;

            //Generate weights for previous layer
            layersArray[numberOfLayers - 2]->generateArrays(newLayer->getNeuronCount());
        }
    }

    void compute(int* arr) {

    }

    void printLayerWeights(int layerNumber) {
        this->layersArray[layerNumber]->printWeightsArray();
    }

    void printLayerBias(int layerNumber) {
        this->layersArray[layerNumber]->printBiasArray();
    }
};

int main()
{

    //Board* board = new Board();
    //board->getMoves(true);
    //board->printAllPossibleBoards();
    //NeuralNetwork* test = new NeuralNetwork();
    //test->addLayer(new FullyConnectedLayer(5));
    //test->addLayer(new FullyConnectedLayer(10));
    //test->printLayerBias(0);
    //test->printLayerWeights(0);
    float a[2][2] = { {1.0,2.0},{3.0,4.0} };
    float b[2][3] = { {5.0,7.0,9.0},{6.0,8.0,10.0} };
    
    float** a1;
    

    Matrix* A = new Matrix(a, 2, 2);
    Matrix* B = new Matrix(b 2, 3);


    return 0;
}
