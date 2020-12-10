// Copyright 2020 lamp
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <any>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::any;
using std::any_cast;
using std::vector;

enum Colours{
    Brown = 0, //0
    Grey = 1, //1
    Blond = 2, //2
    Black = 3 //3
};

struct Squirrel {
    Colours colour;
    bool isHungry = true;
};

struct Visitor {
    string name;
    int nuts;
};

struct Forest {
    std::vector<Squirrel> squirrels;
    std::vector<Visitor> visitors;

    void takeVisitor();
    void PrintSquirrels();
    void GoForAWalk();
};

void Forest::takeVisitor() {
    cout << "Enter your name\n";
    Visitor visitor;
    cin >> visitor.name;
    cout << "Enter amount of nuts\n";
    cin >> visitor.nuts;
    if (visitor.nuts < 1) {
        cout << "You entered wrong amount of nuts!"
        << "Come back next time with nuts";
    } else {
        cout << "Have a great time!\n";
        visitors.push_back(visitor);
    }
}

void Forest::PrintSquirrels() {
    for (int i = 0; i < squirrels.size(); ++i) {
        cout << "Squirrel " << i + 1 << " ";
        cout << ((squirrels[i].isHungry) ? "is so hungry " : "is not hungry ");
        cout << "Skin: ";
        switch (squirrels[i].colour) {
            case Brown:
                cout << "brown\n";
                break;
            case Grey:
                cout << "grey\n";
                break;
            case Blond:
                cout << "blond\n";
                break;
            case Black:
                cout << "black\n";
                break;
        }
    }
}

void Forest::GoForAWalk() {
    for (Visitor visitor : visitors) {
        for (Squirrel& squirrel : squirrels) {
            if (squirrel.isHungry) {
                if (visitor.nuts <= 1) {
                    cout << "Is that all your brought?\nGo away and get some more!!!!\n";
                    break;
                }
                visitor.nuts -= 2;
                squirrel.isHungry = false;
            } else {
                continue;
            }
        }
    }
}

int main() {

    int visitors;
    cout << "Enter the visitors:\n";
    cin >> visitors;

    Forest forest;

    for (int i = 0; i < visitors; ++i) {
    forest.takeVisitor();
    }

    for (unsigned int i = 0; i < (unsigned int)rand()%15; ++i) {
        Squirrel squirrel;
        squirrel.colour = Colours((unsigned int)rand()%4);
        forest.squirrels.push_back(squirrel);
    }
    cout << "There are " << forest.squirrels.size() << " squirrels in the forest\n";

    forest.PrintSquirrels();

    cout << "=============================FOREST WALK=============================\n";

    forest.GoForAWalk();

    forest.PrintSquirrels();
    for (Visitor visitor : forest.visitors) {
        cout << "Visitor\n" << visitor.name << " had " << visitor.nuts << " nut when he came there\n";
    }

    return 0;
}

