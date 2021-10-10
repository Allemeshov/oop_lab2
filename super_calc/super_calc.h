//
// Created by Alexander on 09.10.2021.
//

#ifndef LAB2_SUPER_CALC_H
#define LAB2_SUPER_CALC_H

#include "../jordan_gauss/jordan_gauss.h"
#include "../seidel/seidel.h"

class SuperCalculator {
private:
    JordanGauss *jordanGauss;
    Seidel *seidel;

public:
    SuperCalculator();

    void ProcessJordanGauss();
    void ProcessSeidel();
};

#endif //LAB2_SUPER_CALC_H
