#include <stdio.h>
#include <stdlib.h>
#include "board.h";
#include "fullyConnectedLayer.h";
#include "neuralNetwork.h";
#include "matrix.h";
#include "swishActivation.h"

int main()
{

    Board* board = new Board();
    board->getMoves(true);
    board->printAllPossibleBoards();

    //test->printLayerBias(0);
    //test->printLayerWeights(0);
    //
    float tmpA[2][2] = { {1.0,2.0},{3.0,4.0} };
    float tmpB[2][3] = { {5.0,7.0,9.0},{6.0,8.0,10.0} };
    
    float** a = new float *[2];
    float** b = new float *[2];

    for (int i = 0; i < 2; i++) {
        a[i] = tmpA[i];
        b[i] = tmpB[i];
    }
    

    Matrix* A = new Matrix(a, 2, 2);
    Matrix* B = new Matrix(b, 2, 3);
    Matrix* C = new Matrix(A->getRows(), B->getCols());

    NeuralNetwork* test = new NeuralNetwork();
    Swish* swish = new Swish();
    test->addLayer(new FullyConnectedLayer(4, swish)); //Input layer
    test->addLayer(new FullyConnectedLayer(100, swish));
    test->addOutputLayer(new FullyConnectedLayer(4, swish)); //Output Layer
    test->computeForwardPass(A);
    Matrix* output = test->getOutput();
    output->printMatrix();
    


    //A->printMatrix();
    //B->printMatrix();

    //Computations* compute = new Computations();
    //compute->matMult(A, B, C);
    //compute->matExponential(A, true, A);
    //A->printMatrix();


    return 0;
}
