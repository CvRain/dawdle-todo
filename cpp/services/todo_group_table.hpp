//
// Created by cvrain on 24-6-13.
//

#ifndef DAWDLE_TODO_TODO_GROUP_TABLE_HPP
#define DAWDLE_TODO_TODO_GROUP_TABLE_HPP

#include <string>
#include <string_view>
#include <optional>
#include <spdlog/spdlog.h>

#include "model/todo_group.hpp"
#include "database_service.hpp"

namespace Service {

    class TodoGroupTable {
    public:
        static std::string add_one(const Model::TodoGroup &todo_group);
        static void print_all();
    };
}


#endif //DAWDLE_TODO_TODO_GROUP_TABLE_HPP
