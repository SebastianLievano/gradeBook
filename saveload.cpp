/*
saveload.cpp by Sebastian Lievano Arzayus
part of gradeBook C++ project
This file manages the loading and saving of classes and tasks from and to the save.txt file
*/

#include "globals.h"
#include "course.h"

/*
Format for save File
-----------------
# of Courses
Course Name 
Numtasks
Name Weight Mark
Name Weight Mark
Name Weight Mark
Course Name
Numtasks
Name Weight Mark
*/

//FUNCTION load : This function loads classes and tasks from the save.txt file into the courses vector
//Complexity Analysis: Runs in O(n*m) where n = numCourses, m = numTasks. Not significant because both should be low
void load(vector<course>& courses){
    //numCourses: total number of courses | numTasks: number of tasks
    int numCourses, numTasks;
    //courseName: name of course | taskName: name of task
    string courseName, taskName;
    double weight, mark;
    //course pointer used to construct new courses
    course* cl;
    //task pointer used to construct new tasks
    task* ta;
    //Creation of an input file stream from save.txt
    ifstream loadFile("save.txt");
    //Getting number of courses to use in for loop
    loadFile >> numCourses;
    for(int i = 0; i < numCourses; ++i){
        //getting course name and number of tasks for use in for loop
        loadFile >> courseName >> numTasks;
        //constructing course object
        cl = new course(courseName);
        //Adding tasks
        for(int j = 0; j < numTasks; ++j){
            //Getting task info, creating task, and adding it to course
            loadFile >> taskName >> weight >> mark;
            ta = new task(taskName, weight, mark);
            cl->addExistingTask(*ta);
        }
        //Adding course to courses vector
        courses.push_back(*cl);
    }
    //Just in case
    ta = nullptr;
    cl = nullptr;
}

//FUNCTION save: saves file onto save.txt
//Complexity Analysis: O(numtasks*numcourses) - Not significant as tasks/courses will in general be low
void save(vector<course>& courses){
    //creating output stream and wiping file
    ofstream  saveFile("save.txt");
    //courseNum: number of courses | taskNum: number of tasks
    int courseNum = courses.size(), taskNum;
    //Recording number of courses
    saveFile << courseNum << "\n";
    //Printing onto file in appropriate formatting
    for(int i = 0; i < courseNum; ++i){
        taskNum = courses[i].getTaskNum();
        saveFile << courses[i].getName() << "\n" << taskNum << "\n";
        for(int j = 0; j < taskNum; ++j){
            saveFile << courses[i].getTaskName(j) << " " << courses[i].getTaskWeight(j) << " " << courses[i].getTaskMark(j) << "\n";      
        }
    }
    cout << "Saved Successfully!" << endl;
}