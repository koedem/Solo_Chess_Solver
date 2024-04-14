#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include <cassert>

using Piece = int8_t;
using Hash_Type = uint64_t;

constexpr Piece NON = 0, NIL = 1, ONE = 2, TWO = 3; // Offset by one so that 0 corresponds to an empty square

struct Square {
    uint32_t row, file;
};

struct Placed_Piece {
    Square square;
    Piece piece;
};

struct Move {
    Placed_Piece origin, destination;
};

struct Position {
    std::vector<std::vector<Piece>> squares;

    Piece get_piece(Square square) {
        return squares[square.row][square.file];
    }

    void set_square(Square square, Piece piece) {
        squares[square.row][square.file] = piece;
    }

    explicit Position(std::vector<std::vector<Piece>> configuration) :
                        squares(std::move(configuration)) {};
};

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

public:
    Board(Position pos, uint32_t size) : position(std::move(pos)), translation(size) {
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

        std::cout << hash.get_hash() << std::endl;
    };

    void make_move(Move move) {
        Square origin = move.origin.square;
        position.set_square(origin, NON);
        hash.remove_piece(translation.square_to_number(origin));

        Square destination = move.destination.square;
        Piece result = move.origin.piece  - 1; // Moving uses up one capture
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
};