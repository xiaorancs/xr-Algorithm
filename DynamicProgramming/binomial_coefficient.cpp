/**
 * 求二项式展开的系数，C(n,k) = C(n-1,k) + C(n-1,k-1)
 * C(n,0) = C(n,n) = 1, 可以直接使用DP
 * 或者数学直接计算，
 * C(n,k) = A(n,k) / k!
 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
const int MAXN = 1005;

long long dp[MAXN][MAXN] = {0};

long long get_c_by_dp(int n,int k){
    long long res = 0;
    // 初始化
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){ // 注意最小值的选择
            if(j==0 || i==j) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    res = dp[n][k];
    return res;
}

// 基于数学上的计算
long long get_c_by_math(int n,int k){
    double res = 1.0;
    for(int i=1;i<=k;i++){
        res *= 1.0 * (n-i+1) / (k-i+1);
    }
    return (long long)res;
}


int main()
{
    int n,k;
    while(cin>>n>>k){
        cout<<"基于DP的计算,res = "<<get_c_by_dp(n,k)<<endl;
        cout<<"基于Math的计算,res = "<<get_c_by_math(n,k)<<endl;
    }
    return 0;   
}
