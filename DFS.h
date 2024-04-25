#pragma once

#include <iostream>
#include <utility>
#include "Board.h"
#include "Hashtable.h"
#include "Hashset.h"

template<uint32_t BOARD_SIZE>
class DFS {
    Board<BOARD_SIZE> board;
    Hashtable<> expanded_positions;
    uint64_t counter = 0;
    std::vector<Move<BOARD_SIZE>> pv;

    Cost best_cost = 50;

    void dfs(int depth) {
        if (board.cost() < best_cost) {
            best_cost = board.cost();
            std::cout << best_cost << std::endl;
            board.print();
            print_pv();
        }

        auto moves = board.generate_moves();
        for (auto move : moves) {
            ++counter;
            if ((counter & 0xFFFFFFF) == 0) {
                print_compact_pv();
            }

            board.make_move(move);
            pv[depth] = move;

            auto hash = board.get_hash();
            bool present = expanded_positions.get(hash, depth);
            if (!present) { // not expanded yet
                auto old_counter = counter;
                dfs(depth + 1);
                expanded_positions.put(hash, depth, counter - old_counter);
            }

            board.unmake_move(move);
            pv[depth] = Move<BOARD_SIZE>();
        }
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