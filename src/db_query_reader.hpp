//
// Created by cvrain on 24-5-17.
//

#ifndef DAWDLE_TODO_DB_QUERY_READER_HPP
#define DAWDLE_TODO_DB_QUERY_READER_HPP

#include <QFile>
#include "todo_structure.h"

class DbQueryReader {
public:
    explicit DbQueryReader();
    [[nodiscard]] TodoStructure::QueryStructure get_query_structure() const;
private:
    static std::string read_file();
    void init_query_structure(const std::string& json_string);

private:
    TodoStructure::QueryStructure query_structure;
};


#endif //DAWDLE_TODO_DB_QUERY_READER_HPP
