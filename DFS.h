#pragma once

#include <iostream>
#include <utility>
#include "Board.h"
#include "Hashtable.h"

class DFS {
    Board board;
    Hashtable expanded_positions;
    uint32_t counter = 0;
    std::vector<Move> pv;

    Cost best_cost = 1000;

    Cost dfs(int depth) {
        Cost value = board.cost();
        auto moves = board.generate_moves();
        for (auto move : moves) {
            ++counter;
            board.make_move(move);
            pv[depth] = move;

            Cost inner_value;
            auto hash = board.get_hash();
            int16_t cost = expanded_positions.get(hash);
            if (cost == -1) { // not expanded yet
                inner_value = dfs(depth + 1);
                expanded_positions.put(hash, inner_value);
            } else {
                inner_value = cost;
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