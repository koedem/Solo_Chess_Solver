#include <iostream>
#include "Board.h"
#include "DFS.h"

void solve(const Board& board) {
    auto moves = board.generate_moves();
    for (auto move : moves) {
        move.print();
        std::cout << std::endl;
    }

    DFS dfs(board);
    dfs.root_dfs();
}

int main() {
    int size = 10;
    std::vector<std::vector<Piece >> old_variable_assigment = {
            { NON, NON, NON, NON, NON, NON, NON, TWO, NON, NIL },
            { NON, NON, NON, NON, NON, NON, NON, TWO, NON, NIL },
            { NON, NON, NON, NON, NON, NON, NON, TWO, TWO, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON },
            { TWO, TWO, NON, NON, TWO, NON, NON, TWO, NON, NON },
            { NON, NON, NON, TWO, TWO, NON, NON, NON, NON, NON },
            { NON, TWO, NON, NON, NON, NON, NON, NON, NON, NIL },
            { NON, TWO, TWO, NON, NON, NON, NON, NON, NON, NON },
            { NON, NON, TWO, NON, NON, NON, NON, NON, NON, NON },
            { TWO, TWO, NON, NON, NON, TWO, NON, NON, NON, NON }
    };

    std::vector<std::vector<Piece >> new_assignment = {
            { NON, NON, NON, NON, NON, NON, NON, NON, TWO, TWO },
            { NON, TWO, NON, NON, NON, NON, NON, NON, NON, NIL },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON },
            { TWO, TWO, NON, NON, NON, NON, NON, NON, NON, NON },
            { NON, TWO, TWO, NON, NON, NON, NON, NON, NON, NON },
            { NON, TWO, NON, NON, NON, NON, NON, NON, NIL, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON }
    };

    std::vector<std::vector<Piece >> double_assignment = {
            { NON, NON, NON, TWO, TWO, NON, NON, NON, TWO, TWO },
            { NON, TWO, NON, NON, NON, NON, NON, NON, NON, NON },
            { TWO, TWO, NON, NON, NON, NON, NON, NON, NON, NON },
            { NON, TWO, TWO, NON, NON, NON, NON, NON, NON, NON },
            { NON, TWO, NON, NIL, NON, NON, NON, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, TWO, NON, NON, NIL },
            { TWO, NON, NON, NON, NON, NON, TWO, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, TWO, TWO, NON, NON },
            { NON, NON, NON, NON, NON, NON, TWO, NON, NON, NON }
    };

    size = 11;
    std::vector<std::vector<Piece >> example = {
            { NON, NON, NON, NIL, NIL, NON, NON, NON, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON },
            { NON, NON, NON, NON, NIL, NON, TWO, NON, NON, TWO, NON },
            { NON, NON, NON, NIL, TWO, NON, TWO, NON, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON },
            { NON, TWO, NON, NON, NON, NON, TWO, TWO, NON, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON, NON },
            { NON, NON, TWO, NON, NON, NON, TWO, NON, TWO, NON, NON },
            { NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON },
            { TWO, NON, NON, NON, NON, TWO, TWO, NON, NON, NON, TWO },
            { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO }
    };

    Position position(example);
    Board board(position, size);
    board.print();

    solve(board);
    return 0;
}
