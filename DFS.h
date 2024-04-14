#pragma once

#include <unordered_map>
#include <iostream>
#include <utility>
#include "Board.h"

struct Entry {
    Cost cost;
};

class DFS {
    Board board;
    std::unordered_map<Hash_Type, Entry> expanded_positions;
    uint32_t counter = 0;

    Cost best_cost = 1000;

    Cost dfs() {
        Cost value = board.cost();
        ++counter;
        auto moves = board.generate_moves();
        for (auto move : moves) {
            board.make_move(move);

            Cost inner_value;
            auto hash = board.get_hash();
            if (!expanded_positions.contains(hash)) {
                inner_value = dfs();
                expanded_positions.emplace(hash, Entry{inner_value});
            } else {
                auto entry = expanded_positions.at(hash);
                inner_value = entry.cost;
            }

            if (inner_value < value) { // If we can reduce the value by this move, update the value
                value = inner_value;
                if (value < best_cost) {
                    best_cost = value;
                    std::cout << best_cost << std::endl;
                    board.print();
                }
            }

            board.unmake_move(move);
        }

        return value;
    }

public:
    void root_dfs() {
        dfs();
        std::cout << counter << std::endl;
    }

    explicit DFS(Board board) : board(std::move(board)) {};
};