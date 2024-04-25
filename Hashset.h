#pragma once

#include <cstdint>
#include <array>
#include <vector>

using higher_bits = uint32_t;

static constexpr uint32_t depth_threshold = 17, node_threshold = 100;

template<uint64_t TABLE_SIZE = 735733753> //486347359> //26710193> // large prime number
class Hashset {
    struct alignas(32) Bucket {
        higher_bits entries[8];
    };

    std::vector<Bucket> table;
    uint64_t fill = 0;

public:
    Hashset() : table(TABLE_SIZE) {};

    void put(uint64_t index, int16_t value, uint32_t depth, uint64_t node_cost) {
        if (depth < depth_threshold && node_cost > node_threshold) {
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
    }

    /**
     *
     * @param index
     * @return -1 if entry not found, 100 if found. This is effectively a hack and should be a bool function, however,
     * for compatibility reasons it is this way.
     */
    int16_t get(uint64_t index, uint32_t depth) {
        if (depth < depth_threshold) {
            uint64_t tt_index = index % TABLE_SIZE;
            uint64_t tt_remainder = index / TABLE_SIZE + 1; // to ensure that 0 is unique for empty entries

            auto &bucket = table[tt_index];
            for (auto &entry: bucket.entries) {
                if (entry == tt_remainder) {
                    return 100;
                }
            }
        }
        return -1;
    }

    uint32_t get_fill_permil() {
        uint64_t expanded = fill * 1000;
        uint64_t buckets = expanded / 8;
        uint32_t permil = buckets / TABLE_SIZE;
        return permil;
    }
};