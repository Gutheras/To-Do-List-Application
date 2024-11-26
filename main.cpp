#include <iostream>
#include <string>
#include "TodoList.h"
#include "FileHandler.h"

void displayMenu() {
    std::cout << "\n===== To-Do List Menu =====\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Update Task\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Mark Task as Complete\n";
    std::cout << "5. Display Tasks\n";
    std::cout << "6. Save and Quit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    TodoList todoList;
    FileHandler fileHandler("todo_list.txt");

    // Load existing tasks from file
    todoList = fileHandler.loadTodoList();

    int choice;
    std::string description;
    int id;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todoList.addTask(description);
                break;
            case 2:
                std::cout << "Enter task ID to update: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter new task description: ";
                std::getline(std::cin, description);
                todoList.updateTask(id, description);
                break;
            case 3:
                std::cout << "Enter task ID to delete: ";
                std::cin >> id;
                todoList.deleteTask(id);
                break;
            case 4:
                std::cout << "Enter task ID to mark as complete: ";
                std::cin >> id;
                todoList.markTaskAsComplete(id);
                break;
            case 5:
                todoList.displayTasks();
                break;
            case 6:
                fileHandler.saveTodoList(todoList);
                std::cout << "Tasks saved. Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}