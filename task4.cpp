/* Build a simple console-based to-do list manager that allows users to add, view, and delete tasks */

#include <iostream>
#include <string>

using namespace std ;

const int MAX_TASKS = 10 ;

struct Task 
{
    string description;
    bool completed;
} ;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask() 
{
    if (numTasks < MAX_TASKS) {
        cout << "Enter task description: ";
        cin.ignore();
        getline(cin, tasks[numTasks].description);
        tasks[numTasks].completed = false;
        numTasks++;
        cout << "Task added successfully.\n";
       } else {
        cout << "Maximum number of tasks reached.\n";
       }
}

void viewTasks() 
{
    cout << "Tasks:\n";
    for (int i = 0; i < numTasks; i++)
     {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " (Completed)";
      }
        cout << endl;
    }
}

void deleteTask()
 {
    if (numTasks > 0) {
        cout << "Enter task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= numTasks) {
            for (int i = taskNumber - 1; i < numTasks - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            numTasks--;
            cout << "Task deleted successfully.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    } else {
        cout << "No tasks to delete.\n";
    }
}
int main()
 {
    int choice;
    do {
        cout << "\n=.... To-Do List Manager ....=\n";
        cout << "1. Add Task_\n";
        cout << "2. View Tasks_\n";
        cout << "3. Delete Task_\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: : ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}