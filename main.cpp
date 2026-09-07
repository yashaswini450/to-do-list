#include <iostream>
#include <string>
#include "TaskManager.h"

using namespace std;

int main() {
    TaskManager manager;
    int choice = 0;

    while (choice != 5) {
        manager.displayTasks();
        cout << "\n1. Add Task  2. Mark Completed  3. Remove Task  4. Unmark Task  5. Exit\n";
        cout << "Choose an option: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            cout << "Enter task description: ";
            cin.ignore();
            string title;
            getline(cin, title);
            manager.addTask(title);
        } 
        else if (choice == 2 || choice == 3 || choice == 4) {
            if (manager.getTaskCount() == 0) continue;
            
            cout << "Enter task number: ";
            int index;
            cin >> index;
            
            if (choice == 2) manager.completeTask(index);
            if (choice == 4) manager.unmarkTask(index);
            if (choice == 3) manager.removeTask(index);
        }
    }
    
    cout << "Goodbye!\n";
    return 0;
}
