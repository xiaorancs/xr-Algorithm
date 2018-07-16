/**
 * Author: xiaoran
 * Time: 2018-07-16
 * Problem:
 *  We are given an array of digits (values lie in range from 0 to 100). 
 *  The task is to count all the sub sequences possible in array such 
 *  that in each subsequence every digit is greater than its previous 
 *  digits in the subsequence.
 * Example:
 *  Input : arr[] = {4, 3, 6, 5}
 *  Output: 8
 *  Sub-sequences are {4}, {3}, {6}, {5}, {4,6}, {4,5}, {3,6}, {3,5}
 */ 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


/**
 * Method 1: dp,类似于lis
 * dp[i]: 表示以第i个元素结尾的满足条件的个数。
 * dp[i] = 1 + sum(dp[j]) j < i && a[j] < a[i]
 * init: dp[1...n] = 1
 * 
 * result = sum{dp[1...n]}
 */ 
int all_inc_subq(int a[],int n) {
    int *dp = new int[n+1];
    memset(dp,1,sizeof(dp));
    int ans = 0;
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(j<i && a[j]<a[i]) {
                dp[i] += dp[j];
            }
        }
        ans += dp[i];
    }
    return ans;
}

int main()
{   
    int a[] = {4,3,6,5};
    cout<<all_inc_subq(a,4)<<endl;

    int b[] = {4,3,6,5};
    cout<<all_inc_subq(a,4)<<endl;


    return 0;
}