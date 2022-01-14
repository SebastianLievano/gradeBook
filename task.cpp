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
/*Keeping Dots in Line:

MARK
100.00%
 50.00%
  5.00%
TASK NAME      WEIGHT     MARK
*/
//Utility
void task::print(){
    cout << fixed;
    cout << setprecision(2);
    cout << name;
    for(int i = name.length(); i < 15; i++) cout << " ";
    if(weight < 10) cout << " ";
    cout << weight << "%";
    cout << "     ";
    if(mark < 10) cout << "  ";
    else if(mark != 100) cout << " ";
    if(mark != empty) cout << mark << "%";
    cout << endl;
}

double task::percentsGotten(){
    return ((mark*weight)/100);
}

