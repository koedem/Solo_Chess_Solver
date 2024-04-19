#pragma once

#include <array>

using Piece = int8_t;
using Hash_Type = uint64_t;
using Cost = int16_t;

constexpr Piece NON = 0, NIL = 1, ONE = 2, TWO = 3; // Offset by one so that 0 corresponds to an empty square

struct Square {
    uint32_t row, file;

    bool operator==(const Square& other) const {
        return row == other.row && file == other.file;
    }
};

template<uint32_t BOARD_SIZE>
uint32_t square_to_number(Square square) {
    return square.row * BOARD_SIZE + square.file;
}

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

template<uint32_t BOARD_SIZE>
class Position {

    std::array<Piece, BOARD_SIZE * BOARD_SIZE> squares;

public:
    [[nodiscard]] Piece get_piece(Square square) const {
        return squares[square_to_number<BOARD_SIZE>(square)];
    }

    [[nodiscard]] Piece get_piece(uint32_t square) const {
        return squares[square];
    }

    void set_square(Square square, Piece piece) {
        squares[square_to_number<BOARD_SIZE>(square)] = piece;
    }

    explicit Position(std::vector<std::vector<Piece>> configuration) {
        for (uint32_t row = 0; row < BOARD_SIZE; ++row) {
            for (uint32_t file = 0; file < BOARD_SIZE; ++file) {
                squares[square_to_number<BOARD_SIZE>({row, file})] = configuration[row][file];
            }
        }
    };
};

template<uint32_t BOARD_SIZE>
class Translation {
    std::array<uint32_t, BOARD_SIZE * BOARD_SIZE> square_to_index;
    std::array<uint32_t, BOARD_SIZE * BOARD_SIZE> index_to_square;
    uint32_t number_of_indices = 0;

public:
    uint32_t get_index(Square square) {
        return square_to_index[square_to_number<BOARD_SIZE>(square)];
    }

    [[nodiscard]] uint32_t get_square(uint32_t index) const {
        return index_to_square[index];
    }

    uint32_t append_index(Square square) {
        uint32_t square_number = square_to_number<BOARD_SIZE>(square);
        square_to_index[square_number] = number_of_indices;
        index_to_square[number_of_indices] = square_number;
        return number_of_indices++;
    }

    Translation() {
        index_to_square.fill(BOARD_SIZE * BOARD_SIZE); // Big values for indices that aren't in use
    }
};
