#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
#define GAME_NAME "game1.txt"

bool row[9][9];                 //存储行中数字存在的信息
bool column[9][9];              //存储列中数字存在的信息
bool block[3][3][9];            //存储一个九宫格中数字存在的信息
bool valid;                     //是否填完所有空格
vector<pair<int, int>> spaces;  //存储空格的位置信息
char board[9][9];               //棋盘
string gameName;                //游戏名字

//清空上述存信息的数组，开始下一个游戏的求解
void clear(){
    memset(row, false, sizeof(row));
    memset(column, false, sizeof(column));
    memset(block, false, sizeof(block));
    valid = false;
}

//定义一个深度优先搜索策略
void DFS(char Board[][9],int spacesCount){
    //空格数达到要求，返回
    if(spacesCount==spaces.size()){
        valid=true;
    }
    else{
        pair<int,int> spacePos=spaces[spacesCount];
        int r=spacePos.first;
        int c=spacePos.second;
        for(int i=0;i<9 && valid==false;i++){
            //是空格，且行、列、块都没这个数
            if(!row[r][i] && !column[c][i] && !block[r/3][c/3][i]){
                row[r][i] = column[c][i] = block[r/3][c/3][i]=true;
                Board[r][c]=i+1+'0';
                DFS(Board,spacesCount+1);
                row[r][i] = column[c][i] = block[r/3][c/3][i]=false;
            }
        }
    }
}

//求解函数
void solveGame(char Board[][9]){
    clear();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(Board[i][j]=='$'){
                spaces.emplace_back(i,j);
            }
            else{
                int k=Board[i][j]-'0'-1;
                row[i][k] = column[j][k] = block[i/3][j/3][k] = true;
            }
        }
    }
    DFS(Board,0);
}

int main(){
    // cout<<"111"<<endl;
    string path="./game/";//游戏文件路径
    path += GAME_NAME;
    ifstream infile;
    infile.open(path,ios::in);
    string line;
    int linecnt=0;//读取的行数
    while (getline(infile,line)){
        linecnt++;
        if(line[0]=='='){
            linecnt=0;
            gameName=line;
            continue;
        }
        istringstream ss(line);
        string num;//数独中的数字

        //把文件内容读取到数组中
        int i=0;
        while(getline(ss,num,' ')){
            board[linecnt-1][i++]=num[0];
        }

        //读出一种棋盘形式，开始求解
        if(linecnt==9){
            cout<<gameName<<" answer:"<<endl;
            // clear();
            solveGame(board);
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
        }

    }
    
    system("pause");
    return 0;
}