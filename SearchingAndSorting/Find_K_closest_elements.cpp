/**
 * Author: xiaoran
 * Time : 2017-11-04 16:17
 * Problem ：Find K closest elements to a given value
 *  给您一个排序的数组，和一个数x，在数组中找到与X最接近的K个数
 * Solution：
 *  方法1. 从头到尾遍历整个数组，找到与X最接近的K的数。 时间O(N)。
 *  方法2. 先找到交叉点，在交叉点附近找到与X最接近的K的数，这一步是O(K).
 *  找交叉点有两个方法：
 *      1. 线性查找，O(N), 总的时间复杂度O(N+K)
 *      2. 二分查找，O(logN),总的时间复杂度O(logN+K)
 * 
 */
#include<iostream>
#include<stdio.h>
using namespace std;

/**
 * step 1.找到交叉点
 */
int findCrossOver(int arr[],int low, int high,int x){
    if(arr[high]<=x) return high;

    if(arr[low]>=x) return low;

    int mid;

    while(low < high){
        mid = (low+high) / 2;
        if(arr[mid]<=x && arr[mid+1] > x){
            return mid;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return mid;
}

/**
 * 在交叉点的左右位置，找到相近的K个值
 * 
 */
int printKclosest(int arr[],int x,int k,int n){
    int cross = findCrossOver(arr,0,n-1,x);
    int count = 0;
    int l = cross,r = cross + 1;
    
    while(l>=0 && r < n && count < k){
        if(x - arr[l] < arr[r] - x){
            cout<<arr[l--]<<endl;
        }
        else{
            cout<<arr[r++]<<endl;
        }
        count ++;
    }

    while(count < k && l>=0){
        cout<<arr[l--]<<endl;
        count++;
    }
    while(count < k && r<0){
        cout<<arr[r++]<<endl;
        count++;
    }
}

int main()
{   
    int arr[] = {12,16,22,30,35,39,42,45,48,50,53,55,56};
    int n = sizeof(arr) / sizeof(*arr);
    int x = 35, k = 4;
    printKclosest(arr,x,k,n);
    return 0;
}