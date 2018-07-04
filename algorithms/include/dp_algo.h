/*****************************************
 * Author: xiaoran
 * Time: 2018-07-03
 * Algorithm implementations
 * Dynamic planing 
 * 1. max_subarray
 * 给一个序列，求出最大的子数组的和，例如 {-2,1,-3,4,-1,2,1,-5,4}
 *  sum = 6, subarray = {4,-1.2,1}
 * 2. longest_common_Subsequence
 *  给定两个序列a和b，a="abcdgh", b="aedfhr"; lcs(a,b) = "adh", length is 3.
 * 3. longest_Increasing subsequence
 *  给定一个序列a，求出最长的上升的子序列的长度
 *  a = {10,22,9,33,21,49} lis(s) = {10,22,33,49} length=4
 * 
 ****************************************/

#ifndef ALGO_DP_ALGO_H_
#define ALGO_DP_ALGO_H_

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "xmath.h"

namespace alg {
    /**
     * return [begin,end), sum
     */
    static void max_subarray(int a[], int len, int &begin,int &end, int &sum){
        sum = 0;
        int i,subvalue = 0, new_begin = 0;
        begin = end = 0;

        for(int i=0;i<len;i++){
            if(subvalue > 0){
                subvalue += a[i];
            } else{
                subvalue = a[i];
                new_begin = i;
            }

            if(sum < subvalue){
                sum = subvalue;
                begin = new_begin;
                end = i;
            }
        }
    }
    /**
     * lcs
     */
    template<class T> 
    static void lcs(T* a, int lena, T* b,int lenb,int &len){
        len = 0;
        int dp[lena][lenb] = {0};
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=lena;i++){
            for(int j=1;j<=lenb;j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j-1], dp[i-1][j]);
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        len = dp[lena][lenb];
    } 

    /**
     * lis
     */
    template<class T>
    static void lis(T* a,int lena, int &len){
        int dp[lena] = {0};
        len = 1;
        for(int i=1;i<lena;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
                len = max(len,dp[i]);
            }
        }
    }
    



} // alg end

#endif

