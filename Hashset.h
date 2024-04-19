#pragma once

#include <cstdint>
#include <array>
#include <vector>

using higher_bits = uint32_t;

template<uint64_t TABLE_SIZE = 486347359> // large prime number
class Hashset {
    struct alignas(32) Bucket {
        higher_bits entries[8];
    };

    std::vector<Bucket> table;

public:
    Hashset() : table(TABLE_SIZE) {};

    void put(uint64_t index, int16_t value) {
        uint64_t tt_index = index % TABLE_SIZE;
        uint64_t tt_remainder = index / TABLE_SIZE + 1; // to ensure that 0 is unique for empty entries

        auto& bucket = table[tt_index];
        for (auto& entry : bucket.entries) {
            if (entry == 0) {
                entry = tt_remainder;
                return;
            }
        }
    }

    /**
     *
     * @param index
     * @return -1 if entry not found, 100 if found. This is effectively a hack and should be a bool function, however,
     * for compatibility reasons it is this way.
     */
    int16_t get(uint64_t index) {
        uint64_t tt_index = index % TABLE_SIZE;
        uint64_t tt_remainder = index / TABLE_SIZE + 1; // to ensure that 0 is unique for empty entries

        auto& bucket = table[tt_index];
        for (auto& entry : bucket.entries) {
            if (entry == tt_remainder) {
                return 100;
            }
        }
        return -1;
    }
};