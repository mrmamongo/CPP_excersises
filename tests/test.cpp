// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"



TEST(ProgramTest, FullTest) {
  string jsonString = R"({
  "SolarSystem":{
  "name": "Solar System",
  "star": {
    "name": "Sol",
    "light": 100500
  },
  "planets": [
    {
      "name": "Earth",
      "volume": 250,
      "yebok": "Bulkin",
      "moons": [
        {
          "name": "Moon",
          "volume": 100
        }
      ]
    },
    {
      "name": "Venus",
      "volume": 200,
      "yebok": ["Otrokova", "Boruta"],
      "moons": null
    }
  ]
},
  "_meta": {
    "planetCount": 2
  }
})";
  std::ofstream solarSystemFile;
  solarSystemFile.open("solarSystem.json", std::ios::out);
  solarSystemFile << jsonString;
  solarSystemFile.close();
  SolSystem system = SolSystem::ParseFile("solarSystem.json");
  cout << system;
}

TEST(ProgramTest, StringTest) {
  string jsonString = R"({
  "SolarSystem":{
  "name": "Solar System",
  "star": {
    "name": "Sol",
    "light": 100500
  },
  "planets": [
    {
      "name": "Earth",
      "volume": 250,
      "yebok": "Bulkin",
      "moons": [
        {
          "name": "Moon",
          "volume": 100
        }
      ]
    },
    {
      "name": "Venus",
      "volume": 200,
      "yebok": ["Otrokova", "Boruta"],
      "moons": []
    }
  ]
},
  "_meta": {
    "planetCount": 2
  }
})";
  SolSystem system = SolSystem::ParseString(jsonString);
  cout << system;
}
