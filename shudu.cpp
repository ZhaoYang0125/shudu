#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
int main(){
    // cout<<"111"<<endl;
    string path="./game/";//游戏文件路径
    path+="game1.txt";
    ifstream infile;
    infile.open(path,ios::in);
    string line;
    int linecnt=0;//读取的行数
    string board[9][9];//棋盘
    string gameName;//游戏名字
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
            board[linecnt-1][i++]=num;
        }

        //读出一种棋盘形式，开始求解
        if(linecnt==9){
            cout<<gameName<<endl;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<board[i][j];
                }
                cout<<endl;
            }
        }

    }
    
    system("pause");
    return 0;
}