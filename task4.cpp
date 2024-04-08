/*Build a simple console-based to-do list manager that allows users to add, view, and delete tasks.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
void displayMenu() {
    cout << "\n== TO-DO LIST MANAGER ==" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter task to add: ";
    getline(cin.ignore(), task);
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "\nTasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i  + 1 << ". " << tasks[i] << endl;
        }
    }
}
void deleteTask(vector<string>& tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        cout << "Enter task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}
int main() {
    vector<string> tasks;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
    return 0;
}