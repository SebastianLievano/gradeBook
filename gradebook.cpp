/*
gradebook.cpp by Sebastian Lievano Arzayus
part of gradeBook C++ project

The main file for gradeBook, contains non functions:
- main
- classManagemenet
- opeiningMenu

and initializers for save, load, and clearPage which are found in other cpp files
*/

#include "course.h"


//Helper Functions
int openingMenu(vector<course>& classes);

void classManagement(vector<course> & classes);

void load(vector<course> & classes);

void save(vector<course> & classes);

void clearPage();


//FUNCTION main : Main function, contains loop for main menu, calls saving and loading functions
int main(){
    //userInput: used as main input
    int userInput;
    //keepGoing: looping variable
    bool keepGoing = true;
    //classes: our highest level data structure, contains course objects which contain task objects
    vector<course> classes;
    //loading from save.txt
    load(classes);
    //looping until break
    while(keepGoing){
        //clearing page (just printing some lines, not actually deleting)
        clearPage();
        //Running opening menu function
        userInput = openingMenu(classes);
        //clearing page again
        clearPage();
        //Exiting loop and program if exit program command was given
        if(userInput == -1) break;
        //running class management if 0 was selected
        else if(userInput == 0) classManagement(classes);
        //otherwise entering specific class menu (error checking done in openingMenu)
        else classes[userInput - 1].menu();
    }
    //saving
    save(classes);
    return 0;
}

//FUNCTION openingMenu: Highest level menu, leads to class management and independent class menus
int openingMenu(vector<course> & classes){
    //userInput: input variable | numClasses: number of classes
    int userInput, numClasses = classes.size();
    
    restart: //label for invalid inputs
    clearPage(); //clearing page
    //printing classes
    cout << "GRADEBOOK" << endl << "Your classes are" << endl;
    for(int i = 0; i < numClasses; ++i){
        cout << i+1 << ") " << classes[i].getName() << endl;
    }
    //resetting userInput
    userInput = -10;
    cout << "Menu Options: " << endl << "Enter corresponding number to access Class Menus"
    << endl << "0) Manage Classes" << endl << "WARNING: Use the below option to exit or your changes WILL NOT be saved" << endl << "Anything else to exit" << endl << ">";
    cin >> userInput;
    //If input is valid, return it. wipe input stream
    if(!cin.fail() && userInput >= 0 && userInput < numClasses){ 
        cin.ignore(mil, '\n');
        return userInput;
        }
    //invalid input leads to option to exit program
    else if(cin.fail() || userInput < 0 || userInput > numClasses){
        cin.clear();
        cin.ignore(mil, '\n');
        cout << "Invalid Input. Are you sure you want to exit the program?" << endl
        << "Input 1 to exit. Input any other key to continue" << endl << ">";
        cin >> userInput;
        //exiting program
        if(userInput == 1) return -1;
        //restarting menu
        if(cin.fail() || userInput != 1){
            cin.clear();
            cin.ignore(mil, '\n');
            goto restart;
        }
    }
    return -1;
}

//FUNCTION classManagement: used to add and remove classes
void classManagement(vector<course>& classes){
    //numClasses: number of classes| numInput: main input variable| storage: used if numInput value needed
    int numClasses, numInput, storage;
    string inputString;
    //This menu takes character inputs
    char input = 'K';
    
    clearPage();
    restart: //label to restart entire menu
    numClasses = classes.size();
    //printing classes and options
    cout << "CLASS MANAGEMENT" << endl;
    cout << "GRADEBOOK" << endl << "Your classes are" << endl;
    for(int i = 0; i < numClasses; ++i){
        cout << i+1 << ") " << classes[i].getName() << endl;
    }
    cout << "OPTIONS" << endl << "x) Return to Main menu" << endl << "+) Add Class" << 
    endl << "-) Delete Class" << endl;
    cin >> input;
    cin.ignore(mil, '\n'); //wiping stream
    switch(input){
        //back to main menu
        case 'x': return; break;
        //ADD Classes Menu
        case '+': { 
            cout << "Please enter the name of your new class" << endl;
            cin >> inputString;
            cin.ignore(mil, '\n');
            //creating new course and adding to classes
            course c(inputString);
            classes.push_back(c);
            //entering menu of newly created task to allow for the creation of new tasks and such
            c.menu();
            //restarting menu
            goto restart;
            break;
        }
        //DELETE classes Menu
        case '-': {
            //Receive user input
            cout << "Please enter the number of the class you'd like to delete";
            cin >> numInput;
            cin.ignore(mil, '\n');
            //If invalid, cancel
            if(cin.fail() || numInput < 1 || numInput > numClasses){
                cin.clear();
                cout << "Invalid Input" << endl;
            }
            //If valid
            else{
                //storing task number
                storage = numInput;
                //Confirming erasure
                cout << "Are you sure you want to erase " << classes[numInput-1].getName() << "?" << endl;
                cout << "Press 1 to confirm, anything else to cancel" << endl;
                cin >> numInput;
                cin.ignore(mil, '\n');
                //If invalid, user cancelled, return to menu
                if(cin.fail() || numInput != 1){
                    cin.clear();
                    cout << "Cancelled" << endl;
                }
                //Deletion confirmed
                else classes.erase(classes.begin()+storage-1);
            }
            //Restarting menu
            goto restart;
        }
        default: {
            //Invalid input restarts menu after clearing input stream
            cin.clear();
            cin.ignore(mil, '\n');
            cout << "Invalid Input" << endl;
            goto restart;
        }
    }
}
