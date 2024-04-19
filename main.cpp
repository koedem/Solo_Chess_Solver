#include <iostream>
#include "Board.h"
#include "DFS.h"
#include "Positions.h"

template<uint32_t BOARD_SIZE>
void solve(const Board<BOARD_SIZE>& board) {
    auto moves = board.generate_moves();
    for (auto move : moves) {
        move.print();
        std::cout << std::endl;
    }

    DFS dfs(board);
    dfs.root_dfs();
}

int main() {
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

    Position<12> position(example);
    Board board(position), board2(full_and);
    board2.print();
    board.print();

    solve<12>(board);
    return 0;
}
