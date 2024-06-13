//
// Created by cvrain on 24-5-12.
//

#include "simple_id.hpp"
#include <chrono>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>

namespace Util {
    uint32_t SimpleId::local_timestamp() {
        return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count());
    }

    std::string SimpleId::local_timestamp_string() {
        const auto timestamp = local_timestamp();
        return std::to_string(timestamp);
    }

    //根据时间戳和size创建一个长度为size的随机字符串, 字符包括0~9 a-Z
    std::string SimpleId::random_string(uint32_t size) {
        // 使用时间戳作为种子
        std::random_device rd;
        std::mt19937 gen(rd());

        // 生成随机字符
        std::string str(size, 0);
        std::uniform_int_distribution<> dis('a', 'z');
        for (char &c: str) {
            c = static_cast<char>(dis(gen));
        }
        return str;
    }

    //两位当前时间的秒数
    std::string SimpleId::local_time_second() {
        const auto time = std::chrono::system_clock::now();
        const auto time_t = std::chrono::system_clock::to_time_t(time);
        const auto tm = *std::localtime(&time_t);
        const auto second = tm.tm_sec;
        return std::to_string(second);
    }

    //时间戳—四位随机数—当前时间秒数
    std::string SimpleId::generate() {
        const auto time_str = local_timestamp_string();
        const auto random_str = random_string(8);
        const auto count = local_time_second();
        return time_str + random_str + count;
    }

    std::string SimpleId::local_timestamp_format_string() {
        //生成yyyy-MM-dd HH:mm:ss格式的当前时间
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");

        return ss.str();
    }
} // Utils
