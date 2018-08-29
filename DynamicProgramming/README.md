# 动态规划(DP)
1. [DP基础](./dp.md)

    + 感谢[feedliu](https://github.com/feedliu)提供的dp基础的文档。

2. [binomial_coefficient](./binomial_coefficient.cpp)

    + 求二项式展开的系数，C(n,k) = C(n-1,k) + C(n-1,k-1)
3. [all_increasing_subsequences](./count_all_increasing_subsequences.cpp)

    + 给你一个list，1<=list[i]<=100, 你的任务是统计所有的递增子序列的个数。
    + 例如：arr[] = {4,3,6,5}
    + {4},{3},{6},{5},{4,6},{4,5},{3,6},{3,5}共有8种情况。
4. [All ways to add parenthesis for evaluation](./all_ways_evaluation.cpp)

    + 给你一个字符串表示的表达式，仅仅包含'+','-','*'三种操作符号，你可以使用括号任意改变
    + 计算顺序，返回所有的结果。
    + Input : expr = “3-2-1”    
      Output : {0, 2}   
        ((3-2)-1) = 0   
        (3-(2-1)) = 2
    + 方法  
        使用深度搜索+备忘录，防止计算重复的子串的结果，我们根据运算符进行分割，     
        之后遍历素所有结果进行计算。
    

