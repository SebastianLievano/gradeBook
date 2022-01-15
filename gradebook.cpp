#include "course.h"


//Helper Functions
int openingMenu(vector<course>& classes);
void classManagement(vector<course> & classes);

void load(vector<course> & classes);

void save(vector<course> & classes);

void clearPage();

int main(){
    int userInput;
    bool keepGoing = true;
    vector<course> classes;
    load(classes);
    while(keepGoing){
        clearPage();
        userInput = openingMenu(classes);
        clearPage();
        if(userInput == -1) break;
        else if(userInput == 0) classManagement(classes);
        else classes[userInput - 1].menu();
    }
    save(classes);
    return 0;
}

int openingMenu(vector<course> & classes){
    int userInput, numClasses = classes.size();
    bool done = false;
    restart:
    clearPage();
    cout << "GRADEBOOK" << endl << "Your classes are" << endl;
    for(int i = 0; i < numClasses; ++i){
        cout << i+1 << ") " << classes[i].getName() << endl;
    }
    userInput = -10;
    cout << "Menu Options: " << endl << "Enter corresponding number to access Class Menus"
    << endl << "0) Manage Classes" << endl << "Anything else to exit" << endl << ">";
    cin >> userInput;
    if(!cin.fail() && userInput >= 0 && userInput < numClasses){ 
        cin.ignore(mil, '\n');
        return userInput;
        }
    else if(cin.fail() || userInput < 0 || userInput > numClasses){
        cin.clear();
        cin.ignore(mil, '\n');
        cout << "Invalid Input. Are you sure you want to exit the program?" << endl
        << "Input 1 to exit. Input any other key to continue" << endl << ">";
        cin >> userInput;
        if(userInput == 1) return -1;
        if(cin.fail() || userInput != 1){
            cin.clear();
            cin.ignore(mil, '\n');
            goto restart;
        }
    }
    return -1;
}

void classManagement(vector<course>& classes){
    bool done = false;
    int numClasses, numInput, storage;
    string inputString;
    char input = 'K';
    clearPage();
    restart:
    numClasses = classes.size();
    cout << "CLASS MANAGEMENT" << endl;
    cout << "GRADEBOOK" << endl << "Your classes are" << endl;
    for(int i = 0; i < numClasses; ++i){
        cout << i+1 << ") " << classes[i].getName() << endl;
    }
    cout << "OPTIONS" << endl << "x) Return to Main menu" << endl << "+) Add Class" << 
    endl << "-) Delete Class" << endl;
    cin >> input;
    cin.ignore(mil, '\n');
    switch(input){
        case 'x': return; break;
        case '+': { 
            cout << "Please enter the name of your new class" << endl;
            cin >> inputString;
            cin.ignore(mil, '\n');
            course c(inputString);
            classes.push_back(c);
            c.menu();
            goto restart;
            break;
        }
        case '-': {
            cout << "Please enter the number of the class you'd like to delete";
            cin >> numInput;
            cin.ignore(mil, '\n');
            if(cin.fail() || numInput < 1 || numInput > numClasses){
                cin.clear();
                cout << "Invalid Input" << endl;

            }
            else{
                storage = numInput;
                cout << "Are you sure you want to erase " << classes[numInput-1].getName() << "?" << endl;
                cout << "Press 1 to confirm, anything else to cancel" << endl;
                cin >> numInput;
                cin.ignore(mil, '\n');
                if(cin.fail() || numInput != 1){
                    cin.clear();
                    cout << "Cancelled" << endl;
                }
                else classes.erase(classes.begin()+storage-1);
            }
            goto restart;
        }
        default: {
            cout << "Invalid Input" << endl;
            goto restart;
        }
    }
}
