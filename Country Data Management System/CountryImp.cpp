#include "Country.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

Country::Country() { //initialise all the attributes
    Name = "";
    Population = 0;
    Area = 0;
}

Country::Country(string name, int population, float area) { //set all the value
    Name = name;
    Population = population;
    Area = area;
}

void Country::setName(string name) { //set name
    Name = name;
}

void Country::setPopulation(int population) { // set population
    Population = population;
}

void Country::setArea(float area) { //set area
    Area = area;
}

bool Country::isLarge(Country B) { // which country area is large
    return Area > B.getArea();
}

string Country::getName() const { //get the name
    return Name;
}

int Country::getPopulation() const { // get the population
    return Population;
}

float Country::getArea() const { // get area
    return Area;
}

double Country::getPopulationDensity() const { //get population density
    if (Area != 0) {
        return Population / Area;
    } else {
        return 0.0;
    }
}

void Country::print() const { // print 
    cout << fixed << setprecision(2);
    cout << Name << " has a population " << Population << " and is " << Area << " square km and "
         <<getPopulationDensity() << " people per square km.\n";
}

