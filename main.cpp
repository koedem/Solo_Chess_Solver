#include <iostream>
#include "Board.h"
#include "DFS.h"
#include "Positions.h"

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
    int size = 12;
    std::vector<std::vector<Piece >> example = {
            {	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NIL, 	NON, 	NIL 	},
            {	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON 	},
            {	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON 	},
            {	NON, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON 	},
            {	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NIL 	},
            {	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON 	},
            {	NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON 	},
            {	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON 	},
            {	NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON 	},
            {	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON 	},
            {	TWO, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON 	},
            {	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON 	}
    };

    Position position(example);
    Board board(position, size), board2(full_and_12, 12);
    board2.print();
    board.print();

    solve(board);
    return 0;
}
