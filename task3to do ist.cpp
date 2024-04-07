#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void printTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list." << std::endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "===== To-Do List Manager =====" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Task newTask;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, newTask.description);
                newTask.completed = false;
                tasks.push_back(newTask);
                break;
            }
            case 2: {
                printTasks(tasks);
                break;
            }
            case 3: {
                printTasks(tasks);
                if (!tasks.empty()) {
                    int index;
                    std::cout << "Enter the index of the task to delete: ";
                    std::cin >> index;
                    if (index >= 1 && index <= tasks.size()) {
                        tasks.erase(tasks.begin() + index - 1);
                    } else {
                        std::cout << "Invalid index. Please try again." << std::endl;
                    }
                }
                break;
            }
            case 4: {
                std::cout << "Exiting program." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
