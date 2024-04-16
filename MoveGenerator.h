#pragma once

#include <vector>
#include <cstdint>
#include "Utils.h"

class MoveGenerator {
    const Position& position;
    const uint32_t size = position.squares.size();

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
        while (row < size) {
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
        while (file < size) {
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
        for (uint32_t row = 0; row < position.squares.size(); ++row) {
            for (uint32_t file = 0; file < position.squares.size(); ++file) {
                Square square = {row, file};
                Piece piece = position.get_piece(square);

                if (piece > NIL) {
                    generate_moves(moves, square);
                }
            }
        }
        return moves;
    }

    explicit MoveGenerator(const Position& position) : position(position) {};
};