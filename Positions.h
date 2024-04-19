#pragma once

#include "Board.h"

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
Position<10> old_variable_position_10(old_variable_assigment);

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
Position<10> new_variable_position_10(new_assignment);

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
Position<10> double_variable_position_10(double_assignment);

std::vector<std::vector<Piece >> and_gate = {
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
Position<11> zeroed_and(and_gate);

std::vector<std::vector<Piece >> expanded_and = {
        { NON, NON, NON, NIL, NON, NIL, NON, NON, NON, NON, NON, NON },
        { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON },
        { NON, NON, NON, NON, TWO, NON, NON, NON, NON, NON, NON, NON },
        { NON, NON, NON, NON, TWO, TWO, NON, TWO, NON, NON, TWO, NON },
        { NON, NON, NON, NIL, NON, TWO, NON, TWO, NON, NON, NON, NON },
        { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON },
        { NON, TWO, NON, NON, NON, NON, NON, TWO, TWO, NON, NON, NON },
        { NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON, NON },
        { NON, NON, TWO, NON, NON, NON, NON, TWO, NON, TWO, NON, NON },
        { NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON },
        { TWO, NON, NON, NON, NON, NON, TWO, TWO, NON, NON, NON, TWO },
        { NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO }
};
Position<12> full_and(expanded_and);

std::vector<std::vector<Piece >> improved_and_vec = {
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
Position<12> improved_and(improved_and_vec);
