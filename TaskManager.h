#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>

struct Task {
    std::string title;
    bool isCompleted;
};

class TaskManager {
private:
    std::vector<Task> tasks;
    const std::string FILE_NAME = "tasks.txt";
    
    void loadTasks();
    void saveTasks();

public:
    TaskManager(); // Constructor automatically loads tasks
    void displayTasks() const;
    void addTask(const std::string& title);
    void completeTask(int index);
    void unmarkTask(int index);
    void removeTask(int index);
    int getTaskCount() const;
};

#endif
