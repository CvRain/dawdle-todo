//
// Created by cvrain on 24-5-12.
//

#ifndef DAWDLE_TODO_SIMPLE_ID_HPP
#define DAWDLE_TODO_SIMPLE_ID_HPP

#include <chrono>
#include <ctime>
#include <string>
#include <random>
#include <memory>

#include "duck_service.hpp"

namespace Tool::Id {
    class SimpleId {
    public:
        static uint32_t  local_timestamp();
        static std::string local_timestamp_string();
        static std::string random_string(uint32_t size);
        static std::string generate_id();
    };

} // Tool

#endif //DAWDLE_TODO_SIMPLE_ID_HPP
