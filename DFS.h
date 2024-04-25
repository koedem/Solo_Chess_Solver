#pragma once

#include <iostream>
#include <utility>
#include "Board.h"
#include "Hashtable.h"
#include "Hashset.h"

template<uint32_t BOARD_SIZE>
class DFS {
    Board<BOARD_SIZE> board;
    Hashset<> expanded_positions;
    uint64_t counter = 0;
    std::vector<Move<BOARD_SIZE>> pv;

    Cost best_cost = 1000;

    Cost dfs(int depth) {
        Cost value = board.cost();
        auto moves = board.generate_moves();
        for (auto move : moves) {
            ++counter;
            if ((counter & 0xFFFFFFF) == 0) {
                print_compact_pv();
            }

            board.make_move(move);
            pv[depth] = move;

            Cost inner_value;
            auto hash = board.get_hash();
            bool present = expanded_positions.get(hash, depth);
            if (!present) { // not expanded yet
                auto old_counter = counter;
                inner_value = dfs(depth + 1);
                expanded_positions.put(hash, depth, counter - old_counter);
            } else {
                inner_value = value; // TODO this whole function can be a void function, we don't need to track value at all
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
            pv[depth] = Move<BOARD_SIZE>();
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

    void print_compact_pv() {
        for (int i = 0; i < 8; i++) {
            if (pv[i].destination.square == pv[i].origin.square) { // Not a real move
                break;
            }
            pv[i].print();
            std::cout << ",\t";
        }
        std::cout << expanded_positions.get_fill_permil() << std::endl;
    }

public:
    void root_dfs() {
        dfs(0);
        std::cout << counter << std::endl;
    }

    explicit DFS(Board<BOARD_SIZE> board) : board(std::move(board)), pv(100) {};
};