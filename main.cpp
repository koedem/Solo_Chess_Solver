#include <iostream>
#include "Board.h"

int main() {
    int size = 2;
    std::vector<std::vector<Piece >> example = { { 2, -1 }, { 0, 0 } };
    Position position(example);
    Board board(position, size);
    return 0;
}
