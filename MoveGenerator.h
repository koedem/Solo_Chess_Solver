#pragma once

#include <vector>
#include <cstdint>
#include "Utils.h"

template<uint32_t BOARD_SIZE>
class MoveGenerator {
    const Position<BOARD_SIZE>& position;

    void generate_moves(std::vector<Move>& moves, Square square) const {
        Placed_Piece us{square, position.get_piece(square)};
        uint32_t row = square.row;
        while (row > 0) {
            --row;
            Square adjacent{row, square.file};
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
        }

        row = square.row + 1;
        while (row < BOARD_SIZE) {
            Square adjacent{row, square.file};
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
            ++row;
        }


        uint32_t file = square.file;
        while (file > 0) {
            --file;
            Square adjacent{square.row, file};
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
        }

        file = square.file + 1;
        while (file < BOARD_SIZE) {
            Square adjacent{square.row, file};
            Piece adjacent_piece = position.get_piece(adjacent);

            if (adjacent_piece >= NIL) { // At least a 0 rook, i.e. non-empty
                Move move{us, {adjacent, adjacent_piece}};
                moves.emplace_back(move);
                break;
            }
            ++file;
        }
    }

public:

    [[nodiscard]] std::vector<Move> generate_moves() const {
        std::vector<Move> moves;
        for (uint32_t row = 0; row < BOARD_SIZE; ++row) {
            for (uint32_t file = 0; file < BOARD_SIZE; ++file) {
                Square square = {row, file};
                Piece piece = position.get_piece(square);

                if (piece > NIL) {
                    generate_moves(moves, square);
                }
            }
        }
        return moves;
    }

    explicit MoveGenerator(const Position<BOARD_SIZE>& position) : position(position) {};
};