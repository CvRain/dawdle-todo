//
// Created by cvrain on 24-5-8.
//

#ifndef DAWDLE_TODO_TODO_MANAGER_HPP
#define DAWDLE_TODO_TODO_MANAGER_HPP

#include <utility>
#include <vector>
#include <string>

class TodoManager {
public:
    explicit TodoManager() = default;
    std::vector<std::string> get_all_todo_key();
    std::vector<std::string> get__all_todo_value();
};


#endif //DAWDLE_TODO_TODO_MANAGER_HPP
