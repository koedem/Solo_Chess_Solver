#include <iostream>
#include "Board.h"

int main() {
    int size = 2;
    std::vector<std::vector<Piece >> example = { { 2, 0 }, { 0, 1 } };
    Position position(example);
    Board board(position, size);
    return 0;
}
