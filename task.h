#pragma once
#include "globals.h"

class task{
    private:
        string name;
        double weight;
        double mark;
    public:
        //Constructor
        task(string n, double w, double m);
        task(string n, double w);

        //Accessors
        double getWeight();
        double getMark();
        string getName();

        //Mutators
        void setWeight(double w);
        void setMark(double m);
        void setName(string n);

        //Utility
        void print();
};