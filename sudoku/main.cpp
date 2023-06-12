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
	"��������   ��������                    ��Χ����        �÷�ʾ��",
	"-----------------------------------------------------------------------------------------------------------------------------------------------------------",
	"-c         ��Ҫ��������������          1-1000000       suduku.exe -c 20 [��ʾ����20����������]",
	"-s         ��Ҫ������������ļ�·��    ���Ի����·��  suduku.exe -s game.txt [��ʾ��game.txt��ȡ���ɸ�������Ϸ���������������ɵ�suduku.txt��]",
	"-n         ��Ҫ����Ϸ����              1-10000         suduku.exe -n 1000 [��ʾ����1000��������Ϸ]",
	"-m         ������Ϸ���Ѷ�              1-3             suduku.exe -n 1000 -m 1 [��ʾ����1000����������Ϸ��ֻ��m��nһ��ʹ�ò���Ϊ��������]",
	"-r         ������Ϸ���ڿյ�������Χ    20-55           suduku.exe -n 20 -r 20-55 [��ʾ����20���ڿ�����20��55֮���������Ϸ��ֻ��r��nһ��ʹ�ò���Ϊ��������]",
	"-u         ������Ϸ�Ľ�Ψһ                            suduku.exe -n 20 -u [��ʾ����20����Ψһ��������Ϸ��ֻ��u��nһ��ʹ�ò���Ϊ��������]",
	"-h         ��ʾ����                                    suduku.exe -h [��ʾ��ӡ������Ϣ]",
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