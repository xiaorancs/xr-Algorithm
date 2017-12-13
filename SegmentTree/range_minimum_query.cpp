/**
 *Author: xiaoran
 *Time: 2017-12-13 13:42
 *Problem:
	1. 给定一个数组,查询给定范围[l,r]之间的最小值,
	2. 满足动态更新的需要,更新一个值,arr[i] = new_value
	注: 这里没有给出更新,如果要更新一个值,更新的时候要维护树的性质.

  Solution:
	1. 最简单的遍历
	2. 线段树的使用,叶子节点是数组元素,父节点是该区间的最小值,
 *
 */ 
#include <stdio.h>
#include <math.h>
#include <limits.h>


//const int INT_MAX = 1000000;

int min(int x,int y){

	return (x<y)? x:y;
}

/**
 *建立线段树的使用函数
 *使用递归建立线段树,当前节点的最小值是左右子节点的最小值.
 *arr[] : 数据
 *ss和se分别是起始和结束节点.
 *st: 线段树的根节点
 *si: 当前根节点
 *return 当前节点的最小值
 */
int createSegmentTreeUtil(int arr[],int ss,int se,int *st,int si){
	// 叶子节点
	if(ss == se){
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = ss + (se - ss) / 2;
	st[si] = min(createSegmentTreeUtil(arr,ss,mid,st,si*2+1),
				 createSegmentTreeUtil(arr,mid+1,se,st,si*2+2));
	return st[si];
}

/**
 *构造线段树
 */ 
int *createSegmentTree(int arr[],int n){
	// 申请线段树的空间
	int x = (int)(ceil(log2(n)));
	
	int max_size = 2*(int)pow(2,x);

	int *st = new int[max_size];

	createSegmentTreeUtil(arr,0,n-1,st,0);

	return st;
}

/**
 *RMQ的调用函数.
 *
 */ 
int RMQUtil(int *st,int ss,int se,int qs,int qe,int si){
	
	// 满足查询条件
	if(qs<=ss && qe>=se){
		return st[si];
	}
	
	if(qs>se || qe<ss) return INT_MAX;
	
	//左右递归查询
	int mid = ss + (se - ss) / 2;
	return min(RMQUtil(st,ss,mid,qs,qe,si*2+1),RMQUtil(st,1+mid,se,qs,qe,si*2+2));
}

int RMQ(int *st,int n,int qs,int qe){
	if(qe<0 || qs>=n || qs>qe ){
		printf("Invalid input \n");
		return -1;
	}
	return RMQUtil(st,0,n-1,qs,qe,0);
}

int main()
{
	int arr[] = {1,3,2,7,9,11};
	int n = sizeof(arr) / sizeof(arr[0]);
	int qs = 0,qe=3;
	int *st = createSegmentTree(arr,n);

	printf("Minimum of values in range [%d,%d] is = %d\n",qs,qe,RMQ(st,n,qs,qe));

	return 0;
}
