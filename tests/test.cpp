// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "Moon.hpp"


struct altVector {
    int* vector;


    int operator[](string key);
    int operator[](int index) {
        return vector[index];
    }
    void Print(){
        cout << vector[0];
    }
};
int altVector::operator[](string key) {
    if (key == "first") {
        return vector[0];
    } else if (key == "second") {
        return vector[1];
    } else if (key == "third") {
        return vector[2];
    } else {
        return 0;
    }
}

struct notVector {
    int* vector;
};

TEST(vectorTest, indexing) { // int main()
    altVector vectorObject;

    vectorObject.vector = new int [3]{100,200,300};

    notVector notVectorObject;

    cout << vectorObject[1] << endl; // Good
    cout << vectorObject["pyat"] << endl;

    notVectorObject.vector = new int [3]{100,200,300};

    cout << notVectorObject.vector[1] << endl; // Bad
}


TEST(Moons, parsing){ // int main()
    std::vector<Moon> moons = Moon::Parse();
    cout << moons.size() << endl;

    for (Moon moon : moons) {
        cout << "Name:\t" << moon.name
        << " Parent planet:\t" << moon.parentPlanet << endl;
    }
}