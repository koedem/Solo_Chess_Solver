#pragma once

#include "Board.h"

std::array old_variable_assigment = {
        NON, NON, NON, NON, NON, NON, NON, TWO, NON, NIL,
        NON, NON, NON, NON, NON, NON, NON, TWO, NON, NIL,
        NON, NON, NON, NON, NON, NON, NON, TWO, TWO, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON,
        TWO, TWO, NON, NON, TWO, NON, NON, TWO, NON, NON,
        NON, NON, NON, TWO, TWO, NON, NON, NON, NON, NON,
        NON, TWO, NON, NON, NON, NON, NON, NON, NON, NIL,
        NON, TWO, TWO, NON, NON, NON, NON, NON, NON, NON,
        NON, NON, TWO, NON, NON, NON, NON, NON, NON, NON,
        TWO, TWO, NON, NON, NON, TWO, NON, NON, NON, NON
};
Position<10> old_variable_position_10(old_variable_assigment);

std::array new_assignment = {
        NON, NON, NON, NON, NON, NON, NON, NON, TWO, TWO,
        NON, TWO, NON, NON, NON, NON, NON, NON, NON, NIL,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON,
        TWO, TWO, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, TWO, TWO, NON, NON, NON, NON, NON, NON, NON,
        NON, TWO, NON, NON, NON, NON, NON, NON, NIL, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON
};
Position<10> new_variable_position_10(new_assignment);

std::array double_assignment = {
        NON, NON, NON, TWO, TWO, NON, NON, NON, TWO, TWO,
        NON, TWO, NON, NON, NON, NON, NON, NON, NON, NON,
        TWO, TWO, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, TWO, TWO, NON, NON, NON, NON, NON, NON, NON,
        NON, TWO, NON, NIL, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, TWO, NON, NON, NIL,
        TWO, NON, NON, NON, NON, NON, TWO, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, TWO, TWO, NON, NON,
        NON, NON, NON, NON, NON, NON, TWO, NON, NON, NON
};
Position<10> double_variable_position_10(double_assignment);

std::array and_gate = {
        NON, NON, NON, NIL, NIL, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON,
        NON, NON, NON, NON, NIL, NON, TWO, NON, NON, TWO, NON,
        NON, NON, NON, NIL, TWO, NON, TWO, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, TWO, NON, NON, NON, NON, TWO, TWO, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON, NON,
        NON, NON, TWO, NON, NON, NON, TWO, NON, TWO, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON,
        TWO, NON, NON, NON, NON, TWO, TWO, NON, NON, NON, TWO,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO
};
Position<11> zeroed_and(and_gate);

std::array expanded_and = {
        NON, NON, NON, NIL, NON, NIL, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON,
        NON, NON, NON, NON, TWO, NON, NON, NON, NON, NON, NON, NON,
        NON, NON, NON, NON, TWO, TWO, NON, TWO, NON, NON, TWO, NON,
        NON, NON, NON, NIL, NON, TWO, NON, TWO, NON, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON,
        NON, TWO, NON, NON, NON, NON, NON, TWO, TWO, NON, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON, NON,
        NON, NON, TWO, NON, NON, NON, NON, TWO, NON, TWO, NON, NON,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO, NON, NON,
        TWO, NON, NON, NON, NON, NON, TWO, TWO, NON, NON, NON, TWO,
        NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, NON, TWO
};
Position<12> full_and(expanded_and);

std::array improved_and_vec = {
        	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NIL, 	NON, 	NIL,
        	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON,
        	NON, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON,
        	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NIL,
        	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        	NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON,
        	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON,
        	NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON,
        	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON,
        	TWO, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON,
        	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON
};
Position<12> improved_and(improved_and_vec);

std::array big_or_vec = {
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NIL,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NIL,
        NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON,
        TWO, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON
};
Position<12> big_or(big_or_vec);

std::array small_or_vec = {
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NIL,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NIL,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	TWO, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON,
        TWO, 	NON, 	NON, 	NON, 	TWO, 	NON, 	TWO, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON
};
Position<9> small_or(small_or_vec);

std::array full_or_clause_vec = {
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NIL,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NIL,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON,
        NON, 	NON, 	TWO, 	NON, 	TWO, 	TWO, 	NON,    NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON,    NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        TWO, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON,
        TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	TWO, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON
};
Position<12> full_or_clause(full_or_clause_vec);

std::array and_or_clause_vec = {
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NIL, 	NON, 	NON, 	NON, 	NIL,
        NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NIL,
        NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	NON, 	TWO, 	TWO, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON,
        NON, 	TWO, 	NON, 	NON, 	NON, 	TWO, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON,
        NIL, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	NON, 	TWO, 	NON, 	NON, 	NON, 	NON, 	NON,
        NIL, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	TWO, 	NON, 	TWO,
        NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON, 	NON
};
Position<14> and_or_clause(and_or_clause_vec);
