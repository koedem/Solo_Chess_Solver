#pragma once

#include <cstdint>

struct TT_Entry {
    uint32_t lower_bits;
    uint16_t higher_bits;
    int16_t value;
};

struct alignas(64) Bucket {
    TT_Entry entries[8];
};

class Hashtable {
    uint64_t table_size = 280476641; // large prime number  403713413;
    std::vector<Bucket> table;

public:
    Hashtable() : table(table_size) {};

    void put(uint64_t index, int16_t value) {
        uint64_t tt_index = index % table_size;
        uint64_t tt_remainder = index / table_size + 1; // to ensure that 0 is unique for empty entries

        auto& bucket = table[tt_index];
        for (auto & entry : bucket.entries) {
            if (entry.higher_bits == 0 && entry.lower_bits == 0) {
                entry.value = value;
                entry.lower_bits = tt_remainder & 0xFFFFFFFF;
                entry.higher_bits = (tt_remainder >> 32);
                return;
            }
        }
    }

    int16_t get(uint64_t index) {
        uint64_t tt_index = index % table_size;
        uint64_t tt_remainder = index / table_size + 1; // to ensure that 0 is unique for empty entries

        auto& bucket = table[tt_index];
        for (auto & entry : bucket.entries) {
            uint64_t bits = ((uint64_t) entry.higher_bits << 32) + entry.lower_bits;
            if (bits == tt_remainder) {
                return entry.value;
            }
        }
        return -1;
    }
};