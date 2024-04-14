#include <iostream>
#include "Board.h"
#include "DFS.h"

int main() {
    int size = 2;
    std::vector<std::vector<Piece >> example = { { ONE, NON }, { TWO, NIL } };
    Position position(example);
    Board board(position, size);
    board.print();

    auto moves = board.generate_moves();
    for (auto move : moves) {
        move.print();
        std::cout << std::endl;
    }

    DFS dfs(board);
    dfs.root_dfs();
    return 0;
}
