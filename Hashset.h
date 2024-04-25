#pragma once

#include <cstdint>
#include <array>
#include <vector>

using higher_bits = uint32_t;

template<uint64_t TABLE_SIZE = 735733753, uint32_t ENTRIES_PER_BUCKET = 8> //486347359> //26710193> // large prime number
class Hashset {
    struct alignas(32) Bucket {
        higher_bits entries[ENTRIES_PER_BUCKET];
    };

    std::vector<Bucket> table;
    uint64_t fill = 0;

public:
    Hashset() : table(TABLE_SIZE) {};

    void put(uint64_t index, uint32_t depth, uint64_t node_cost) {
        if (depth >= tt_depth_threshold || node_cost <= tt_node_threshold) {
            return;
        }
        uint64_t tt_index = index % TABLE_SIZE;
        uint64_t tt_remainder = index / TABLE_SIZE + 1; // to ensure that 0 is unique for empty entries

        auto &bucket = table[tt_index];
        for (auto &entry: bucket.entries) {
            if (entry == 0) {
                entry = tt_remainder;
                ++fill;
                return;
            }
        }
    }

    bool get(uint64_t index, uint32_t depth) {
        if (depth >= tt_depth_threshold) {
            return false;
        }
        uint64_t tt_index = index % TABLE_SIZE;
        uint64_t tt_remainder = index / TABLE_SIZE + 1; // to ensure that 0 is unique for empty entries

        auto &bucket = table[tt_index];
        for (auto &entry: bucket.entries) {
            if (entry == tt_remainder) {
                return true;
            }
        }
        return false;
    }

    uint32_t get_fill_permil() {
        uint64_t expanded = fill * 1000;
        uint64_t buckets = expanded / ENTRIES_PER_BUCKET;
        uint32_t permil = buckets / TABLE_SIZE;
        return permil;
    }
};