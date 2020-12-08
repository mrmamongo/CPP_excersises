// Copyright 2020 Your Name <your_email>

#include <header.hpp>

/*void Planet::Print() {
  cout << "The planet " << name << endl;
  cout << "Has " << moons.size() << " moons:\n";
  for (size_t i = 0; i < moons.size(); ++i) {
    cout << moons[i].name << endl;
  }
  cout << "Volume is:\t" << volume << endl;
}*/

SolSystem SolSystem::ParseFile(const string& jsonPath) {
  std::ifstream file(jsonPath);
  if (!file) {
    throw std::runtime_error("ERROR: File doesn't exist");
  }

  json data;
  file >> data;

  if (!data["SolarSystem"]["planets"].is_array()){
    throw std::runtime_error("ERROR: \"planets\" field is not array");
  }

  return SolSystem::Parse(data);
}

SolSystem SolSystem::ParseString(const string& jsonString) {
  const json data = json::parse(jsonString);

  if (!data["SolarSystem"]["planets"].is_array()){
    throw std::runtime_error("ERROR: \"planets\" field is not array");
  }

  return Parse(data);
}

inline any get_yebok(const json& value) {
  if (value.is_string()) {
    return value.get<string>();
  } else {
    return value.get<std::vector<string>>();
  }
}



SolSystem SolSystem::Parse(const json& data) {
  string name = data.at("SolarSystem").at("name");

  std::vector<Planet> planets;
  for(const auto& planet : data["SolarSystem"]["planets"]) {
    auto pName = planet["name"].get<string>();
    int volume = planet["volume"].get<int>();
    any yebok = get_yebok(planet["yebok"]);
    std::vector<Moon> moons;
    for (const auto& moon : planet["moons"]) {
      auto mName = moon["name"].get<string>();
      int mVolume = moon["volume"].get<int>();
      Moon m(mVolume, mName);
      moons.push_back(m);
    }
    Planet p(yebok, moons, volume, pName);
    planets.push_back(p);
  }
  auto sName = data["SolarSystem"]["star"]["name"].get<string>();
  int sLight = data["SolarSystem"]["star"]["light"].get<int>();
  Star s(sLight, sName);

  return SolSystem(s, planets, name);
}

std::ostream& operator<< (std::ostream& os, const SolSystem& system){
  os << "System:\n\t" << system.name << ":\n"
     << "Has star:\t" << system.star.name << ",\tlight:\t"
     << system.star.light << endl;
  if (!system.planets.empty()) {
    os << "Has some planets:\n";
    for (const auto& planet : system.planets) {
      os << planet.name << ":\tvolume:\t" << planet.volume << "\tyebok:\t";
      if (planet.yebok.type() == typeid(string)) {
        os << std::any_cast<string>(planet.yebok) << endl;
      } else {
        for (const auto& yebok : std::any_cast<vector<string>>(planet.yebok)) {
          os << yebok << " ";
        }
        os << endl;
      }
      if (!planet.moons.empty()) {
        os << "Has moons:\n";
        for (const auto& moon : planet.moons){
          os << moon.name << ":\tvolume:\t" << moon.volume << endl;
        }
      } else {
        os << "Planet doesn't have any moons\n";
      }
      os << endl;
    }
  } else {
    os << "This system doesn't have any planets\n";
  }

  return os;
}

