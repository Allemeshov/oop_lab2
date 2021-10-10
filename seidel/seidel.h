
#ifndef LAB2_SEIDEL_H
#define LAB2_SEIDEL_H

#include <iostream>
#include <stdio.h>
#include "../fort/fort.hpp"

class Seidel {
private:
    int size;

    float **matrix;
    float *rightSide;
    float *x;
    float *y;

    void initMatrix();

    void initRightSide();

    void initXs();

    void initYs();

    void enterSize();

    void enterLeftValues();

    void enterRightValues();

    void enterInitialXs();

    int enterIterationNumber();

    void iterate(int iterationsNumber);

public:
    Seidel();

    void process();
};

#endif //LAB2_SEIDEL_H
