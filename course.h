#pragma once
#include "task.h"

class course{
    private:
        vector<task> gradeBook;
        string name;
    
    public:
        //Constructor
        course(string n);

        //Accessors
        string getName();

        //Mutators
        void setName(string n);

        //Utility
        void menu();
        void print();
        void getCurrentMark();
        void calculateMarks();
        void addTask();
        void removeTask(int taskNum);
        void editTask(int taskNum);
        void inputMark(int taskNum);

};