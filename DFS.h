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
    std::vector<Move> pv;

    Cost best_cost = 1000;

    Cost dfs(int depth) {
        Cost value = board.cost();
        ++counter;
        auto moves = board.generate_moves();
        for (auto move : moves) {
            board.make_move(move);
            pv[depth] = move;

            Cost inner_value;
            auto hash = board.get_hash();
            if (!expanded_positions.contains(hash)) {
                inner_value = dfs(depth + 1);
                expanded_positions.emplace(hash, Entry{inner_value});
            } else {
                auto entry = expanded_positions.at(hash);
                inner_value = entry.cost;
            }
            if (hash != board.get_hash()) {
                int a = 0;
            }

            if (inner_value < value) { // If we can reduce the value by this move, update the value
                value = inner_value;
                if (value < best_cost) {
                    best_cost = value;
                    std::cout << best_cost << std::endl;
                    board.print();
                    print_pv();
                }
            }

            board.unmake_move(move);
            pv[depth] = Move();
        }

        return value;
    }

    void print_pv() {
        for (int i = 0; i < 100; i++) {
            if (pv[i].destination.square == pv[i].origin.square) { // Not a real move
                break;
            }
            pv[i].print();
            std::cout << std::endl;
        }
    }

public:
    void root_dfs() {
        dfs(0);
        std::cout << counter << std::endl;
    }

    explicit DFS(Board board) : board(std::move(board)), pv(100) {};
};