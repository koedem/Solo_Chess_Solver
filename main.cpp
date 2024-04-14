#include <iostream>
#include "Board.h"

int main() {
    int size = 2;
    std::vector<std::vector<Piece >> example = { { ONE, NON }, { TWO, NIL } };
    Position position(example);
    Board board(position, size);

    auto moves = board.generate_moves();
    for (auto move : moves) {
        move.print();
        std::cout << std::endl;
    }
    return 0;
}
