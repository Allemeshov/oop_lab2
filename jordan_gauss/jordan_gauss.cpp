//
// Created by Alexander on 09.10.2021.
//

#include "jordan_gauss.h"
#include "../fort/fort.hpp"

JordanGauss::JordanGauss() {
    std::cout << "Enter size of 2d array (square matrix): ";
    std::cin >> size;
    if (std::cin.fail()) {
        do {
            std::cout << "Wrong input! Enter size of 2d array (square matrix): ";
            std::cin >> size;
        } while (std::cin.fail());
    }

    //    matrix = new float *[size];
//    for (int i = 0; i < size; ++i) {
//        matrix[i] = new float[size];
//    }
}

void JordanGauss::PrintMatrix() {
    fort::char_table table;
    table.set_cell_text_align(fort::text_align::center);
    table.set_cell_min_width(7);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++)
            table << matrix[i][j];
        table << fort::endr;
    }

    std::cout << table.to_string() << std::endl;
}

void JordanGauss::process() {
    int flag = 0;

    flag = PerformOperation();

    if (flag == 1)
        flag = CheckConsistency(flag);

    // Printing Final Matrix
    std::cout << "Final Argumented Matrix is : " << std::endl;
    PrintMatrix();
    std::cout << std::endl;

    // Printing Solutions(if exist)
    PrintResult(flag);
}

int JordanGauss::PerformOperation() {
    int i, j, k = 0, c, flag = 0, m = 0;
    float pro = 0;

    // Performing elementary operations
    for (i = 0; i < size; i++) {
        if (matrix[i][i] == 0) {
            c = 1;
            while ((i + c) < size && matrix[i + c][i] == 0)
                c++;
            if ((i + c) == size) {
                flag = 1;
                break;
            }
            for (j = i, k = 0; k <= size; k++)
                std::swap(matrix[j][k], matrix[j + c][k]);
        }

        for (j = 0; j < size; j++) {

            // Excluding all i == j
            if (i != j) {

                // Converting Matrix to reduced row
                // echelon form(diagonal matrix)
                float pro = matrix[j][i] / matrix[i][i];

                for (k = 0; k <= size; k++)
                    matrix[j][k] = matrix[j][k] - (matrix[i][k]) * pro;
            }
        }
    }
    return flag;
}

int JordanGauss::CheckConsistency(int flag) {
    int i, j;
    float sum;

    // flag == 2 for infinite solution
    // flag == 3 for No solution
    flag = 3;
    for (i = 0; i < size; i++) {
        sum = 0;
        for (j = 0; j < size; j++)
            sum = sum + matrix[i][j];
        if (sum == matrix[i][j])
            flag = 2;
    }
    return flag;
}

void JordanGauss::PrintResult(int flag) {
    std::cout << "Result is : ";

    if (flag == 2)
        std::cout << "Infinite Solutions Exists" << std::endl;
    else if (flag == 3)
        std::cout << "No Solution Exists" << std::endl;


        // Printing the solution by dividing constants by
        // their respective diagonal elements
    else {
        for (int i = 0; i < size; i++)
            std::cout << matrix[i][size] / matrix[i][i] << " ";
    }
}
