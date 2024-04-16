#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include <cassert>

#include "Utils.h"
#include "MoveGenerator.h"

class Translation {
    std::vector<uint32_t > square_to_index;
    const uint32_t size;
    uint32_t number_of_indices = 0;

    [[nodiscard]] uint32_t square_to_number(Square square) const {
        return square.row * size + square.file;
    }

public:
    uint32_t get_index(Square square) {
        return square_to_index[square_to_number(square)];
    }

    uint32_t append_index(Square square) {
        square_to_index[square_to_number(square)] = number_of_indices;
        return number_of_indices++;
    }

    explicit Translation(uint32_t size) : size(size), square_to_index(size * size) {};
};

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

class Board {
    Position& position;
    Translation translation;
    Board_Hash hash;
    MoveGenerator move_gen;
    uint32_t size;

public:
    Board(Position& pos, uint32_t size) : position(pos), translation(size), move_gen(position), size(size) {
        assert(position.squares.size() == size);

        for (uint32_t row = 0; row < size; ++row) {
            for (uint32_t file = 0; file < size; ++file) {
                Square square{row, file};
                Piece piece = position.get_piece(square);
                if (piece != NON) {
                    hash.add_piece(translation.append_index(square), piece);
                }
            }
        }
    };

    void make_move(Move move) {
        Square origin = move.origin.square;
        position.set_square(origin, NON);
        hash.remove_piece(translation.get_index(origin));

        Square destination = move.destination.square;
        Piece result = move.origin.piece  - 1; // Moving uses up one capture
        assert(result >= NIL); // Otherwise this piece had no captures left
        position.set_square(destination, result);
        hash.modify_piece(translation.get_index(destination), result);
    }

    void unmake_move(Move move) {
        Square origin = move.origin.square;
        Piece original = move.origin.piece; // Reinstate the original capture count
        position.set_square(origin, original);
        hash.add_piece(translation.get_index(origin), original);

        Square destination = move.destination.square;
        Piece previous = move.destination.piece;
        position.set_square(destination, previous);
        hash.modify_piece(translation.get_index(destination), previous);
    }

    [[nodiscard]] auto generate_moves() const {
        return move_gen.generate_moves();
    }

    void print() {
        for (uint32_t row = 0; row < size; ++row) {
            for (uint32_t file = 0; file < size; ++file) {
                Square square{row, file};
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
    Cost cost() {
        Cost cost = 0;
        for (uint32_t row = 1; row < size; ++row) {
            for (uint32_t file = 1; file < size; ++file) {
                Square square{row, file};
                Piece piece = position.get_piece(square);
                if (piece > NON) {
                    ++cost;
                }
            }
        }
        return cost;
    }
};