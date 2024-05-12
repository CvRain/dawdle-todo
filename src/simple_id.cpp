//
// Created by cvrain on 24-5-12.
//

#include "simple_id.hpp"

namespace Tool::Id {
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
        const auto local_time = local_timestamp();
        std::seed_seq seed{local_time};
        std::mt19937 generator{seed};
        std::uniform_int_distribution<int> distribution(0, 'Z'-'0');
        std::string random_str;
        random_str.reserve(size);
        for (uint32_t i = 0; i < size; ++i) {
            random_str.push_back(static_cast<char>(distribution(generator)));
        }
        return random_str;
    }

    //时间戳—四位随机数—存储组个数
    std::string SimpleId::generate_id() {
        const auto time_str = local_timestamp_string();
        const auto random_str = random_string(4);
        const auto count = std::to_string(SingletonDatabase::get_instance().size() + 1);
        return time_str + random_str + count;
    }
} // Tool