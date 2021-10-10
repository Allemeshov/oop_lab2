//
// Created by Alexander on 09.10.2021.
//

#include "super_calc.h"

SuperCalculator::SuperCalculator() {
    jordanGauss = nullptr;
    seidel = nullptr;
}

void SuperCalculator::ProcessJordanGauss() {
    jordanGauss = new JordanGauss();

    jordanGauss->process();
}

void SuperCalculator::ProcessSeidel() {
    seidel = new Seidel();

    seidel->process();
}

