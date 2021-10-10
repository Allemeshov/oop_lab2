#include "person.h"


int Person::s_id = 1;

Person::Person(FIO fio, std::string adress, Sex sex, Education education, DateOfBirth date) {
    this->id = Person::s_id++;

    this->fio.surname = fio.surname;
    this->fio.name = fio.name;
    this->fio.second_name = fio.second_name;

    this->adress = adress;

    this->sex = sex;

    this->education = education;

    this->date_of_birth = date;
}

Person::~Person() {
    this->fio.second_name.clear();
    this->fio.surname.clear();
    this->fio.name.clear();

    this->adress.clear();
}


Person generatePerson() {
    return *new Person(
            {"Lemeshov", "Alexander", "Alexanderovich"},
            "Kukuevo 6",
            static_cast<Sex>(getRandNumber(1, 3)),
            {
                    getRandNumber(0, 100) % 2 == 0,
                    getRandNumber(0, 100) % 2 == 0,
                    getRandNumber(0, 100) % 2 == 0
            },
            {
                    getRandNumber(1, 28),
                    getRandNumber(1, 12),
                    getRandNumber(1940, 2021)
            }
    );
}

int getRandNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}

void Person::printData() {
    std::cout << std::endl;

    std::cout << this->getFio().toString() << std::endl;

    std::cout << this->date_of_birth.toString() << std::endl;

    switch (this->sex) {
        case Sex::Male:
            std::cout << "Male";
            break;
        case Sex::Female:
            std::cout << "Female";
            break;
        case Sex::Undefined:
            std::cout << "Undefined";
            break;
    }
    std::cout << std::endl;

    std::cout << "Adress: " << this->adress << std::endl;

    std::cout << "Educations: " << std::endl;
    std::cout << "\tKindergarten: " << std::to_string(this->education.kindergarten) << std::endl;
    std::cout << "\tSchool: " << std::to_string(this->education.school) << std::endl;
    std::cout << "\tHigh: " << std::to_string(this->education.high) << std::endl;

    std::cout << std::endl;
}

