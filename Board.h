#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include <cassert>

#include "Utils.h"
#include "MoveGenerator.h"

struct Board_Hash {
    Hash_Type hash = 0;

    [[nodiscard]] Hash_Type get_hash() const {
        return hash;
    }

    void add_piece(uint32_t index, Piece piece) {
        hash |= (piece & 3ull) << (index * 2); // One piece takes two bits, so shift by twice the index
    }

    void remove_piece(uint32_t index) {
        hash &= ~(3ull << (index * 2));
    }

    void modify_piece(uint32_t index, Piece piece) {
        remove_piece(index);
        add_piece(index, piece);
    }
};

template<uint32_t BOARD_SIZE>
class Board {
    Position<BOARD_SIZE>& position;
    Translation<BOARD_SIZE> translation;
    Board_Hash hash;
    MoveGenerator<BOARD_SIZE> move_gen;

    Cost current_cost = 0;

    /**
     * Counts the number of remaining pieces outside the first row and file
     * @return
     */
    Cost calculate_cost() {
        Cost cost = 0;
        for (uint32_t row = 1; row < BOARD_SIZE; ++row) {
            for (uint32_t file = 1; file < BOARD_SIZE; ++file) {
                Square square = square_from_row_file<BOARD_SIZE>(row, file);
                Piece piece = position.get_piece(square);
                if (piece > NON) {
                    if (file == BOARD_SIZE - 1) {
                        ++cost;
                    } else {
                        cost += 10; // avoid nonsense solutions and make sure clauses get cleared and only the output may be left 0
                    }
                }
            }
        }
        return cost;
    }

    Cost cost_change(Move<BOARD_SIZE>& move) {
        Cost cost = 0;
        if (move.origin.row() > 0 && move.origin.file() > 0) {
            cost = -1;
            if (move.origin.file() != BOARD_SIZE - 1) {
                cost = -10;
            }
        }
        return cost;
    }

public:
    explicit Board(Position<BOARD_SIZE>& pos) : position(pos), move_gen(position, translation) {
        for (Square square = 0; square < BOARD_SIZE * BOARD_SIZE; ++square) {
            Piece piece = position.get_piece(square);
            if (piece != NON) {
                hash.add_piece(translation.append_index(square), piece);
            }
        }
        current_cost = calculate_cost();
    };

    void make_move(Move<BOARD_SIZE> move) {
        Square origin = move.origin.square;
        position.set_square(origin, NON);
        hash.remove_piece(translation.get_index(origin));

        Square destination = move.destination.square;
        Piece result = move.origin.piece  - 1; // Moving uses up one capture
        assert(result >= NIL); // Otherwise this piece had no captures left
        position.set_square(destination, result);
        hash.modify_piece(translation.get_index(destination), result);

        current_cost += cost_change(move);
    }

    void unmake_move(Move<BOARD_SIZE> move) {
        Square origin = move.origin.square;
        Piece original = move.origin.piece; // Reinstate the original capture count
        position.set_square(origin, original);
        hash.add_piece(translation.get_index(origin), original);

        Square destination = move.destination.square;
        Piece previous = move.destination.piece;
        position.set_square(destination, previous);
        hash.modify_piece(translation.get_index(destination), previous);

        current_cost -= cost_change(move);
    }

    [[nodiscard]] auto generate_moves() const {
        return move_gen.generate_moves();
    }

    void print() {
        for (uint32_t row = 0; row < BOARD_SIZE; ++row) {
            for (uint32_t file = 0; file < BOARD_SIZE; ++file) {
                Square square = square_from_row_file<BOARD_SIZE>(row, file);
                Piece piece = position.get_piece(square);
                if (piece > NON) {
                    std::cout << piece - 1;
                } else {
                    std::cout << "-";
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    Hash_Type get_hash() {
        return hash.get_hash();
    }

    /**
     * Counts the number of remaining pieces outside the first row and file
     * @return
     */
    [[nodiscard]] Cost cost() const {
        assert(current_cost == calculate_cost());
        return current_cost;
    }
};