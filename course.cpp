#include "course.h"

void clearPage(){
    for(int i = 0; i < 20; i++) cout << endl;
}

course::course(string n){
    name = n;
}


//Accessors
string course::getName(){
    return name;
}

int course::getTaskNum(){
    return gradeBook.size();
}

string course::getTaskName(int taskNum){
    return gradeBook[taskNum].getName();
}

double course::getTaskWeight(int taskNum){
    return gradeBook[taskNum].getWeight();
}

double course::getTaskMark(int taskNum){
    return gradeBook[taskNum].getMark();
}

//Mutators
void course::setName(string n){
    name = n;
}

//Utility
void course::menu(){
    char userInput;
    int taskNum;
    restart:
    invalid:
    cout << endl;
    print();
    cout << "OPTIONS" << endl;
    cout << "x) Go back to Course List" << endl <<
    "c) Calculate Marks" << endl <<
    "e) Edit Tasks" << endl <<
    "i) Input Mark" << endl << 
    "m) Get Current Mark" << endl <<
    "n) New Task" << endl;
    cin >> userInput;
    cin.ignore(mil,'\n');
    if(cin.fail()){
        cin.clear();
        cout << "Invalid input" << endl;
        goto invalid;
    }
    switch(userInput){
        case 'x':{
            return;
            break;
        }
        case 'c': {
            calculateMarks();
            goto restart;
            break;
        }
        case 'e': {
            invalidTask:
            cout << "Please enter the number of the task you'd like to edit: ";
            cin >> taskNum;
            cin.ignore(mil,'\n');
            if(cin.fail() || taskNum < 1 || taskNum > gradeBook.size()){
                cin.clear();
                cout << "Invalid input" << endl;
                goto invalidTask;
            }
            else editTask(taskNum);
            goto restart;
            break;
        }
        case 'i': {
            invalidName:
            cout << "Please enter the number of the task you'd like to edit: ";
            cin >> taskNum;
            cin.ignore(mil,'\n');
            if(cin.fail() || taskNum < 1 || taskNum > gradeBook.size()){
                cin.clear();
                cout << "Invalid input" << endl;
                goto invalidName;
            }
            else inputMark(taskNum);
            goto restart;
            break;
        }
        case 'm': {
            getCurrentMark();
            goto restart;
            break;
        }
        case 'n': {
            addTask();
            goto restart;
            break;
        }
        default: {
            cout << "Invalid Input" << endl;
            goto restart;
        }
    }

}
        
void course::print(){
    cout << name << " Gradebook" << endl;
    cout << "#  TASK NAME      WEIGHT     MARK" << endl;
    for(int i = 0; i < gradeBook.size(); i++){
        cout << i+1 << ") ";
        gradeBook[i].print();
    }
}
        
void course::getCurrentMark(){
    clearPage();
    double percentsGotten = 0, percentPotential = 0, currentMark, maxMark, minMark;
    for(int i = 0; i < gradeBook.size(); i++){
        if(gradeBook[i].getMark() != empty){
            percentsGotten += gradeBook[i].percentsGotten();
            percentPotential += gradeBook[i].getWeight();
        }
    }
    currentMark = (percentsGotten/percentPotential)*100;
    maxMark = 100 - percentPotential + percentsGotten;
    cout << fixed;
    cout << setprecision(2);
    cout << "Current Mark: " << currentMark << endl <<
    "Of the " << percentPotential << "% you could've got, you've gotten " << percentsGotten;
    cout << endl << "Maximum Potential Mark (assuming 100 on remaining marks): " << maxMark << "% "<< endl;
    cout << "Minimum Potential Mark(assuming 0 on remaining tasks): " << currentMark << "% " << endl;
}

//Enter Assumed Marks for all non inputted tasks or Enter 

