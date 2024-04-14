#pragma once

#include <cstdint>
#include <utility>
#include <vector>
#include <cassert>

using Piece = int8_t;
using Hash_Type = uint64_t;

constexpr Piece NIL = 0, ONE = 1, TWO = 2, NON = -1;

struct Position {
    std::vector<std::vector<Piece>> squares;

    Piece get_piece(uint32_t row, uint32_t file) {
        return squares[row][file];
    }

    explicit Position(std::vector<std::vector<Piece>> configuration) :
                        squares(std::move(configuration)) {};
};

struct Translation {
    std::vector<uint32_t > square_to_index;
    const uint32_t size;
    uint32_t number_of_indices = 0;

    [[nodiscard]] uint32_t two_d_to_one_d(uint32_t row, uint32_t file) const {
        return row * size + file;
    }

    uint32_t get_index(uint32_t row, uint32_t file) {
        return square_to_index[two_d_to_one_d(row, file)];
    }

    uint32_t append_index(uint32_t row, uint32_t file) {
        square_to_index[two_d_to_one_d(row, file)] = number_of_indices;
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
        hash |= (piece & 3) << index;
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
                Piece piece = position.get_piece(row, file);
                if (piece != NON) {
                    hash.add_piece(translation.append_index(row, file), piece);
                }
            }
        }

        std::cout << hash.get_hash() << std::endl;
    };
};