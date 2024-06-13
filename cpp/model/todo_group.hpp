//
// Created by cvrain on 24-6-11.
//

#ifndef DAWDLE_TODO_TODO_GROUP_HPP
#define DAWDLE_TODO_TODO_GROUP_HPP

#include <string>
#include <string_view>
#include "utils/simple_id.hpp"

namespace Model{
    struct TodoGroup{
        std::string id;
        std::string name;
        int times;
        std::string category;
        std::string create_time;
        std::string finish_time;
    };

    enum class TodoCategory{
        Cycle,
        Daily,
        Once,
        Property
    };

    inline std::string_view todo_category_to_string(TodoCategory category){
        switch (category) {
            case TodoCategory::Cycle:
                return "Cycle";
            case TodoCategory::Daily:
                return "Daily";
            case TodoCategory::Once:
                return "Once";
            case TodoCategory::Property:
                return "Property";
        }
        return "";
    }

    inline TodoGroup create_todo_group(const std::string_view& name, TodoCategory category, const std::string_view & create_time = ""){
        const auto todo_group = TodoGroup{
            .id = Util::SimpleId::generate(),
            .name = name.data(),
            .times = 0,
            .category = todo_category_to_string(category).data(),
            .create_time = create_time.empty() ? Util::SimpleId::local_timestamp_format_string() : create_time.data(),
            .finish_time = ""
        };
        return todo_group;
    }
}


#endif //DAWDLE_TODO_TODO_GROUP_HPP
