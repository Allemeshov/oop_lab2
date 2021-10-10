#include "seidel.h"

Seidel::Seidel() {
    size = 0;
    matrix = nullptr;
    rightSide = nullptr;
    x = nullptr;
    y = nullptr;
}

void Seidel::process() {
    enterSize();
    enterLeftValues();
    enterRightValues();
    enterInitialXs();
    const int iterationsNumber = enterIterationNumber();
    iterate(iterationsNumber);
}

void Seidel::enterSize() {
    std::cout << "Enter size of 2d array (square matrix): ";
    std::cin >> size;
    if (std::cin.fail()) {
        do {
            std::cout << "Wrong input! Enter size of 2d array (square matrix): ";
            std::cin >> size;
        } while (std::cin.fail());
    }

    initMatrix();
    initRightSide();
    initXs();
    initYs();
}

void Seidel::initMatrix() {
    matrix = new float *[size];

    for (int i = 0; i < size; ++i) {
        matrix[i] = new float[size];
    }
}

void Seidel::initRightSide() {
    rightSide = new float[size];
}

void Seidel::initXs() {
    x = new float[size];
}

void Seidel::initYs() {
    y = new float[size];
}

void Seidel::enterLeftValues() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "Enter values no :(" << i << ", " << j << ") ";
            std::cin >> matrix[i][j];
        }
    }
}

void Seidel::enterRightValues() {
    std::cout << "\nEnter Values to the right side of equation\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Enter values no :(" << i << ", " << size << ") ";
        std::cin >> rightSide[i];
    }
}

void Seidel::enterInitialXs() {
    std::cout << "\nEnter initial values of x\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Enter values no. :(" << i << "):";
        std::cin >> x[i];
    }
}

int Seidel::enterIterationNumber() {
    int iterationsNumber;

    std::cout << "\nEnter the number of iteration: ";
    std::cin >> iterationsNumber;
    if (std::cin.fail()) {
        do {
            std::cout << "Wrong input! Enter the number of iteration: ";
            std::cin >> iterationsNumber;
        } while (std::cin.fail());
    }

    return iterationsNumber;
}

void Seidel::iterate(int iterationsNumber) {
    fort::char_table table;
    table.set_cell_text_align(fort::text_align::center);
    table.set_cell_min_width(7);

    std::string cell;

    table << fort::header << "x1" << "x2" << "x3" << fort::endr;

    while (iterationsNumber > 0) {
        for (int i = 0; i < size; i++) {
            y[i] = (rightSide[i] / matrix[i][i]);
            for (int j = 0; j < size; j++) {
                if (j == i)
                    continue;
                y[i] = y[i] - ((matrix[i][j] / matrix[i][i]) * x[j]);
                x[i] = y[i];
            }
            table << y[1];
        }
        table << fort::endr;
        iterationsNumber--;
    }

    std::cout << table.to_string() << std::endl;
}
