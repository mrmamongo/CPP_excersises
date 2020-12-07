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

SolSystem SolSystem::ParseFile(string jsonPath) {
  std::fstream file(jsonPath);

  if (!file) {
    throw std::runtime_error("ERROR: File doesn't exist");
  }

  string jsonString;
  file >> jsonString;
  return SolSystem::ParseString(jsonString);
}

SolSystem SolSystem::ParseString(string jsonString) {
  json data = json::parse(jsonString);

  string name = data.at("SolarSystem").at("name");

  std::vector<Planet> planets;
  for(const auto& planet : data["SolarSystem"]["planets"]) {
    string pName = planet["planet"];
    int volume = planet["volume"];
    any yebok = planet["yebok"];
    std::vector<Moon> moons;
    for (const auto& moon : planet["moons"]) {
      string mName = moon["name"];
      int mVolume = moon["volume"];
      Moon m(mVolume, mName);
      moons.push_back(m);
    }
    Planet p(yebok, moons, volume, pName);
    planets.push_back(p);
  }
  string sName = data["SolarSystem"]["star"]["name"];
  int sLight = data["SolarSystem"]["star"]["light"];
  Star s(sLight, sName);

  return SolSystem(s, planets, name);
}
void SolSystem::Print() {

}

void Program() {
  std::fstream file("SolarSystem.json");
  string jsonString;
  file >> jsonString;
  SolSystem Sol = SolSystem::ParseString(jsonString);
}
