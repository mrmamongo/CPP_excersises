//
// Created by lamp on 11.12.2020.
//

#ifndef EX1_1_MOON_HPP
#define EX1_1_MOON_HPP

#include <vector>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using json = nlohmann::json;

struct Moon {
    string name;
    string parentPlanet;
    long square;
    int openingYear;

    int nameWidth;

    static std::vector<Moon> Parse();
};


#endif //EX1_1_BANK_H
