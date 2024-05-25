//
// Created by cvrain on 24-5-24.
//
#include "todo_structure.hpp"
#include "simple_id.hpp"

#include <spdlog/spdlog.h>

namespace TodoStructure{
    std::string QueryStructure::get_delete_group_query(const std::string_view& group_id) const{
        spdlog::info("QueryStructure::get_delete_group_query");
        //delete from todo_group where id = '{}' 将{}替换为group_id
        if(group_id.empty()) return "";
        return std::string(delete_todo_group).replace(delete_todo_group.find("{}"), 2, group_id);
    }

    std::string QueryStructure::get_new_group_query(const std::string_view& group_name, const std::string_view& category) const {
        spdlog::info("QueryStructure::get_new_group_query");

        const auto id = Tool::Id::SimpleId::generate_id();
        spdlog::info("Generate new id:{}", id);

        const auto create_time = Tool::Id::SimpleId::local_timestamp_format_string();
        spdlog::info("Generate new create_time:{}", create_time);

        size_t pos = 0;
        std::string result = new_todo_group;
        result.replace(result.find("{}"), 2, id);
        pos = result.find("{}", pos + id.length());

        result.replace(pos, 2, std::string(group_name));
        pos = result.find("{}", pos + group_name.length());

        result.replace(pos, 2, std::string(category));
        pos = result.find("{}", pos + category.length());

        result.replace(pos, 2, create_time);

        return result;
    }

    std::string QueryStructure::get_new_group_query(const TodoGroupInfo &group_info) const {
        spdlog::info("QueryStructure::get_new_group_query");

        const auto id = [&](){
            if(group_info.group_id.empty()){
                spdlog::info("Generate new id");
                return Tool::Id::SimpleId::generate_id();
            }
            return group_info.group_id;
        }();
        const auto name = group_info.group_name;

        const auto category = group_info.category;

        size_t pos = 0;
        std::string result = new_todo_group;
        result.replace(result.find("{}"), 2, id);
        pos = result.find("{}", pos + id.length());
        result.replace(pos, 2, std::string(name));
        pos = result.find("{}", pos + name.length());
        result.replace(pos, 2, std::string(category));
        pos = result.find("{}", pos + category.length());
        result.replace(pos, 2, Tool::Id::SimpleId::local_timestamp_format_string());
        return result;
    }
}