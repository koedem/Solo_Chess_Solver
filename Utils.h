#pragma once

#include <array>

using Piece = int8_t;
using Hash_Type = uint64_t;
using Cost = int16_t;

constexpr Piece NON = 0, NIL = 1, ONE = 2, TWO = 3; // Offset by one so that 0 corresponds to an empty square

using Square = uint32_t;

template<uint32_t BOARD_SIZE>
uint32_t row_of(Square square) {
    return square / BOARD_SIZE;
}

template<uint32_t BOARD_SIZE>
uint32_t file_of(Square square) {
    return square % BOARD_SIZE;
}

template<uint32_t BOARD_SIZE>
uint32_t square_from_row_file(uint32_t row, uint32_t file) {
    return row * BOARD_SIZE + file;
}

template<uint32_t BOARD_SIZE>
struct Placed_Piece {
    Square square;
    Piece piece;

    [[nodiscard]] uint32_t row() const {
        return row_of<BOARD_SIZE>(square);
    }

    [[nodiscard]] uint32_t file() const {
        return file_of<BOARD_SIZE>(square);
    }
};

template<uint32_t BOARD_SIZE>
struct Move {
    Placed_Piece<BOARD_SIZE> origin, destination;

    void print() const {
        std::cout << origin.row() << "-" << origin.file() << " (" << origin.piece - 1 << ") --> ";
        std::cout << destination.row() << "-" << destination.file() << " (" << destination.piece - 1 << ")";
    }
};

template<uint32_t BOARD_SIZE>
class Position {

    std::array<Piece, BOARD_SIZE * BOARD_SIZE> squares;

public:
    [[nodiscard]] Piece get_piece(Square square) const {
        return squares[square];
    }

    void set_square(Square square, Piece piece) {
        squares[square] = piece;
    }

    explicit Position(std::vector<std::vector<Piece>> configuration) {
        for (uint32_t row = 0; row < BOARD_SIZE; ++row) {
            for (uint32_t file = 0; file < BOARD_SIZE; ++file) {
                squares[square_from_row_file<BOARD_SIZE>(row, file)] = configuration[row][file];
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
        return square_to_index[square];
    }

    [[nodiscard]] Square get_square(uint32_t index) const {
        return index_to_square[index];
    }

    uint32_t append_index(Square square) {
        square_to_index[square] = number_of_indices;
        index_to_square[number_of_indices] = square;
        return number_of_indices++;
    }

    Translation() {
        index_to_square.fill(BOARD_SIZE * BOARD_SIZE); // Big values for indices that aren't in use
    }
};
