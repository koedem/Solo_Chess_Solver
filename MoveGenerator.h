#pragma once

#include <vector>
#include <cstdint>
#include "Utils.h"

template<uint32_t BOARD_SIZE>
class MoveGenerator {
    const Position<BOARD_SIZE>& position;
    const Translation<BOARD_SIZE>& translation;

    void generate_moves(std::vector<Move<BOARD_SIZE>>& moves, Square square) const {
        uint32_t row = row_of<BOARD_SIZE>(square), file = file_of<BOARD_SIZE>(square);
        Placed_Piece<BOARD_SIZE> us{square, position.get_piece(square)};
        while (row > 0) {
            --row;
            Square adjacent = square_from_row_file<BOARD_SIZE>(row, file);
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move<BOARD_SIZE> move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
        }

        row = row_of<BOARD_SIZE>(square) + 1;
        while (row < BOARD_SIZE) {
            Square adjacent = square_from_row_file<BOARD_SIZE>(row, file);
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move<BOARD_SIZE> move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
            ++row;
        }
        row = row_of<BOARD_SIZE>(square);

        while (file > 0) {
            --file;
            Square adjacent = square_from_row_file<BOARD_SIZE>(row, file);
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move<BOARD_SIZE> move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
        }

        file = file_of<BOARD_SIZE>(square) + 1;
        while (file < BOARD_SIZE) {
            Square adjacent = square_from_row_file<BOARD_SIZE>(row, file);
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move<BOARD_SIZE> move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
            ++file;
        }
    }

public:

    [[nodiscard]] std::vector<Move<BOARD_SIZE>> generate_moves() const {
        std::vector<Move<BOARD_SIZE>> moves;
        Square square;
        for (uint32_t index = 0; (square = translation.get_square(index)) < BOARD_SIZE * BOARD_SIZE ;++index) {
            Piece piece = position.get_piece(square);

            if (piece > NIL) {
                generate_moves(moves, square);
            }
        }
        return moves;
    }

    MoveGenerator(const Position<BOARD_SIZE>& position, const Translation<BOARD_SIZE>& translation)
                            : position(position), translation(translation) {};
};