float markReq(float target, float pivotWeight, float otherMark){
    float req, marksFromPivot;
    if(target > (otherMark + pivotWeight) || target < otherMark){
        return -1;
    }
    //Target = MarksFromPivot + Percents Gotten
    marksFromPivot = target - otherMark;
    //MarksFromPivot = Weight * req / 100 -> req = 100Mp / Weight
    req = 100 * marksFromPivot / pivotWeight;
    return req;

}

void course::calculateMarks(){
    int userInput = 0, taskPivot;
    double w, m, percentGotten = 0, pivotWeight, dummy, req, doubleIn;
    clearPage();
    cout << fixed;
    cout << setprecision(2);
    invalid1:
    cout << name << " :MARK ESTIMATOR" << endl;
    print();
    cout << "OPTIONS: " << endl << "1) Guesstimate all marks" << endl
    << "2) Pivot Calculator" << endl
    << "    -> Gives required mark on pivot to get certain grades. (i.e need 90 on exam to get 85 on course)" << endl;
    cin >> userInput;
    if(cin.fail() || userInput > 2 || userInput < 1){
        cin.ignore(mil,'\n');
        cin.clear();
        cout << "Invalid Input" << endl << endl << endl;
        goto invalid1;
    }
    if(userInput == 2){
        cin.ignore(mil,'\n');
        invalid2:
        cout << "Which task would you like to look at?" << endl;
        cin >> taskPivot;
        if(cin.fail() || taskPivot < 1 || taskPivot > gradeBook.size()){
            cin.ignore(mil,'\n');
            cin.clear();
            cout << "Invalid Input" << endl; goto invalid2;
        }
        taskPivot -= 1;
        cout << "Your pivot task is " << gradeBook[taskPivot].getName() << endl;
    }
    double valAdded;
    for(int i = 0; i < gradeBook.size(); i++){
            if(i == taskPivot && userInput == 2){
                pivotWeight = gradeBook[i].getWeight();
            }
            else{
                w = gradeBook[i].getWeight();
                m = gradeBook[i].getMark();
                if(m == empty){
                    invalid3:
                    cin.ignore(mil,'\n');
                    cout << "Please enter a mark from 0 to 100 for " << gradeBook[i].getName() << endl;
                    cin >> doubleIn;
                    if(cin.fail() || doubleIn < 0 || doubleIn > 100){   
                        cin.clear();
                        cout << "Invalid Input" << endl; 
                        goto invalid3;
                    }
                    valAdded = doubleIn*w/100;
                    percentGotten += valAdded;
                    }
                else{
                    valAdded = (m*w)/100;
                    percentGotten += valAdded;
                }
            }
    }
    if(userInput == 1)   cout << "With these scores, your final mark in " << name << " will be " << percentGotten << "%" << endl;
    else{
        cout << "Your final marks for different marks in " << gradeBook[taskPivot].getName() << " will be:" << endl;
        cout << "MAX COURSE MARK: " << percentGotten + pivotWeight << "%" << endl;
        cout << "MIN COURSE MARK: " << percentGotten << "%" << endl;
        for(int i = 20; i < 110; i +=10){
            dummy = markReq(i, pivotWeight, percentGotten);
            if(dummy != -1){
                cout << "To get a " << i << "%, you need a " << dummy << "%" << " on " << gradeBook[taskPivot].getName() << endl;
            }
        }
        invalid4:
        cin.ignore(mil,'\n');
        req = -2;
        cout << endl << "If there is a specific percent you'd like to calculate for, insert it below. To exit this menu, press 0" << endl;
        cin >> dummy;
        if(dummy == 0) return;
        if(dummy < 0 || dummy > 100 || cin.fail()){ cout << "Invalid Input"; goto invalid4;}
        else req = markReq(dummy, pivotWeight, percentGotten);
        if(cin.fail() || req == -2){
            cin.clear();
            cout << "Invalid Input" << endl;
            goto invalid4;
        }
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
        
void course::addTask(){
    string input;
    float weight, mark;
    invalidStringInput:
    cout << "Please enter the name of your task: (max 12 characters, no spaces)" << endl;
    cin >> input;
    cin.ignore(mil,'\n');
    if(cin.fail() || input.length() > 12){
        cout << "Invalid Input" << endl;
        cin.clear();
        goto invalidStringInput;
    }
    else{
        invalidWeightInput:
        cout << "Please enter the weight of your task: (between 0 and 100)" << endl;
        cin >> weight;
        cin.ignore(mil,'\n');
        if(cin.fail() || weight < 0 || weight > 100){
            cin.clear();
            cout << "Invalid Input" << endl;
            goto invalidWeightInput;
        }
        else{
            invalidMarkInput:
            cout << "If you would like to enter a mark for " << input << " please do so below" << endl 
            << "To skip this step, input any negative number" << endl << "Values above 100% will be accepted for mark" << endl;
            cin >> mark;
            cin.ignore(mil,'\n');
            if(cin.fail()){
                cin.clear();
                cout << "Invalid Input" << endl;
                goto invalidMarkInput;
            }
            else if(mark < 0){
                task n(input, weight);
                gradeBook.push_back(n);
                return;
            }
            else{
                task n(input, weight, mark);
                gradeBook.push_back(n);
                return;
            }
        }
    }
}

void course::removeTask(int taskNum){
    int input = 0;
    string name = gradeBook[taskNum-1].getName();
    cout << "Are you sure you want to erase " << name << "? " << endl
    << "Enter 1 to confirm, anything else to cancel" << endl;
    cin >> input;
    cin.ignore(mil,'\n');
    if(cin.fail() || input != 1){
        cin.clear();
        cout << "Deletion cancelled" << endl;
        return;
    }
    else gradeBook.erase((gradeBook.begin()+taskNum-1));
    cout << name << " has been deleted" << endl;
}

void course::editTask(int taskNum){
    int input = -1;
    string newName;
    float newMarkWeight;
    restart:
    cout << "You have selected the following task: ";
    gradeBook[taskNum-1].print();
    cout << endl << "OPTIONS" << endl <<
    "1) Change Name" << endl <<
    "2) Change Weight" << endl <<
    "3) Change Mark" << endl <<
    "4) Delete Task" << endl;
    cin >> input;
    switch(input){
        case 1: {
            invalidName:
            cout << "Enter new name (max 12 Chars): ";
            cin >> newName;
            cin.ignore(mil,'\n');
            if(cin.fail() || newName.length() > 12){
                cin.clear();
                cout << endl << "Invalid Input" << endl;
                goto invalidName;
            }
            else gradeBook[taskNum - 1].setName(newName);
            break;
        }
        case 2: {
            invalidWeight:
            cout << "Enter new weight (max 100%): ";
            cin >> newMarkWeight;
            cin.ignore(mil,'\n');
            if(cin.fail() || newMarkWeight < 0 || newMarkWeight > 100){
                cin.clear();
                cout << endl << "Invalid Input" << endl;
                goto invalidWeight;
            }
            else gradeBook[taskNum-1].setWeight(newMarkWeight);
            break;
        }
        case 3: {
            inputMark(taskNum);
            break;
        }
        case 4: {
            removeTask(taskNum);
            break;
        }
        default: {
            cout << "Invalid Input" << endl;
            goto restart;
        }
    }
}

void course::inputMark(int taskNum){
    double newMark;
    invalidMark: 
    newMark = 1;
    cout << "Enter new mark: (Input -1 to empty mark)";
    cin >> newMark;
    cin.ignore(mil,'\n');
    if(newMark == -1){
        gradeBook[taskNum-1].setMark(-5);
    }
    else if(cin.fail() || newMark < 0){
        cin.clear();
        cout << endl << "Invalid Input" << endl;
        goto invalidMark;
    }
    else gradeBook[taskNum-1].setMark(newMark);
}

void course::addExistingTask(task ta){
    gradeBook.push_back(ta);
}