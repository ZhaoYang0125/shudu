#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Sudoku.h"
using namespace std;

/* limitations */
const int MIN_FINALS = 1;			// minimum of final results
const int MAX_FINALS = (int) 1e6;	// maximum of final results

const int MIN_GAMES = 1;			// minimum of games
const int MAX_GAMES = (int) 1e4;	// maximum of games

const int MIN_DIFFICULTY = 1;		// minimum of difficulty
const int MAX_DIFFICULTY = 3;		// maximum of difficulty

const int MIN_BLANKS = 20;			// minimum of blanks
const int MAX_BLANKS = 55;			// maximum of blanks

/* global variants */
int n_finals = 0;					// number of final results
char* input = nullptr;				// file path of games (both relative and absolute path are ok)
int n_games = 0;					// number of games to be generated
int n_difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
int n_blanks = MIN_BLANKS;			// number of blanks
bool unique = false;				// whether solution is unique (default is not)

/* usage of the executable */
const char* usage[] = {
	"参数名字   参数意义                    范围限制        用法示例",
	"-----------------------------------------------------------------------------------------------------------------------------------------------------------",
	"-c         需要的数独终盘数量          1-1000000       suduku.exe -c 20 [表示生成20个数独终盘]",
	"-s         需要解的数独棋盘文件路径    绝对或相对路径  suduku.exe -s game.txt [表示从game.txt读取若干个数独游戏，并给出其解答，生成到suduku.txt中]",
	"-n         需要的游戏数量              1-10000         suduku.exe -n 1000 [表示生成1000个数独游戏]",
	"-m         生成游戏的难度              1-3             suduku.exe -n 1000 -m 1 [表示生成1000个简单数独游戏，只有m和n一起使用才认为参数无误]",
	"-r         生成游戏中挖空的数量范围    20-55           suduku.exe -n 20 -r 20-55 [表示生成20个挖空数在20到55之间的数独游戏，只有r和n一起使用才认为参数无误]",
	"-u         生成游戏的解唯一                            suduku.exe -n 20 -u [表示生成20个解唯一的数独游戏，只有u和n一起使用才认为参数无误]",
	"-h         显示帮助                                    suduku.exe -h [表示打印帮助信息]",
};

void print_usage() {
	for (auto line : usage) {
		cout << line << endl;
	}
}

/* parse cmdline arguments */
int main(int argc, char* argv[]) {
	if (argc < 2) {
		print_usage();
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-c") == 0) {
			assert(++i < argc);
			n_finals = atoi(argv[i]);
			assert(n_finals >= MIN_FINALS && n_finals <= MAX_FINALS);
			continue;
		}
		else if (strcmp(argv[i], "-s") == 0) {
			assert(++i < argc);
			size_t length = strlen(argv[i]);
			input = new char[length + 1];
			strncpy_s(input, length + 1, argv[i], length);
			continue;
		}
		else if (strcmp(argv[i], "-n") == 0) {
			assert(++i < argc);
			n_games = atoi(argv[i]);
			assert(n_games >= MIN_GAMES && n_games <= MAX_GAMES);
			continue;
		}
		else if (strcmp(argv[i], "-m") == 0) {
			assert(++i < argc);
			n_difficulty = atoi(argv[i]);
			assert(n_difficulty >= MIN_DIFFICULTY && n_difficulty <= MAX_DIFFICULTY);
			continue;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			assert(++i < argc);
			n_blanks = atoi(argv[i]);
			assert(n_blanks >= MIN_BLANKS && n_blanks <= MAX_BLANKS);
			continue;
		}
		else if (strcmp(argv[i], "-u") == 0) {
			unique = true;
			continue;
		}
		else if (strcmp(argv[i], "-h") == 0) {
			print_usage();
			continue;
		}
		else {
			cerr << "Wrong Commands!" << endl;
			print_usage();
			exit(1);
		}
	}

	if (n_finals) {
		generate_finals();
	}
	if (n_games) {
		generate_games();
	}
	if (input) {
		solve_games();
	}
	return 0;
}