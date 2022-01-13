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
        if(userInput == -1) break;
        else if(userInput == 0) classManagement();
        else classes[userInput - 1].menu();
    }
    save(classes);
    return 0;
}

int openingMenu(){
    int userInput, numClasses = classes.size();
    bool done = false;
    restart:
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
        userInput = -1;
        cout << "Invalid Input. Are you sure you want to exit the program?" << endl
        << "Input 1 to exit. Input any other key to continue" << endl << ">";
        cin >>  userInput;
        if(userInput == 1) return -1;
        if(cin.fail() || userInput != 1) goto restart;
    }
    return -1;
}

void classManagement(){
    bool done = false;
    int input = -1, numClasses = classes.size();
    string inputString;
    restart:
    clearPage();
    cout << "CLASS MANAGEMENT" << endl;
    cout << "GRADEBOOK" << endl << "Your classes are" << endl;
    for(int i = 0; i < numClasses; ++i){
        cout << i+1 << ") " << classes[i].getName() << endl;
    }
    cout << "0) Return to Main menu" << endl << "1) Add Class" << 
    endl << "2) Delete Class" << endl;
    cin >> input;
    switch(input){
        case 0: return; break;
        case 1: { 
            cout << "Please enter the name of your new class" << endl;
            cin >> inputString;
            course c(inputString);
            classes.push_back(c);
            c.menu();
            break;
        }
        case 2: {
            cout << "Please enter the number of the class you'd like to delete";
            cin >> input;
            if(cin.fail() || input < 1 || input > numClasses){
                cout << "Invalid Input" << endl;

            }
            else{
                cout << "Are you sure you want to erase " << classes[input-1].getName() << "?" << endl;
                cout << "Press 1 to confirm, anything else to cancel" << endl;
                cin >> input;
                if(cin.fail() || input != 1) cout << "Cancelled" << endl;
                else classes.erase(classes.begin()+input-1);
            }
        }
        default: {
            cout << "Invalid Input" << endl;
            goto restart;
        }
    }
}

void clearPage(){
    for(int i = 0; i < 20; i++) cout << endl;
}