#include "globals.h"
#include "course.h"

/*Format for save File
# of Courses
Course Name 
Numtasks
Name   Weight  Mark
Name   Weight  Mark
Name   Weight  Mark
Course Name
Numtasks
Name   Weight  Mark
*/


void load(vector<course>& courses){
    int numCourses, numTasks;
    string courseName, taskName;
    double weight, mark;
    course* cl;
    task* ta;
    ifstream loadFile("save.txt");
    loadFile >> numCourses;
    for(int i = 0; i < numCourses; ++i){
        loadFile >> courseName >> numTasks;
        cl = new course(courseName);
        for(int j = 0; j < numTasks; ++j){
            loadFile >> taskName >> weight >> mark;
            ta = new task(taskName, weight, mark);
            cl->addExistingTask(*ta);
        }
        courses.push_back(*cl);
    }
    ta = nullptr;
    cl = nullptr;
}

/*Format for save File
# of Courses
Course Name 
Numtasks
Name   Weight  Mark
Name   Weight  Mark
Name   Weight  Mark
Course Name
Numtasks
Name   Weight  Mark
*/

void save(vector<course>& courses){
    ofstream  saveFile("save.txt");
    int courseNum = courses.size(), taskNum;
    saveFile << courseNum << "\n";
    for(int i = 0; i < courseNum; ++i){
        taskNum = courses[i].getTaskNum();
        saveFile << courses[i].getName() << "\n" << taskNum << "\n";
        for(int j = 0; j < taskNum; ++j){
            saveFile << courses[i].getTaskName(j) << " " << courses[i].getTaskWeight(j) << " " << courses[i].getTaskMark(j) << "\n";      
        }
    }
    cout << "Saved Successfully!" << endl;
}