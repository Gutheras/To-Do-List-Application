#include "TodoList.h"
#include <iostream>
#include <algorithm>

TodoList::TodoList() : nextId(1) {}

void TodoList::addTask(const std::string& description) {
    tasks.emplace_back(nextId++, description);
}

void TodoList::updateTask(int id, const std::string& newDescription) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getId() == id; });
    if (it != tasks.end()) {
        it->updateDescription(newDescription);
    }
}

void TodoList::deleteTask(int id) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getId() == id; }), tasks.end());
}

void TodoList::markTaskAsComplete(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.getId() == id; });
    if (it != tasks.end()) {
        it->setCompleted(true);
    }
}

void TodoList::displayTasks() const {
    for (const auto& task : tasks) {
        std::cout << "[" << (task.isCompleted() ? "X" : " ") << "] " << task.getId() << ": " << task.getDescription() << std::endl;
    }
}

const std::vector<Task>& TodoList::getTasks() const {
    return tasks;
}

void TodoList::setTasks(const std::vector<Task>& newTasks) {
    tasks = newTasks;
    nextId = tasks.empty() ? 1 : tasks.back().getId() + 1;
}