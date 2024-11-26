#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "TodoList.h"
#include <string>

class FileHandler {
private:
    std::string filename;

public:
    FileHandler(const std::string& filename);
    void saveTodoList(const TodoList& todoList);
    TodoList loadTodoList();
};

#endif 