#include "globals.h"
#include "task.h"

class task{
    private:
        string name;
        double weight;
        double mark;
    public:
        //Constructor
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
        string getName();

        //Mutators
        void setWeight(double w);
        void setMark(double m);
        void setName(string n);

        //Utility
        void print();
};