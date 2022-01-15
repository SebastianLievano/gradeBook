This is an in depth usage guide to GradeBook

**SAVE AND LOAD FUNCTIONALITY**
GradeBook is fully equipped to save and load your classes. Although it is fully optional, you may find it faster to write existing
classes and tasks on the included 'save.txt' file, which will then be loaded whenever you open the program. Alternatively, you may
use the existing program menus to create your classes/tasks, which will then be saved when you exit the program.

The save.txt file is formatted like this (included below is the template and then an example)

    numClasses
    Class1Name
    NumTasks1
    Task1 Weight Mark
    Task2 Weight Mark
    Task3 Weight Mark
    Task4 Weight Mark
    Class2Name
    NumTasks2
    Task1 Weight Mark
    Task2 Weight Mark

NOTE: numClasses and numTasks must be accurate or your program will load incorrect/incomplete data
NOTE: If you dont want to input/havent received a mark yet, write -5

EXAMPLE

    4
    ECE244-C++
    6
    Lab1 5 100
    Lab2 10 100
    Lab3 10 90
    Lab4 15 -5
    Midterm 25 80
    Final 35 -5
    ECE241-Verilog
    6
    Lab1 10 100
    Lab2 10 75
    Lab3 10 0
    Lab4 10 100
    Lab5 10 95
    Final 50 -5
    ECE297-Software
    1
    Project 100 100
    ECE212-Circuits
    0



**MENU USAGE**
This menu displays upon running of the program. Note Classes are already loaded from the save.txt file
OPTIONS
**0) Manage Classes**
Press this option to enter the following menu: 

        CLASS MANAGEMENT
        GRADEBOOK
        Your classes are
        1) ECE244-C++
        2) ECE241-Verilog
        3) ECE297-Software
        4) ECE212-Circuits
        x) Return to Main menu
        +) Add Class
        -) Delete Class

*x) Return to Main menu*        Brings us back to opening menu

*+) Add Class*                  Allows for the creation of a new class
                                Requests user input for name of new task

*-) Delete Class*               Used to delete classes. A popup menu appears to prevent accidental deletions. Deletion can not be undone
                                Requests user input for number of task to delete

**CLASS MENU**
This menu can be accessed by pressing the corresponding number in the menu above

        ECE244-C++ Gradebook
        #  TASK NAME      WEIGHT     MARK
        1) Lab1            5.00%     100.00%
        2) Lab2           10.00%     100.00%
        3) Lab3           10.00%      85.00%
        4) Lab4           15.00%      90.00%
        5) Midterm        25.00%      80.00%
        6) Final          35.00%       
        OPTIONS
        x) Go back to Course List
        c) Calculate Marks
        e) Edit Tasks
        i) Input Mark
        m) Get Current Mark
        n) New Task

**x) Go back to Course List** Returns to Main menu

**c) Calculate Marks** 
    One of the more complex options in this program, it allows for the calculation and projection of marks.

        ECE244-C++ :MARK ESTIMATOR
        ECE244-C++ Gradebook
        #  TASK NAME      WEIGHT     MARK
        1) Lab1            5.00%     100.00%
        2) Lab2           10.00%     100.00%
        3) Lab3           10.00%      90.00%
        4) Lab4           15.00%       
        5) Midterm        25.00%      80.00%
        6) Final          35.00%       
        OPTIONS: 
        1) Guesstimate all marks
        2) Pivot Calculator
            -> Gives required mark on pivot to get certain grades. (i.e need 90 on exam to get 85 on course)
    
  *Option 1*      The program will request inputted guess marks for all non completed tasks and output a final mark 

            Please enter a mark from 0 to 100 for Lab4
            >70
            Please enter a mark from 0 to 100 for Final
            >80
            With these scores, your final mark in ECE244-C++ will be 82.50%

   *Option 2* This option will allow you to see potential marks based on a "pivot". Input all other incomplete marks and the gradeBook will tell you how you need to do on the pivot to reach certain thresholds. First you need to select a pivot task and input marks for nonPivot tasks, as shown below:
        
            Which task would you like to look at?
            >6
            Your pivot task is Final
            Please enter a mark from 0 to 100 for Lab4
            >80

   and then the program will produce an output like this: 

            Your final marks for different marks in Final will be:
            MAX COURSE MARK: 91.00%
            MIN COURSE MARK: 56.00%
            To get a 60%, you need a 11.43% on Final
            To get a 70%, you need a 40.00% on Final
            To get a 80%, you need a 68.57% on Final
            To get a 90%, you need a 97.14% on Final

            If there is a specific percent you'd like to calculate for, insert it below. To exit this menu, press 0

   And finally, you can calculate for specific percent values with the final option.


**e)Edit Tasks** 
Used to edit task name, weight, and mark. Also used to delete tasks. After user inputs task number, the following menu appears

    You have selected the following task: Midterm        25.00%      80.00%

    OPTIONS
    1) Change Name
    2) Change Weight
    3) Change Mark
    4) Delete Task

   *1) Change Name*     Changes name of Task
   *2) Change Weight*   Changes weight of Task
   *3) Change Mark*     Changes mark of Task
   *4) Delete task*     Deletes task. Popup to confirm. Can not be undone

**i)Input Marks**
Used to input marks. Simply select task and then input mark

    Please enter the number of the task you'd like to edit: 4
    Enter new mark: (Input -1 to empty mark)85

**m) Get Current Mark**
Calculates your current mark from the deliverables you have completed

    Current Mark: 88.00
    Of the 50.00% you could've got, you've gotten 44.00
    Maximum Potential Mark (assuming 100 on remaining marks): 94.00% 
    Minimum Potential Mark(assuming 0 on remaining tasks): 88.00% 

**n) New Task**
Creates a new task after receiving user input for name, weight, and mark.
There is an option to not enter a mark by inserting a negative number

    Please enter the name of your task: (max 12 characters, no spaces)
    > Lab5
    Please enter the weight of your task: (between 0 and 100)
    > 10
    If you would like to enter a mark for Lab5 please do so below
    To skip this step, input any negative number
    Values above 100% will be accepted for mark
    > 85




