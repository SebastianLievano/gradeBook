#include "globals.h"
#include "task.h"

task::task(string n, double w, double m){
    name = n;
    weight = w;
    mark = m;
}
        
task::task(string n, double w){
    name = n;
    weight = w;
    mark = empty;
}

//Accessors
double task::getWeight(){
    return weight;
}
        
double task::getMark(){
    return mark;
}

string task::getName(){
    return name;
}

//Mutators
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
void task::print(){
    cout << fixed;
    cout << setprecision(2);
    cout << name << "   " << weight << "   " << mark << endl;
}
