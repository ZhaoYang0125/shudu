#pragma once


extern int n_finals;		// number of final results
extern char* input;			// file path of games (both relative and absolute path are ok)
extern int n_games;			// number of games to be generated
extern int n_difficulty;	// difficulty (easy, middle or hard, default is easy)
extern int n_blanks;		// number of blanks
extern bool unique;			// whether solution is unique (default is not)

void generate_finals();		// generate final results depending on `n_finals`
void generate_games();		// generate games depending on `n_games`
void solve_games();			// solve games in file `input` and dump to `sudoku.txt`

class Sudoku
{

};

