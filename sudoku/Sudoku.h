#pragma once
#include <iostream>

/* limitations */
const int MIN_FINALE = 1;			// minimum of final results
const int MAX_FINALE = (int)1e6;	// maximum of final results

const int MIN_PUZZLE = 1;			// minimum of games
const int MAX_PUZZLE = (int)1e4;	// maximum of games

const int MIN_DIFFICULTY = 1;		// minimum of difficulty
const int MAX_DIFFICULTY = 3;		// maximum of difficulty

const int MIN_BLANK = 20;			// minimum of blanks
const int MAX_BLANK = 55;			// maximum of blanks

const char output[] = "sudoku.txt";	// solution of input

/* usage of the executable */
// because of an encoding problem between file and console, 
// Chinese words are printed wrongly
// #define CHINESE_USAGE
#ifndef CHINESE_USAGE
const char usage[] = {
	"name       meaning                                                 range                       example\n"
	"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
	"-c         number of finales to be generated                       1-1000000                   suduku.exe -c 20 [generate 20 finales]\n"
	"-s         file path of puzzles to be solved                       relative or absolute path   suduku.exe -s game.txt [solving puzzles stored at `game.txt`，dumping solution to `suduku.txt`]\n"
	"-n         number of puzzles to be generated                       1-10000                     suduku.exe -n 1000 [generating 1000 puzzles]\n"
	"-m         difficulty of puzzles to be generated                   1-3                         suduku.exe -n 1000 -m 1 [both `n` and `m` are needed]\n"
	"-r         number of blanks of puzzles to be generated             20-55                       suduku.exe -n 20 -r 20-55 [both `n` and `r` are needed]\n"
	"-u         whether the solution of a generated puzzle is unique                                suduku.exe -n 20 -u [both `n` and `u` are needed]\n"
	"-h         print help message                                                                  suduku.exe -h\n"
};
#else // CHINESE_USAGE
const char usage[] = {
	"参数名字   参数意义                    范围限制        用法示例\n"
	"-----------------------------------------------------------------------------------------------------------------------------------------------------------\n"
	"-c         需要的数独终盘数量          1-1000000       suduku.exe -c 20 [表示生成20个数独终盘]\n"
	"-s         需要解的数独棋盘文件路径     绝对或相对路径    suduku.exe -s game.txt [表示从game.txt读取若干个数独游戏，并给出其解答，生成到suduku.txt中]\n"
	"-n         需要的游戏数量              1-10000         suduku.exe -n 1000 [表示生成1000个数独游戏]\n"
	"-m         生成游戏的难度              1-3             suduku.exe -n 1000 -m 1 [表示生成1000个简单数独游戏，只有m和n一起使用才认为参数无误]\n"
	"-r         生成游戏中挖空的数量范围     20-55           suduku.exe -n 20 -r 20-55 [表示生成20个挖空数在20到55之间的数独游戏，只有r和n一起使用才认为参数无误]\n"
	"-u         生成游戏的解唯一                            suduku.exe -n 20 -u [表示生成20个解唯一的数独游戏，只有u和n一起使用才认为参数无误]\n"
	"-h         显示帮助                                    suduku.exe -h [表示打印帮助信息]\n"
};
#endif

const char character_map[] = { '$', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

class Sudoku
{
private:
	int _n_finale = 0;					// number of final results
	char* _input = nullptr;				// file path of games (both relative and absolute path are ok)
	int _n_puzzle = 0;					// number of games to be generated
	int _difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
	int _n_blank = MIN_BLANK;			// number of blanks
	bool _unique = false;				// whether solution is unique (default is not)

public:
	Sudoku() {}
	~Sudoku() { if (_input != nullptr) { delete[]_input; _input = nullptr;  } }

	/*
	* Init sudoku object with input params
	*/ 
	void init(int n_finale, char* input, int n_puzzle, int difficulty, int n_blank, bool unique);

	/* 
	* Generate sudoku finals.
	*/
	void generate_finales() const;

	/*
	* Generate sudoku puzzles.
	*/
	void generate_puzzles() const;

	/*
	* Read games from input and solve them.
	* Solutions will be dump to `output`
	*/
	void solve_puzzles() const;

	/* 
	* Print usage of how to play 
	*/
	static void print_usage() { std::cout << usage; }


private:
	/*
	* Convert 9 * 9 grid into a flattened string
	*/
	void grid_to_str(int grid[9][9], char* grid_str) const;

	/* 
	* Print the grid (9 * 9) in formatted string
	*/
	void print_grid(int grid[9][9]) const;

	/*
	* Print the grid (flattened string) in formatted string
	*/
	void print_grid(char* grid_str) const;

	/*
	* Generate a finale 
	*/
	void gen_finale(int grid[9][9]) const;

};

