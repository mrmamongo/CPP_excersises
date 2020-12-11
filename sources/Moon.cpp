//
// Created by lamp on 11.12.2020.
//
#include "Moon.hpp"

std::vector<Moon> Moon::Parse() {
    string wMoon = R"({
  "Moons": [
{
  "name": "Moon",
  "parentPlanet": "Earth",
  "square": 38000000,
  "openingYear": 0
},
{
"name": "Phobos",
"parentPlanet": "Mars",
"square": 1600,
"openingYear": 1877
},
{
"name": "Ganimed",
"parentPlanet": "Jupiter",
"square": 5262,
"openingYear": 1610
},
{
"name": "Kallisto",
"parentPlanet": "Jupiter",
"square": 4821,
"openingYear": 1610
},
{
"name": "IO",
"parentPlanet": "Jupiter",
"square": 41910000,
"openingYear": 1619
},
{
"name": "Miranda",
"parentPlanet": "Uranus",
"square": 698710,
"openingYear": 1948
}
],
  "_meta": {
    "count": 6
  }
})";

    std::ofstream wrongMoon;


    wrongMoon.open("package.json", std::ios::out);
    wrongMoon << wMoon;
    wrongMoon.close();

    std::ifstream file;
    file.open("package.json");

    if (!file) {
        throw std::runtime_error{"Field is not exist"};
    }

    json moonsJson;

    file >> moonsJson;
    file.close();

    if(!(moonsJson["Moons"].is_array())) {
        throw std::runtime_error{"Field \"Moons\" is not array!"};
    }

    if(moonsJson["Moons"].size() != (moonsJson["_meta"])["count"]) {
        throw std::runtime_error{"Field \"Moons\" is incorrect, check \"_meta\""};
    }

    std::vector<Moon> out;
    for (json moon : moonsJson["Moons"]) {
        string newName = moon["name"].get<string>();
        string newParentPlanet = moon["parentPlanet"].get<string>();
        long newSquare = moon["square"].get<long>();
        int newOpeningYear = moon["openingYear"].get<int>();
        Moon newMoon {
            newName,
            newParentPlanet,
            newSquare,
            newOpeningYear
        };
        out.push_back(newMoon);
    }
    return out;
}
