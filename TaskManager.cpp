#include "TaskManager.h"
#include <iostream>
#include <fstream>

using namespace std;

TaskManager::TaskManager() {
    loadTasks();
}

void TaskManager::loadTasks() {
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

void TaskManager::saveTasks() {
    ofstream file(FILE_NAME);
    for (const auto& task : tasks) {
        file << (task.isCompleted ? "1" : "0") << " " << task.title << "\n";
    }
    file.close();
}

void TaskManager::displayTasks() const {
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

void TaskManager::addTask(const string& title) {
    tasks.push_back({title, false});
    saveTasks();
}

void TaskManager::completeTask(int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = true;
        saveTasks();
    } else {
        cout << "Invalid task number.\n";
    }
}

void TaskManager::unmarkTask(int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = false;
        saveTasks();
    } else {
        cout << "Invalid task number.\n";
    }
}

void TaskManager::removeTask(int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        saveTasks();
    } else {
        cout << "Invalid task number.\n";
    }
}

int TaskManager::getTaskCount() const {
    return tasks.size();
}
