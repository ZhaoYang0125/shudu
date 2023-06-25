```
1>C:\Users\18213\Downloads\shudu\sudoku\Sudoku.h(29,28): warning C4305: 'initializing': truncation from 'double' to 'const float'
1>C:\Users\18213\Downloads\shudu\sudoku\Sudoku.h(30,30): warning C4305: 'initializing': truncation from 'double' to 'const float'
1>C:\Users\18213\Downloads\shudu\sudoku\Sudoku.h(31,30): warning C4305: 'initializing': truncation from 'double' to 'const float'
1>C:\Users\18213\Downloads\shudu\sudoku\Sudoku.h(585,31): warning C4244: 'initializing': conversion from 'float' to 'const int', possible loss of data
1>C:\Users\18213\Downloads\shudu\sudoku\Sudoku.h(586,33): warning C4244: 'initializing': conversion from 'float' to 'const int', possible loss of data
1>C:\Users\18213\Downloads\shudu\sudoku\utils.h(36,16): warning C4244: 'initializing': conversion from '_Rep' to 'uint32_t', possible loss of data
1>        with
1>        [
1>            _Rep=std::chrono::system_clock::rep
1>        ]
```

# 数独游戏

生成不重复的数独终局至文件中

读取文件内的数独问题，求解并将结果输出至文件

C++

可以使用`.Net Framework`

运行环境为Win10 64位

代码经过质量分析并消除警告

至少10个用例来覆盖主要功能，统计覆盖率

使用Github管理源代码和测试用例

空格使用`$`表示

| 参数名字 | 参数意义                 | 范围限制       | 用法示例                                                     |
| -------- | ------------------------ | -------------- | ------------------------------------------------------------ |
| -c       | 需要的数独终盘数量       | 1-1000000      | 示例：suduku.exe -c 20 [表示生成20个数独终盘]                |
| -s       | 需要解的数独棋盘文件路径 | 绝对或相对路径 | 示例：suduku.exe -s game.txt [表示从game.txt读取若干个数独游戏，并给出其解答，生成到suduku.txt中] |
| -n       | 需要的游戏数量           | 1-10000        | 示例：suduku.exe -n 1000 [表示生成1000个数独游戏]            |
| -m       | 生成游戏的难度           | 1-3            | 示例：suduku.exe -n 1000 -m 1 [表示生成1000个简单数独游戏，只有m和n一起使用才认为参数无误，否则请报错] |
| -r       | 生成游戏中挖空的数量范围 | 20-55          | 示例：suduku.exe -n 20 -r 20-55 [表示生成20个挖空数在20到55之间的数独游戏，只有r和n一起使用才认为参数无误，否则请报错] |
| -u       | 生成游戏的解唯一         |                | 示例：suduku.exe -n 20 -u [表示生成20个解唯一的数独游戏，只有u和n一起使用才认为参数无误，否则请报错] |

