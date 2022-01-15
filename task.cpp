/*
task.cpp by Sebastian Lievano Arzayus
Part of GradeBook C++ program
Class method declarations for task class

*/

#include "task.h"

//Constructors
//Constructor with mark input sets all values upon construction
task::task(string n, double w, double m){
    name = n;
    weight = w;
    mark = m;
}

//Constructor without mark input sets mark as empty
task::task(string n, double w){
    name = n;
    weight = w;
    mark = empty;
}

//Accessors for weight, mark, and name
double task::getWeight(){
    return weight;
}
        
double task::getMark(){
    return mark;
}

string task::getName(){
    return name;
}

//Mutators for weight, mark, and name
void task::setWeight(double w){
    weight = w;
}
        
void task::setMark(double m){
    mark = m;
}
        
void task::setName(string n){
    name = n;
}



//Utility
//METHOD task::print : prints the task name, weight, and mark
void task::print(){
    //Setting output to two decimal points
    cout << fixed;
    cout << setprecision(2);
    cout << name;
    //Printing 15 characters combined of name and spaces. 
    //Max name length is 12 characters, but name box must be same length for all tasks
    for(int i = name.length(); i < 15; i++) cout << " ";
    //If the weight value is single digit, an extra space is added to keep things aligned
    if(weight < 10) cout << " ";
    cout << weight << "%";
    cout << "     ";
    //If mark is single digit, two spaces are added
    if(mark < 10) cout << "  ";
    //If mark is double digit, single space added. if 100%, no space added
    else if(mark != 100) cout << " ";
    //Only printing if mark is set
    if(mark != empty) cout << mark << "%";
    cout << endl;
}

//METHOD task::percentsGotten : returns the percentage points the student received from that task
double task::percentsGotten(){
    return ((mark*weight)/100);
}

