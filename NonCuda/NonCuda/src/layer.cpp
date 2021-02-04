#include "layer.h";

    void Layer::swishActivationFunction() {

    }

    Layer::Layer(int neuronsCurrentLayer) {
        this->neuronsCurrentLayer = neuronsCurrentLayer;
    }

    void Layer::calculateWeightsBias(Matrix* input) {
        this->inputMatrix = new Matrix(input);
        comp->matMult(input, weightsMatrix, outputMatrix);
        comp->matMult(outputMatrix, biasMatrix, outputMatrix);
        this->calculateOutput();
    }

    void Layer::calculateOutput() {
        Matrix* denominator = new Matrix(outputMatrix->getRows(), outputMatrix->getCols());
        comp->matExponential(outputMatrix, false, denominator);
        comp->matScalarAdd(denominator, 1.0f, denominator);
        comp->matDivision(outputMatrix, denominator, activatedOutputMatrix);
    }

    void Layer::generateArrays(int neuronsNextLayer) {
        this->neuronsNextLayer = neuronsNextLayer;
        //Alocate Memory for outputs
        this->activatedOutputMatrix->setMatrixDims(neuronsCurrentLayer, weightsMatrix->getCols());
        this->outputMatrix->setMatrixDims(neuronsCurrentLayer, weightsMatrix->getCols());

        //Allocate Memory for weightArray
        this->weightsMatrix->setMatrixDims(neuronsCurrentLayer, neuronsNextLayer);

        //Allocate Memory for biasMatrix
        biasMatrix->setMatrixDims(1, neuronsNextLayer);

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