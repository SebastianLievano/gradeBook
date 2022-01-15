/*
task.h by Sebastian Lievano Arzayus
part of gradeBook C++ program
TASK is a class for student assignments. In the current gradebook form, a task contains a name, a weight, and a mark
*/


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
        double percentsGotten();
};