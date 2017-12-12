/**
 * Author: xiaoran
 * Time: 2017-11-24 21:05
 * Problem:
 *	给你两个有序的数组a and b和一个数x，从a和b中分别取一个数，使这两个数的和最接近x。
 * 
 * 分析：
 *	方法1、两层循环，O(n^2)时间复杂度, 函数findClosestPair1()
 *	方法2、使用2的思想，但是不使用额外的空间，O(n+m) + O(1)
 *	  1. 初始化，i = 0，是a数组的开头；j=m-1,是b数值的结尾。
 *	  2. Loop while i<n and j>=0
 *			if abs(a[i]+b[j]-x) < diff 
 *				update diff and result
 *			else if a[i]+b[j] < x
 *				i++;
 *			else j--
 */ 


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

/**
 *参数：数组a和b，已经其长度n和m，和x。
 *
 *打印两个数e1,e2，使得其和e1+e2最接近x
 */ 
void findClosestPair1(int a[],int b[],int n,int m,int x){
	int c1=a[0],c2=b[0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(abs(c1+c2-x) > abs(a[i]+b[j]-x)){
				c1 = a[i];
				c2 = b[j];
			}
		}
	}
	cout<<c1<<" "<<c2<<endl;
}


void findClosestPair2(int a[],int b[],int n,int m,int x){
	int c1=a[0],c2=b[m-1],diff=x;
	int i=0,j=m-1;
	diff = abs(c1+c2-x);
	while(i<n && j>=0){
		if(abs(a[i]+b[j]-x) < diff){
			diff = abs(a[i]+b[j]-x);
			c1 = a[i];
			c2 = b[j];
		}
		else if(a[i]+b[j] < x) i++;
		else j--;
	}
	cout<<c1<<" "<<c2<<endl;
}


int main()
{
	int a[] = {1,4,5,7};
	int b[] = {10,20,30,40};
	int n = sizeof(a) / sizeof(a[0]);
	int m = sizeof(b) / sizeof(b[0]);
	int x = 38;
	cout<<"findClosestPair1: ";
	findClosestPair1(a,b,n,m,x);
	cout<<"findClosestPair2: ";
	findClosestPair2(a,b,n,m,x);
	return 0;
}
