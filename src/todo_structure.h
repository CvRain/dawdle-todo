//
// Created by cvrain on 24-5-9.
//

#ifndef DAWDLE_TODO_TODO_STRUCTURE_H
#define DAWDLE_TODO_TODO_STRUCTURE_H

#include <string>
#include <map>

namespace TodoStructure {
    enum class TodoCategory {
        Cycle,
        Daily,
        Once,
        Property
    };
    struct TodoGroupInfo {
        std::string group_name;
        std::string group_id;
        std::string category;
    };

    inline std::map<TodoCategory, std::string> TodoCategoryAsMap(){
        std::map<TodoCategory, std::string> category_map{};
        category_map[TodoCategory::Cycle] = "cycle";
        category_map[TodoCategory::Daily] = "daily";
        category_map[TodoCategory::Once] = "once";
        category_map[TodoCategory::Property] = "property";
        return category_map;
    }

    inline std::string TodoCategoryToString(TodoCategory category){
        static const auto& category_map = TodoCategoryAsMap(); // 只计算一次
        auto it = category_map.find(category);
        if (it != category_map.end()){
            return it->second;
        }
        return "unknown";
    }
}

#endif //DAWDLE_TODO_TODO_STRUCTURE_H
