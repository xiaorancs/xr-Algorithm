/**
 *Author: xiaoran
 *Time: 2017-12-11 22:20
 *Problem:
 *计算有序的二进制数组中1的个数
 *
 *	方法1:遍历O(n)
 *	方法2:二分,找到最后一个1的位置,O(logn)
 *
 */ 
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int countOne(int a[],int n){
	int i = 0,j = n - 1;
	while(i<=j){
		int mid = (i+j)/2;
	//	cout<<" s "<< mid <<endl;
		if(a[mid] == 1 && ( mid+1 == n || a[mid+1] == 0) ){
			return mid+1;
		}
		else if(a[mid] == 1 && a[mid+1] == 1){
			i = mid+1;
		}
		else if(a[mid] == 0){
			j = mid - 1;
		}
	}
	return 0;
}

int main()
{
	int a[] = {1,1,1,1,0,0,0};
	int b[] = {1,1,1,1,1};
	int c[] = {0,0,0,0};
	int alen = sizeof(a) / sizeof(int);
	int blen = sizeof(b) / sizeof(int);
	int clen = sizeof(c) / sizeof(int); 
	
	cout<<countOne(a,alen)<<endl;
	cout<<countOne(b,blen)<<endl;
	cout<<countOne(c,clen)<<endl;
	return 0;
}
