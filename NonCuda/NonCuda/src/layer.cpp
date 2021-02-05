#include "layer.h";

    Layer::Layer(int neuronsCurrentLayer) {
        this->neuronsCurrentLayer = neuronsCurrentLayer;
    }

    Layer::Layer(int neuronsCurrentLayer, Activation* func) {
        this->neuronsCurrentLayer = neuronsCurrentLayer;
        this->activationFunc = func;
    }

    void Layer::generateArrays(int neuronsNextLayer) {
        this->neuronsNextLayer = neuronsNextLayer;

        //Allocate Memory for weightArray
        this->weightsMatrix->setMatrixDims(neuronsCurrentLayer, neuronsNextLayer);

        //Allocate Memory for biasMatrix
        biasMatrix->setMatrixDims(1, neuronsNextLayer);

        //Alocate Memory for outputs
        this->activatedOutputMatrix->setMatrixDims(1,neuronsNextLayer);
        this->outputMatrix->setMatrixDims(1, neuronsNextLayer);

        //Initialise weights and bias to 0
        for (int j = 0; j < neuronsNextLayer; j++) {
            for (int i = 0; i < neuronsCurrentLayer; i++) {
                weightsMatrix->arr[i][j] = 0;
            }
            biasMatrix->arr[0][j] = 0;
        }
    }

    int Layer::getNeuronCount() {
        return neuronsCurrentLayer;
    }

    void Layer::printWeightsArray() {
        this->weightsMatrix->printMatrix();
    }

    void Layer::printBiasArray() {
        this->biasMatrix->printMatrix();
    }

    void Layer::setActivationFunction(Activation* func) {
        this->activationFunc = func;
    }