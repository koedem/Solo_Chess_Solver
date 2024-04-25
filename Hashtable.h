#pragma once

#include <cstdint>


template<uint64_t TABLE_SIZE = 735733753> //280476641> // large prime number  403713413;
class Hashtable {
    struct alignas(32) Bucket {
        uint32_t hashes[6] = {};
        uint8_t infos[6] = {};
        uint8_t present_entries = 0;
        uint8_t lru_flags = 0;
    };

    std::vector<Bucket> table;

public:
    Hashtable() : table(TABLE_SIZE) {};

    void put(uint64_t index, int32_t depth, uint64_t node_cost) {
        if (depth >= tt_depth_threshold && node_cost <= tt_node_threshold) {
            return;
        }
        uint64_t tt_index = index % TABLE_SIZE;
        uint64_t tt_remainder = index / TABLE_SIZE;
        uint8_t info = node_cost; // TODO use log or something

        auto& bucket = table[tt_index];
        if (bucket.present_entries < 6) {
            bucket.hashes[bucket.present_entries] = tt_remainder;
            bucket.infos[bucket.present_entries] = info;
            ++bucket.present_entries;
        } else {
            // replace lowest cost value
        }
    }

    bool get(uint64_t index, uint32_t depth) {
        if (depth >= tt_depth_threshold) {
            return false;
        }
        uint64_t tt_index = index % TABLE_SIZE;
        uint64_t tt_remainder = index / TABLE_SIZE;

        auto& bucket = table[tt_index];
        for (int i = 0; i < bucket.present_entries; ++i) {
            if (bucket.hashes[i] == tt_remainder) {
                // TODO maybe do LRU bit stuff later
                return true;
            }
        }
        return false;
    }
};