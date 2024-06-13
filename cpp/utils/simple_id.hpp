//
// Created by cvrain on 24-5-12.
//

#ifndef DAWDLE_TODO_SIMPLE_ID_HPP
#define DAWDLE_TODO_SIMPLE_ID_HPP

#include <string>
#include <cstdint>

namespace Util {
    class SimpleId {
    public:
        static uint32_t  local_timestamp();
        static std::string local_timestamp_string();
        static std::string local_timestamp_format_string();
        static std::string random_string(uint32_t size);
        static std::string local_time_second();
        static std::string generate();
    };

} // Util

#endif //DAWDLE_TODO_SIMPLE_ID_HPP
