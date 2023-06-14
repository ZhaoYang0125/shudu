#pragma once
#include <iostream>

/* limitations */
const int MIN_FINALS = 1;			// minimum of final results
const int MAX_FINALS = (int)1e6;	// maximum of final results

const int MIN_GAMES = 1;			// minimum of games
const int MAX_GAMES = (int)1e4;		// maximum of games

const int MIN_DIFFICULTY = 1;		// minimum of difficulty
const int MAX_DIFFICULTY = 3;		// maximum of difficulty

const int MIN_BLANKS = 20;			// minimum of blanks
const int MAX_BLANKS = 55;			// maximum of blanks

const char output[] = "sudoku.txt";	// solution of input

/* usage of the executable */
const char usage[] = {
	"��������   ��������                    ��Χ����        �÷�ʾ��\n"
	"-----------------------------------------------------------------------------------------------------------------------------------------------------------\n"
	"-c         ��Ҫ��������������          1-1000000       suduku.exe -c 20 [��ʾ����20����������]\n"
	"-s         ��Ҫ������������ļ�·��    ���Ի����·��  suduku.exe -s game.txt [��ʾ��game.txt��ȡ���ɸ�������Ϸ���������������ɵ�suduku.txt��]\n"
	"-n         ��Ҫ����Ϸ����              1-10000         suduku.exe -n 1000 [��ʾ����1000��������Ϸ]\n"
	"-m         ������Ϸ���Ѷ�              1-3             suduku.exe -n 1000 -m 1 [��ʾ����1000����������Ϸ��ֻ��m��nһ��ʹ�ò���Ϊ��������]\n"
	"-r         ������Ϸ���ڿյ�������Χ    20-55           suduku.exe -n 20 -r 20-55 [��ʾ����20���ڿ�����20��55֮���������Ϸ��ֻ��r��nһ��ʹ�ò���Ϊ��������]\n"
	"-u         ������Ϸ�Ľ�Ψһ                            suduku.exe -n 20 -u [��ʾ����20����Ψһ��������Ϸ��ֻ��u��nһ��ʹ�ò���Ϊ��������]\n"
	"-h         ��ʾ����                                    suduku.exe -h [��ʾ��ӡ������Ϣ]\n"
};

class Sudoku
{
private:
	int _n_finals = 0;					// number of final results
	char* _input = nullptr;				// file path of games (both relative and absolute path are ok)
	int _n_puzzles = 0;					// number of games to be generated
	int _difficulty = MIN_DIFFICULTY;	// difficulty (easy, middle or hard, default is easy)
	int _n_blanks = MIN_BLANKS;			// number of blanks
	bool _unique = false;				// whether solution is unique (default is not)

public:
	Sudoku() {}
	~Sudoku() { if (_input != nullptr) { delete[]_input; _input = nullptr;  } }

	/*
	* Init sudoku object with input params
	*/ 
	void init(int n_finals, char* input, int n_puzzles, int difficulty, int n_blanks, bool unique);

	/* 
	* Generate sudoku finals. 
	* 
	* Refference: [���������㷨��� - ֪��](https://zhuanlan.zhihu.com/p/67447747)
	*/
	void generate_finals() const;

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
	* print usage of how to play 
	*/
	static void print_usage() { std::cout << usage; }


private:
	void print_grid(int grid[9][9]) const;
	void gen_final(int grid[9][9]) const;

};

