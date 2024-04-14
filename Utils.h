#pragma once

using Piece = int8_t;
using Hash_Type = uint64_t;
using Cost = int32_t;

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

    void print() const {
        std::cout << origin.square.row << "-" << origin.square.file << " (" << origin.piece - 1 << ") --> ";
        std::cout << destination.square.row << "-" << destination.square.file << " (" << destination.piece - 1 << ")";
    }
};

struct Position {
    std::vector<std::vector<Piece>> squares;

    [[nodiscard]] Piece get_piece(Square square) const {
        return squares[square.row][square.file];
    }

    void set_square(Square square, Piece piece) {
        squares[square.row][square.file] = piece;
    }

    explicit Position(std::vector<std::vector<Piece>> configuration) :
            squares(std::move(configuration)) {};
};