/**
 * Author: xiaoran
 * Time: 2017-11-09 15:55
 * Problem:
 *  给你n个数，这n个数字的范围在0到n^2-1之间，请对这n个数排序，你能使用时间复杂度在O(n)时间的算法吗？
 * 
 * 分析：
 *  计数排序：O(n^2-1)
 *  插入排序、选择排序：O(n*n)
 *  归并排序、快速排序、堆排序：O(nlogn)
 *  
 *  思考的艺术，我们知道两个重要的点，
 *   比较排序的时间复杂度最优是O(logn),如果更优秀的方法，我们只能根据数据的范围
 *   进行计数排序，那么我们的问题就是如何讲数据范围变成n。
 *   要从n^2-1出发，如果一个数是k,一定可以表示成一个以n为基数的两位书，
 *   (k)[10] = (k/n)(k%n)[n], 这样就得到n个两位数，而且每一位上的数都小于等于n
 *   之后，我们可以使用基数排序，对每一位上的数进行计数排序，时间复杂度O(2n) 
 * example:
 * arr[] = {0,10,13,12,7} n = 5,
 * 我们讨论基数5，进行转换数字
 * arr[] = {00(0),20(10),23(13),22(12),12(7)}
 * 
 * 基数排序，第一次根据最右边一位排序
 * arr[] = {00(0),20(10),12(7),22(12),23(12)}
 * 
 * 第二次基数排序，根据最左边排序
 * arr[] = {00(0),12(7),20(10),22(12),23(12)}
 *  
 */ 
#include<iostream>
#include<stdio.h>
using namespace std;

/**
 * exp：对应基数n的权重，我们从低权重开始
 * 
 */
int countSort(int arr[],int n,int exp){
    int output[n];//输出数组
    int i,count[n];
    for(int i=0;i<n;i++){
        count[i] = 0;
    }
    //计算每一个数出现的次数，
    for(int i=0;i<n;i++){
        count[arr[i]/exp % n]++;
    }
    // 计算每一个数所在的位置，
    for(int i=1;i<n;i++){
        count[i] += count[i-1];
    }

    // 从后往前进行排序，即讲对应的数放到对应的位置
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]/exp % n]-1] = arr[i];
        count[arr[i]/exp % n] --;
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

/**
 * 基数排序
 */
void sort(int arr[],int n){
    // 只有两位，先根据低位排序，之后根据高位权重
    countSort(arr,n,1);

    countSort(arr,n,n);
} 

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {40,12,45,32,33,1,22};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"排序之前：";
    printArr(arr,n);

    sort(arr,n);
    cout<<"排序之后：";
    printArr(arr,n);

    return 0;
}