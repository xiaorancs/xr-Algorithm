/**
 *Author: xiaoran
 *Time: 2017-11-09 16:31
 *Problem: 给你一个无序的数组，讲其排序成波动的排序，
 *  即 arr[0]>=arr[1]<=arr[2]>=arr[3]<=arr[4]>=...
 *
 *思路：
 *	1、将数组排序
 *	2、交换相邻的两个值，swap(arr[i],arr[i+1])
 */ 
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

void sortInWave(int arr[],int n){
	sort(arr,arr+n);

	for(int i=0;i<n-1;i+=2){
		swap(arr[i],arr[i+1]);
	}
}

int main()
{
	int arr[] = {10,90,49,2,1,5,23};
	int n = sizeof(arr) / sizeof(arr[0]);
	sortInWave(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
