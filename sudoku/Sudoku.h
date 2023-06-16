#pragma once
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>

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
	Init sudoku object with input params
	*/ 
	void init(int n_finale, char* input, int n_puzzle, int difficulty, int n_blank, bool unique)
	{
		// at this time, we do not know which function the user needs
		// so we check the legality of params when calling corresponding functions
		_n_finale = n_finale;
		if (input != nullptr) {	// deepcopy in case that `input` is out of its lifetime
			size_t length = strlen(input);
			_input = new char[length + 1];
			strncpy_s(_input, length + 1, input, length);
		}
		_n_puzzle = n_puzzle;
		_difficulty = difficulty;
		_n_blank = n_blank;
		_unique = unique;
	}

	/* 
	Generate sudoku finals.
	*/
	void generate_finales() const
	{
		assert(_n_finale >= MIN_FINALE && _n_finale <= MAX_FINALE);

		std::cout << "Generating " << _n_finale << " finales..." << std::endl;
		int grid[9][9];
		for (int i = 0; i < _n_finale; i++) {
			gen_finale(grid);
			std::cout << "Finale " << i + 1 << std::endl;
			print_grid(grid);
		}
		std::cout << "All " << _n_finale << " finale(s) have(has) been generated." << std::endl;
	}

	/*
	Generate sudoku puzzles.
	*/
	void generate_puzzles() const 
	{
		assert(_n_puzzle >= MIN_PUZZLE && _n_puzzle <= MAX_PUZZLE);
		assert(_difficulty >= MIN_DIFFICULTY && _difficulty <= MAX_DIFFICULTY);
		assert(_n_blank >= MIN_BLANK && _n_blank <= MAX_BLANK);

		std::cout << "generate_games" << std::endl;
	}

	/*
	Read games from input and solve them.
	Solutions will be dump to `output.txt`
	*/
	void solve_puzzles() const
	{
		// TODO
		assert(false);
	}

	/* 
	* Print usage of how to play 
	*/
	static void print_usage() { std::cout << usage; }

	/*
	Convert 9 * 9 grid into a flattened string
	`0` will be maped to `$`
	*/
	void grid_to_str(int grid[9][9], char* grid_str) const
	{
		int* ptr_src = nullptr;
		char* ptr_dst = grid_str;
		for (int i = 0; i < 9; i++) {
			ptr_src = grid[i];
			for (int j = 0; j < 9; j++) {
				int idx = *ptr_src;
				*ptr_dst++ = character_map[*ptr_src++];
			}
		}
	}

	/* 
	Print the grid (9 * 9)
	*/
	void print_grid(int grid[9][9]) const
	{
		char grid_str[81];
		grid_to_str(grid, grid_str);	// flatten
		print_grid(grid_str);
	}

	/*
	Print the grid (flattened string) in formatted string
	*/
	void print_grid(char* grid_str) const
	{
		const int buf_sz = 1024;
		char buffer[buf_sz];
		char* s = grid_str;
		snprintf(buffer, buf_sz,
			"-------------------------\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"-------------------------\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"------------------------- \n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"| %c %c %c | %c %c %c | %c %c %c |\n"
			"-------------------------",
			s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], s[9],
			s[10], s[11], s[12], s[13], s[14], s[15], s[16], s[17], s[18], s[19],
			s[20], s[21], s[22], s[23], s[24], s[25], s[26], s[27], s[28], s[29],
			s[30], s[31], s[32], s[33], s[34], s[35], s[36], s[37], s[38], s[39],
			s[40], s[41], s[42], s[43], s[44], s[45], s[46], s[47], s[48], s[49],
			s[50], s[51], s[52], s[53], s[54], s[55], s[56], s[57], s[58], s[59],
			s[60], s[61], s[62], s[63], s[64], s[65], s[66], s[67], s[68], s[69],
			s[70], s[71], s[72], s[73], s[74], s[75], s[76], s[77], s[78], s[79],
			s[80]);
		std::cout << buffer << std::endl;
	}

	/*
	Generate a finale 
	*/
	void gen_finale(int grid[9][9]) const
	{
		int grid_test[9][9] = {
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
			{0, 1, 2, 3, 4, 5, 6, 7, 8},
		};
		set_grid(grid_test, grid);

		// test_insert
		int num = 1;
		int r = 0;
		int c = 0;
		if (safe_check(grid, num, r, c)) {
			grid[r][c] = num;
		}
	}

	/*
	Check whether insert a num at specific coordinate is safe
	by scanning the row
	*/
	bool row_safe(int grid[9][9], int num, int r, int c) const
	{
		if (grid[r][c]) {
			return false;		// pos(r, c) already has a number
		}
		for (int j = 0; j < 9; j++) {
			if (grid[r][j] == num) {
				return false;	// numbers in a row cannot be the same
			}
		}
		return true;
	}

	/*
	Check whether insert a num at specific coordinate is safe
	by scanning the column
	*/
	bool col_safe(int grid[9][9], int num, int r, int c) const
	{
		if (grid[r][c]) {
			return false;		// pos(r, c) already has a number
		}
		for (int i = 0; i < 9; i++) {
			if (grid[i][c] == num) {
				return false;	// numbers in a row cannot be the same
			}
		}
		return true;
	}

	/*
	Check whether insert a num at specific coordinate is safe
	by scanning the box
	*/
	bool box_safe(int grid[9][9], int num, int r, int c) const
	{
		// start coordinates are
		// (0, 0), (0, 3), (0, 6)
		// (3, 0), (3, 3), (3, 6)
		// (6, 0), (6, 3), (6, 6)

		int s_r = (r / 3) * 3;
		int s_c = (c / 3) * 3;
		int* ptr = nullptr;
		for (int i = s_r; i < s_r + 3; i++) {
			ptr = grid[i] + s_c;
			for (int j = s_c; j < s_c + 3; j++) {
				if (*ptr++ == num) {
					return false;
				}
			}
		}
		return true;
	}

	/*
	Check whether insert a num at specific coordinate is safe
	by scanning the row
	*/
	bool safe_check(int grid[9][9], int num, int r, int c) const
	{
		assert(num >= 1 && num <= 9
			&& r >= 0 && r <= 8
			&& c >= 0 && c <= 8);
		return row_safe(grid, num, r, c)
			&& col_safe(grid, num, r, c)
			&& box_safe(grid, num, r, c);
	}

	/*
	manully set the gridand copy to the dst
	*/
	void set_grid(int src[9][9], int dst[9][9]) const
	{
		int* src_ptr = nullptr, * dst_ptr = nullptr;
		for (int i = 0; i < 9; i++) {
			src_ptr = src[i];
			dst_ptr = dst[i];
			for (int j = 0; j < 9; j++) {
				*dst_ptr++ = *src_ptr++;
			}
		}
	}
};

