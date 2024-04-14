#pragma once

#include <unordered_map>
#include <iostream>
#include <utility>
#include "Board.h"

struct Entry {

};

class DFS {
    Board board;
    std::unordered_map<Hash_Type, Entry> expanded_positions;
    uint32_t counter = 0;

    void dfs() {
        ++counter;
        auto moves = board.generate_moves();
        for (auto move : moves) {
            board.make_move(move);

            auto hash = board.get_hash();
            if (!expanded_positions.contains(hash)) {
                dfs();
                expanded_positions.emplace(hash, Entry{});
            }

            board.unmake_move(move);
        }
    }

public:
    void root_dfs() {
        dfs();
        std::cout << counter << std::endl;
    }

    explicit DFS(Board board) : board(std::move(board)) {};
};