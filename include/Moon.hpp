//
// Created by lamp on 11.12.2020.
//

#ifndef EX1_1_MOON_HPP
#define EX1_1_MOON_HPP

#include <vector>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using json = nlohmann::json;

struct Moon {
    string name;
    int yearOfTheOpening;
    double volume;
    bool hasWater;
};


#endif //EX1_1_BANK_H
