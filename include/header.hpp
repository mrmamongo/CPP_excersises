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
#include <utility>

using string = std::string;
using std::cout;
using std::cin;
using std::endl;
using std::any;
using json = nlohmann::json;
using std::vector;

class SolSystem {
struct Moon {
 explicit Moon(int volume_ = 100, string name_ = "Moon")
      : volume(volume_), name(name_){}
 
 protected:
  int volume;
  string name;

  friend std::ostream& operator<<(std::ostream& os, const SolSystem& system);
};

class Planet {
 protected:
  int volume;

  string name;

  std::vector<Moon> moons;

  any yebok;

 public:
  explicit Planet(int volume_ = 50, string name_ = "Random_Planet")
      : volume(volume_), name(std::move(name_)){}
  Planet(
      any yebok_, std::vector<Moon> moons_,
      int volume_ = 50, string name_ = "Random_Planet"
      )
      : volume(volume_), name(std::move(name_)),
        moons(std::move(moons_)), yebok(std::move(yebok_)){}
  friend std::ostream& operator<<(std::ostream& os, const SolSystem& system);
  //void Print();
};
 
class Star {
 protected:
  int light;
  string name;

 public:
  explicit Star(int light_ = 100000, string name_ = "Sol")
      : light(light_), name(std::move(name_)){}
  friend std::ostream& operator<<(std::ostream& os, const SolSystem& system);
};

 private:
  std::vector<Planet> planets;

  Star star;

  string name;

 public:
  explicit SolSystem(string name_ = "Solar_System")
      : name(std::move(name_)){}
  SolSystem(
      Star star_, std::vector<Planet> planets_,
      string name_ = "Solar_System")
      : planets(std::move(planets_)),
        star{std::move(star_)},
        name(std::move(name_)){}


  static SolSystem Parse(const json& data);
  static SolSystem ParseFile(const string& jsonPath);
  static SolSystem ParseString(const string& jsonString);
  friend std::ostream& operator<<(std::ostream& os, const SolSystem& system);
};

#endif // INCLUDE_HEADER_HPP_
