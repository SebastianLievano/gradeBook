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
        
int course::getCurrentMark(){
    clearPage();
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
    return currentMark;
}

//Enter Assumed Marks for all non inputted tasks or Enter 

float markReq(float target, float pivotWeight, float otherMark){
    float req, percentGotten, marksFromPivot;
    if(target > (otherMark + pivotWeight) || target < otherMark){
        return -1;
    }
    //PercentGotten = NonPivotWeight*OtherMark/100
    percentGotten = (100-pivotWeight)*otherMark/100;
    //Target = MarksFromPivot + Percents Gotten
    marksFromPivot = target - percentGotten;
    //MarksFromPivot = Weight * req / 100 -> req = 100Mp / Weight
    req = 100 * marksFromPivot / pivotWeight;
    return req;

}

void course::calculateMarks(){
    int userInput = 0, percentGotten = 0, taskPivot, pivotWeight, dummy, req;
    double w, m;
    clearPage();
    cout << fixed;
    cout << setprecision(2);
    invalid1:
    cout << name << " :MARK ESTIMATOR" << endl;
    print();
    cout << "OPTIONS: " << endl << "1) Input all uninputted marks and get your mark back" << endl
    << "2) Guess all marks but one, then receive the required values for the non guessed mark to achieve certain grades" << endl
    << "    i.e) After your inputted marks: MAX(100 on task): 90%, MIN(0 on task): 50%, A: Need 75 on task, ..." << endl;
    cin >> userInput;
    if(cin.fail() || userInput > 2 || userInput < 1){
        cout << "Invalid Input" << endl << endl << endl;
        goto invalid1;
    }
    if(userInput == 2){
        invalid2:
        cout << "Which task would you like to look at?" << endl;
        cin >> taskPivot;
        if(cin.fail() || taskPivot < 1 || taskPivot > gradeBook.size()) cout << "Invalid Input" << endl; goto invalid2;
    }

    for(int i = 0; i < gradeBook.size(); i++){
            if(i == taskPivot && userInput == 2){
                pivotWeight = gradeBook[i].getWeight();
            }
            else{
                w = gradeBook[i].getWeight();
                m = gradeBook[i].getMark();
                if(m == empty){
                    invalid3:
                    cout << "Please enter a mark from 0 to 100 for " << m << ". Weight: " << w;
                    cin >> dummy;
                    if(cin.fail() || userInput < 0 || userInput > 100) cout << "Invalid Input" << endl; goto invalid3;
                    percentGotten += (userInput*w/100);
                    }
                else percentGotten += (m*w/100);
            }
    }
    if(userInput == 1)   cout << "With these scores, your final mark in " << name << " will be " << percentGotten << "%" << endl;
    else{
        cout << "Your final marks for different marks in " << gradeBook[taskPivot].getName() << "will be:" << endl;
        cout << "MAX COURSE MARK: " << percentGotten + pivotWeight << "%" << endl;
        cout << "MIN COURSE MARK: " << percentGotten << "%" << endl;
        for(int i = 20; i < 110; i +=10){
            dummy = markReq(i, pivotWeight, percentGotten);
            if(dummy != -1){
                cout << "To get a " << i << "%, you need a " << dummy << "%" << " on " << gradeBook[taskPivot].getName() << endl;
            }
        }
        invalid4:
        req = -2;
        cout << endl << "If there is a specific percent you'd like to calculate for, insert it below. To exit this menu, press 0" << endl;
        cin >> dummy;
        if(dummy < 0 || dummy > 100 || cin.fail()){ cout << "Invalid Input"; goto invalid4;}
        else req = markReq(dummy, pivotWeight, percentGotten);
        if(cin.fail() || req == -2){
            cout << "Invalid Input" << endl;
            goto invalid4;
        }
        else if(req == 0) return;
        else if(req == -1){
            cout << "You can not get that mark" << endl;
            goto invalid4;
        }
        else{
            cout << "To get a " << dummy <<"%, you need a " << req <<"%" << " on " << gradeBook[taskPivot].getName() << endl;
            goto invalid4;
        }
    }
}
        
void addTask();
        void removeTask(int taskNum);
        void editTask(int taskNum);
};