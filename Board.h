#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include <cassert>

#include "Utils.h"
#include "MoveGenerator.h"

struct Translation {
    std::vector<uint32_t > square_to_index;
    const uint32_t size;
    uint32_t number_of_indices = 0;

    [[nodiscard]] uint32_t square_to_number(Square square) const {
        return square.row * size + square.file;
    }

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

    Hash_Type get_hash() {
        return hash;
    }

    void add_piece(uint32_t index, Piece piece) {
        hash |= (piece & 3) << (index * 2); // One piece takes two bits, so shift by twice the index
    }

    void remove_piece(uint32_t index) {
        hash &= ~(3ull << index);
    }

    void modify_piece(uint32_t index, Piece piece) {
        remove_piece(index);
        add_piece(index, piece);
    }
};

class Board {
    Position position;
    Translation translation;
    Board_Hash hash;
    MoveGenerator move_gen;

public:
    Board(Position pos, uint32_t size) : position(std::move(pos)), translation(size), move_gen(position) {
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
        hash.remove_piece(translation.square_to_number(origin));

        Square destination = move.destination.square;
        Piece result = move.origin.piece  - 1; // Moving uses up one capture
        assert(result >= NIL); // Otherwise this piece had no captures left
        position.set_square(destination, result);
        hash.modify_piece(translation.square_to_number(destination), result);
    }

    void unmake_move(Move move) {
        Square origin = move.origin.square;
        Piece original = move.origin.piece; // Reinstate the original capture count
        position.set_square(origin, original);
        hash.add_piece(translation.square_to_number(origin), original);

        Square destination = move.destination.square;
        Piece previous = move.destination.piece;
        position.set_square(destination, previous);
        hash.modify_piece(translation.square_to_number(destination), previous);
    }

    auto generate_moves() {
        return move_gen.generate_moves();
    }
};