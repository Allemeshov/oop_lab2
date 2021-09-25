#include <iostream>
#include "person.h"

void fillPeople(std::vector<Person> &people, const int &length);

void outputElderThan(std::vector<Person> &people);

void outputWithHigh(std::vector<Person> &people);

void outputMales(std::vector<Person> &people);

int main() {

    std::vector<Person> people;

    fillPeople(people, 10);

//    outputElderThan(people);
//    outputWithHigh(people);
    outputMales(people);


    return 0;
}

void fillPeople(std::vector<Person> &people, const int &length) {
    for (int i = 0; i < length; ++i) {
        people.push_back(generatePerson());
    }
}

void outputElderThan(std::vector<Person> &people) {
    int bound;
    while (true) {
        std::cout << "Enter bound of the age: ";
        if (std::cin >> bound) {
            if (bound > 0) {
                break;
            } else {
                std::cout << "Age must be positive";
            }
        } else {
            std::cout << "Error! Enter integer." << std::endl;
        }
    }

    auto size = people.size();
    for (int i = 0; i < size; ++i) {
        if (2021 - people[i].getDateOfBirth().year > bound) {
            people[i].printData();
        }
    }
}

void outputWithHigh(std::vector<Person> &people) {
    auto size = people.size();
    for (int i = 0; i < size; ++i) {
        if (people[i].getEducation().high) {
            people[i].printData();
        }
    }
}

void outputMales(std::vector<Person> &people) {
    auto size = people.size();
    for (int i = 0; i < size; ++i) {
        if (people[i].getSex() == Sex::Male) {
            people[i].printData();
        }
    }

}



