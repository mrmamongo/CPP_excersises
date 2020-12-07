// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <string>
#include <vector>
#include <iostream>
#include <any>
#include <nlohmann/json.hpp>
#include <fstream>
#include <map>

using string = std::string;
using std::cout;
using std::cin;
using std::endl;
using std::any;
using json = nlohmann::json;

struct Moon {
  Moon(int volume_ = 100, string name_ = "Moon")
      : volume(volume_), name(name_){};
 private:
  int volume;
  string name;
};

class Planet {
  int volume;

  string name;

  std::vector<Moon> moons;

  any yebok;

 public:
  Planet(int volume_ = 50, string name_ = "Random_Planet")
      : volume(volume_), name(name_){};
  Planet(
      any yebok_, std::vector<Moon> moons_,
      int volume_ = 50, string name_ = "Random_Planet"
      )
      : volume(volume_), name(name_),  moons(moons_), yebok(yebok_){};

  //void Print();
};

class Star {
 private:
  int light;
  string name;

 public:
  Star(int light_ = 100000, string name_ = "Sol")
      : light(light_), name(name_){};
};

class SolSystem {
 private:
  std::vector<Planet> planets;

  Star star;

  string name;
 public:

  SolSystem(string name_ = "Solar_System")
      : name(name_){};
  SolSystem(
      Star star_, std::vector<Planet> planets_,
      string name_ = "Solar_System")
      : planets(planets_), star{star_}, name(name_){};


  static SolSystem ParseFile(string jsonPath);
  static SolSystem ParseString(string jsonString);
  void Print();
};

#endif // INCLUDE_HEADER_HPP_
