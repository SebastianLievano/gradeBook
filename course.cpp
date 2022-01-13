#include "globals.h"
#include "course.h"

class course{
    private:
        vector<task> gradeBook;
        string name;
    
    public:
        //Constructor
course::course(string n){
    name = n;
}

//Accessors
string course::getName(){
    return name;
}

//Mutators
void course::setName(string n){
    name = name;
}

//Utility
void course::menu(){
    print();

}
        
void course::print(){
    cout << name << " Gradebook" << endl;
    cout << "#  TASK NAME      WEIGHT     MARK" << endl;
    for(int i = 0; i < gradeBook.size(); i++){
        cout << i+1 << ") ";
        gradeBook[i].print();
        cout << endl;
    }
}
        
void course::getCurrentMark(){
    double percentsGotten = 0, percentPotential = 0, currentMark, maxMark, minMark;
    for(int i = 0; i < gradeBook.size(); i++){
        if(gradeBook[i].getMark() != empty){
            percentsGotten += gradeBook[i].percentsGotten();
            percentPotential += gradeBook[i].getWeight();
        }
    }
    currentMark = (percentsGotten/percentPotential)*100;
    maxMark = 100 - percentPotential + currentMark;
    cout << fixed;
    cout << setprecision(2);
    cout << "Current Mark: " << currentMark << endl <<
    "Of the " << percentPotential << "% you could've got, you've gotten " << percentsGotten;
    cout << endl << "Maximum Potential Mark (assuming 100 on remaining marks): " << maxMark << "% "<< endl;
    cout << "Minimum Potential Mark(assuming 0 on remaining tasks): " << currentMark << "% " << endl;
}
        
void calculateMarks();
        
void addTask();
        void removeTask(int taskNum);
        void editTask(int taskNum);
};