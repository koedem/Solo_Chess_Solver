#pragma once

#include <cstdint>


template<uint64_t TABLE_SIZE = 735733753, uint32_t ENTRIES_PER_BUCKET = 6> //280476641> // large prime number  403713413;
class Hashtable {
    struct alignas(32) Bucket {
        uint32_t hashes[ENTRIES_PER_BUCKET] = {};
        uint8_t infos[ENTRIES_PER_BUCKET] = {};
        uint8_t present_entries = 0;
        uint8_t lru_flags = 0;
    };

    std::vector<Bucket> table;
    uint64_t fill = 0;

public:
    Hashtable() : table(TABLE_SIZE) {};

    void put(uint64_t index, uint32_t depth, uint64_t node_cost) {
        if (depth >= tt_depth_threshold || node_cost <= tt_node_threshold) {
            return;
        }
        uint64_t tt_index = index % TABLE_SIZE;
        uint64_t tt_remainder = index / TABLE_SIZE;
        uint8_t info = node_cost; // TODO use log or something

        auto& bucket = table[tt_index];
        if (bucket.present_entries < ENTRIES_PER_BUCKET) {
            bucket.hashes[bucket.present_entries] = tt_remainder;
            bucket.infos[bucket.present_entries] = info;
            ++bucket.present_entries;
            ++fill;
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

    uint32_t get_fill_permil() {
        uint64_t expanded = fill * 1000;
        uint64_t buckets = expanded / ENTRIES_PER_BUCKET;
        uint32_t permil = buckets / TABLE_SIZE;
        return permil;
    }
};