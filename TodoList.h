#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "Task.h"

class TodoList {
private:
    std::vector<Task> tasks;
    int nextId;

public:
    TodoList();
    void addTask(const std::string& description);
    void updateTask(int id, const std::string& newDescription);
    void deleteTask(int id);
    void markTaskAsComplete(int id);
    void displayTasks() const;
    const std::vector<Task>& getTasks() const;
    void setTasks(const std::vector<Task>& newTasks);
};

#endif 