#include "Task.h"

Task::Task(int id, const std::string& description) : id(id), description(description), completed(false) {}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool status) {
    completed = status;
}

void Task::updateDescription(const std::string& newDescription) {
    description = newDescription;
}