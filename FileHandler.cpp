#include "FileHandler.h"
#include <fstream>
#include <sstream>

FileHandler::FileHandler(const std::string& filename) : filename(filename) {}

void FileHandler::saveTodoList(const TodoList& todoList) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : todoList.getTasks()) {
            file << task.getId() << "," << task.getDescription() << "," << task.isCompleted() << std::endl;
        }
        file.close();
    }
}

TodoList FileHandler::loadTodoList() {
    TodoList todoList;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr, description, completedStr;
            if (std::getline(iss, idStr, ',') && std::getline(iss, description, ',') && std::getline(iss, completedStr)) {
                int id = std::stoi(idStr);
                bool completed = (completedStr == "1");
                Task task(id, description);
                task.setCompleted(completed);
                todoList.getTasks().push_back(task);
            }
        }
        file.close();
    }
    return todoList;
}