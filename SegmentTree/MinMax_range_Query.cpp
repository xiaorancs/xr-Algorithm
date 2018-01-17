/**
 *Author: xiaoran
 *Time: 2018-01-17 15:34
 *Problem:
 *	区间最大最小值查询
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

using namespace std;


struct Node{
	int maxVal;
	int minVal;
};


void createSegmentTreeUtil(Node* st,int arr[],int ss,int se,int index){
	if(se == ss){
		st[index].minVal = arr[se];
		st[index].maxVal = arr[se];
		return;
	}

	// 递归构造线段树
	int mid = (se+ss) / 2;
	
	// left
	createSegmentTreeUtil(st,arr,ss,mid,index*2+1);
	// right
	createSegmentTreeUtil(st,arr,mid+1,se,index*2+2);

	// 反向更新
	st[index].minVal = min(st[index*2+1].minVal, st[index*2+2].minVal);
	st[index].maxVal = max(st[index*2+1].maxVal, st[index*2+2].maxVal);
}


struct Node* createSegmentTree(int arr[],int n){
	// 最大的线段树的个数
	int x = (int) (ceil(log2(n)));
	int max_size = 2*(int)pow(2,x) - 1;
	

	Node* st = new Node[max_size];

	// create segmentTree
	createSegmentTreeUtil(st,arr,0,n-1,0);

	return st;
}

Node MinMaxQueryUtil(Node* st,int ss,int se,int qs,int qe,int index){
	Node result, left, right;

	if(qs <= ss && qe>=se){
		return st[index];
	}
	
	if(qs>se || qe<ss){ // 注意不要写反了
		result.minVal = INT_MAX;
		result.maxVal = INT_MIN;
		return result;
	}

	// 递归查询
	int mid = (se+ss) / 2;

	// left 
	left = MinMaxQueryUtil(st,ss,mid,qs,qe,index*2+1);
	// right
	right = MinMaxQueryUtil(st,mid+1,se,qs,qe,index*2+2);

	result.minVal = min(left.minVal, right.minVal);
	result.maxVal = max(left.maxVal, right.maxVal);

	return result;
}


// 查询
Node MinMaxQuery(Node * st, int n, int qs,int qe){
	struct Node result;
	if(qs<0 || qe>n-1 || qs>qe){// 输入不合法
		printf("Invalid Input!");
		result.minVal = INT_MIN;
		result.maxVal = INT_MAX;
		
		return result;
	}


	// 查询
	return MinMaxQueryUtil(st,0,n-1,qs,qe,0);
}



int main()
{
	int arr[] = {1,8,5,9,6,14,2,4,3,7};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("%d\n",n);
	Node* st = createSegmentTree(arr,n);

	int qs = 0, qe = 8;
	Node result = MinMaxQuery(st,n,qs,qe);

	printf("Minimum = %d and Maximum = %d \n", result.minVal, result.maxVal);


	return 0;
}
