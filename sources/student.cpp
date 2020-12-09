//
// Created by lamp on 07.12.2020.
//
// Copyright 2020 lamp

#include <string>
#include <nlohmann/json.hpp>
#include <any>

using std::string;
using std::any;
using json = nlohmann::json;

struct Student {
  string name;
  any group;
  any avg;
  any debt;

  static Student from_json(const json& j);
};

string parse_name(const json& j);
any parse_group(const json& j);
any parse_avg(const json& j);
any parse_debt(const json& j);

Student Student::from_json(const json& j) {
  Student student;
  student.name = parse_name(j);
  student.group = parse_group(j);
  student.avg = parse_avg(j);
  student.debt = parse_debt(j);

  return student;
}

string parse_name(const json& j) {
  return static_cast<string>(j);
}


int main(){
  json data; // = Some data;
  std::vector<Student> students;

  for (const auto& item : data["items"]){
    students.push_back(Student::from_json(item));
  }

}
