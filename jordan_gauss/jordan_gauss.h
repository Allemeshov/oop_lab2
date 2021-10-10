//
// Created by Alexander on 09.10.2021.
//

#ifndef LAB2_JORDAN_GAUSS_H
#define LAB2_JORDAN_GAUSS_H

#include <iostream>

class JordanGauss {
private:
    int size;

//    float **matrix;
    float matrix[10][10] = {{0, 2, 1, 4},
                            {1, 1, 2, 6},
                            {2, 1, 1, 7}};

    void PrintMatrix();

    int PerformOperation();

    int CheckConsistency(int flag);

    void PrintResult(int flag);

public:

    JordanGauss();

    void process();

};

#endif //LAB2_JORDAN_GAUSS_H
