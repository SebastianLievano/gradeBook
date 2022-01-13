#include "globals.h"
#include "course.h"
#include "task.h"

vector<course> classes;

//Helper Functions
int openingMenu();

void load(vector<course>& s);

void save(const vector<course> s);

void clearPage();

void classManagement();




int main(){
    int userInput;
    bool keepGoing = true;
    load(classes);
    while(keepGoing){
        clearPage();
        userInput = openingMenu();
        clearPage();
        if(userInput == -1) return 0;
        if(userInput == 0) classManagement();
        else classes[userInput - 1].menu();
    }
    save(classes);
    return 0;
}

int openingMenu(){
    int userInput, numClasses = classes.size();
    bool done = false;
    while(!done){
        clearPage();
        cout << "GRADEBOOK" << endl << "Your classes are" << endl;
        for(int i = 0; i < numClasses; ++i){
            cout << i+1 << ") " << classes[i].getName() << endl;
        }
        cout << "Menu Options: " << endl << "Enter corresponding number to access Class Menus"
        << endl << "0) Manage Classes" << endl << "Anything else to exit" << endl << ">";
        cin >> userInput;
        if(!cin.fail() && userInput > 0 && userInput < numClasses){
            return userInput;
        }
        else {
            cout << "Invalid Input. Are you sure you want to exit the program?" << endl
            << "If not, input 1. Input any other key to exit" << endl << ">";
            cin >>  userInput;
            if(cin.fail() || userInput != 1) done = true;
        }
    }
    return -1;

}

void classManagement(){
    bool done = false;
    int input, numClasses = classes.size();
    string inputString;
    while(!done){
        clearPage();
        cout << "CLASS MANAGEMENT" << endl;
        cout << "GRADEBOOK" << endl << "Your classes are" << endl;
        for(int i = 0; i < numClasses; ++i){
            cout << i+1 << ") " << classes[i].getName() << endl;
        }
        cout << "0) Return to Main menu" << endl << "1) Add Class" << 
        endl << "2) Delete Class" << endl;
        if(input == 0) return;
        else if(input == 1){
            cout << "Please enter the name of your new class" << endl;
            cin >> inputString;
            course c(inputString);
            classes.push_back(c);
            c.menu();
        }
        else if(input == 2){
            cout << "Please enter the number of the class you'd like to delete";
            cin >> input;
            if(cin.fail() || input < 1 || input > numClasses){
                cout << "Invalid Input" << endl;

            }
            classes.erase(classes.begin()+input-1);
        }
        
    }
}

void clearPage(){
    for(int i = 0; i < 20; i++) cout << endl;
}