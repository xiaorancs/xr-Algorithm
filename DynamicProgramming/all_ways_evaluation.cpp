/**
 * Author: xiaoran
 * Time: 2018-06-17
 * Problem:
 *  Given a string that represents an expression constituting numbers 
 *  and binary operator +, – and * only. We need to parenthesize 
 *  the expression in all possible way and return all evaluated values.
 */ 
#include <bits/stdc++.h>

using namespace std;

bool isOperator(char op) {
    return (op=='+' || op=='-' || op=='*');
}

// input 和 记录已经计算过的子串的所有的得分
vector<int> possibleResultUitl(string input, map<string, vector<int> > memo) {
    // 已经计算
    if(memo.find(input) != memo.end()){
        return memo[input];
    }
    vector<int> res;
    
    // 根据所有的op进行分开计算
    for(int i=0;i<input.size();i++){
        if(isOperator(input[i])) {
            vector<int> resPre = possibleResultUitl(input.substr(0,i), memo);
            vector<int> resSuf = possibleResultUitl(input.substr(i+1), memo);
            
            // 合并前后计算的结果
            for(int j=0;j<resPre.size();j++){
                for(int k=0;k<resSuf.size();k++){
                    if(input[i]=='+') res.push_back(resPre[j] + resSuf[k]);
                    else if(input[i]=='-') res.push_back(resPre[j] - resSuf[k]);
                    else if(input[i]=='*') res.push_back(resPre[j] * resSuf[k]);
                    
                }
            }
        }
    }
    if(res.size() == 0) {// 只有一个数，
        res.push_back(atoi(input.c_str()));
    }
    // 记录这个字符的result
    memo[input] = res;
    return res;
}

vector<int> possibleResult(string input) {
    map<string, vector<int> > memo;
    return possibleResultUitl(input, memo);
}

int main()
{
    string input = "5*4-3*2";
    vector<int> res = possibleResult(input);

    cout<<input<<" = ? "<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;


    input = "3-2-1";
    res = possibleResult(input);
    cout<<input<<" = ?"<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}