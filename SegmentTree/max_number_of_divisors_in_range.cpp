/**
 *Author: xiaoran
 *Time: 2018-01-21 19:50
 *Problem: 
 *	取给定区间[L,R]的最大因子的个数。
 *
 *1. 使用欧拉定理计算所有的数的因子个数数组divisors
 *2. 对divisors使用线段树。
 */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int MAXN = 10005;

const int maxn = 100;

int divisors[MAXN];
int segmentTree[4*MAXN];

// 计算n的因子个数
int erlu(int n){
	int s = 1;
	int k = (int)sqrt(n);
	for(int i=2;i<=k;i++){
		int k = 0;
		while(n%i==0){
			n/=i;
			k++;
		}
		s*=(k+1);
	}
	return s;
}


// 得到因子数组
void getAllDivisors(int maxn){
	for(int i=1;i<=maxn;i++){
		divisors[i] = erlu(i);

	}
}


// 创建线段树
void createSegTree(int arr[],int node,int ss,int se){
	if(ss > se){
		return;
	}

	if(ss == se){
		segmentTree[node] = arr[ss];
		return;
	}

	int mid = (ss+se)/2;

	// left
	createSegTree(arr,node*2,ss,mid);
	// right
	createSegTree(arr,node*2+1,mid+1,se);

	// 父节点
	segmentTree[node] = max(segmentTree[node*2],segmentTree[node*2+1]);

}


// Query
int findMaxNumberofDivisors(int node,int ss,int se,int l,int r){
	// invalid input
	if(l>r || l>se || r<ss ){
		// 输入非法

		return 0;
	}

	if(ss == se){
		return segmentTree[node];
	}
	
	if(l<=ss && se<=r){
		return segmentTree[node];
	}
	
	int mid = (ss+se)/2;

	return max(findMaxNumberofDivisors(node*2,ss,mid,l,r),
				findMaxNumberofDivisors(node*2+1,mid+1,se,l,r));

}


int main()
{	

	getAllDivisors(maxn);

	createSegTree(divisors,1,1,maxn);

//	cout<<erlu(3)<<endl;
//	cout<<erlu(48)<<endl;

	cout<<"Maximum divisors that a number has in [1,100] are "
		<<findMaxNumberofDivisors(1,1,maxn,1,100)<<endl;

	cout<<"Maximum divisors that a number has in [10,48] are "
		<<findMaxNumberofDivisors(1,1,maxn,10,48)<<endl;
	
	cout<<"Maximum divisors that a number has in [1,10] are "
		<<findMaxNumberofDivisors(1,1,maxn,1,10)<<endl;



	return 0;
}


