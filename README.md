# shudu
NKU software engineering programming assignment.

zhangzhaoyang's branch

### 数独求解思路：回溯


用一个数组记录每个数字是否出现。在存储时，我们使用一个长度为9的布尔类型的数组，其中第i 个元素的值为True，当且仅当数字i+1 出现过。

例如我们用 line[2][3]=True表示数字4在第2行已经出现过，那么当我们在遍历到第 2行的空白格时，就不能填入数字4。

我们首先对整个数独数组进行遍历，当我们遍历到第i行第j 列的位置：如果该位置是一个空白格，那么我们将其加入一个用来存储空白格位置的列表中，方便后续的递归操作；如果该位置是一个数字 x，那么我们需要将line[i][x−1]，column[j][x−1] 以及 block[⌊i/3⌋][⌊j/3⌋][x−1] 均置为 True。

当我们结束了遍历过程之后，就可以开始递归枚举。当递归到第i行第j列的位置时，我们枚举填入的数字x根据题目的要求，数字x不能和当前行、列、九宫格中已经填入的数字相同，因此line[i][x−1]，column[j][x−1] 以及block[⌊i/3⌋][⌊j/3⌋][x−1] 必须均为False。

当我们填入了数字 x 之后，我们要将上述的三个值都置为 True，并且继续对下一个空白格位置进行递归。在回溯到当前递归层时，我们还要将上述的三个值重新置为 False。