#ifndef _COUNTRY_H
#define _COUNTRY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Country {
	private:
        string Name;
        int Population;
        float Area;

    public:
        Country();
        Country(string name, int population, float area);
        void setName(string name);
        void setPopulation(int population);
        void setArea(float area);
         bool isLarge(Country B);
        string getName() const;
        int getPopulation() const;
        float getArea() const;
        double getPopulationDensity() const;
        void print() const;
    
};

#endif
