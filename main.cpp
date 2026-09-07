#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Task {
    string title;
    bool isCompleted;
};

vector<Task> tasks;
const string FILE_NAME = "tasks.txt";

// Load tasks from text file
void loadTasks() {
    ifstream file(FILE_NAME);
    string line;
    while (getline(file, line)) {
        if (line.length() > 2) {
            bool status = (line[0] == '1');
            string title = line.substr(2);
            tasks.push_back({title, status});
        }
    }
    file.close();
}

// Save tasks to text file
void saveTasks() {
    ofstream file(FILE_NAME);
    for (const auto& task : tasks) {
        file << (task.isCompleted ? "1" : "0") << " " << task.title << "\n";
    }
    file.close();
}

void displayTasks() {
    cout << "\n--- Your To-Do List ---\n";
    if (tasks.empty()) {
        cout << "No tasks found!\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << (tasks[i].isCompleted ? "X" : " ") << "] " 
             << i + 1 << ". " << tasks[i].title << "\n";
    }
}

int main() {
    loadTasks();
    int choice = 0;

    while (choice != 5) {
        displayTasks();
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
            tasks.push_back({title, false});
            saveTasks();
        } 
        else if (choice == 2 || choice == 3 || choice == 4) {
            if (tasks.empty()) continue;
            cout << "Enter task number: ";
            int index;
            cin >> index;
            
            if (index > 0 && index <= tasks.size()) {
                if (choice == 2) tasks[index - 1].isCompleted = true;
                if (choice == 4) tasks[index - 1].isCompleted = false;
                if (choice == 3) tasks.erase(tasks.begin() + index - 1);
                saveTasks();
            } else {
                cout << "Invalid task number.\n";
            }
        }
    }
    
    cout << "Goodbye!\n";
    return 0;
}
