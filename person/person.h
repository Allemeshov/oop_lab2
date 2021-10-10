#ifndef LAB2_PERSON_H
#define LAB2_PERSON_H

#include <iostream>
#include <utility>
#include <random>
#include <vector>

enum Sex {
    Male = 1,
    Female,
    Undefined
};

struct Education {
    bool kindergarten = false;
    bool school = false;
    bool high = false;
};

struct FIO {
    std::string surname;
    std::string name;
    std::string second_name;

    std::string toString() const {
        return this->name + ' ' +
               this->second_name + ' ' +
               this->surname;
    }
};

struct DateOfBirth {
    int day;
    int month;
    int year;

    std::string toString() const {
        return std::to_string(this->day) + "." +
               std::to_string(this->month) + "." +
               std::to_string(this->year);
    }
};


class Person {
private:

    static int s_id;

    int id;

    FIO fio;

    std::string adress;

    Sex sex;

    Education education;

    DateOfBirth date_of_birth;

public:
    Person(FIO fio, std::string adress, Sex sex, Education education, DateOfBirth date);

    ~Person();

    FIO getFio() {
        return this->fio;
    }

    void setFio(FIO fio) {
        this->fio = std::move(fio);
    }

    std::string getAdress() {
        return this->adress;
    }

    void setAdress(const std::string &newAdress) {
        this->adress = newAdress;
    }

    Sex getSex() {
        return this->sex;
    }

    void setSex(const Sex &newSex) {
        this->sex = newSex;
    }

    Education getEducation() {
        return this->education;
    }

    void setEducation(const Education &newEducation) {
        this->education = newEducation;
    }

    DateOfBirth getDateOfBirth() {
        return this->date_of_birth;
    }


    void setDateOfBirth(const DateOfBirth &newDate) {
        this->date_of_birth = newDate;
    }

    void printData();
};

Person generatePerson();

int getRandNumber(int min, int max);


#endif //LAB2_PERSON_H
