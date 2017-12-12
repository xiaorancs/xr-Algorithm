/**
 *Author: xiaoran
 *Time: 2017-12-12 13:54
 *Problem:
	有一个数组arr[0,...,n-1],做一下的操作:
	 1. 查询arr[l,...,r]的sum,where 0<=l<=r<=n-1.
	 2. 跟新一个值,arr[i] = x; where 0<=i<=n-1
  分析:
   1. 循环l-r计算所有的和时间复杂度O(n),直接更新第i个值O(1).
   2. 存储一个数组sum,sum[i]表示0-i的所有元素的和;这样查询时间是O(1),
      但是更新一个值,就要更新包含改值的所有区间,时间O(n).
   3. 使用一种新的数据结构线段是使得查询和更新时间都是O(logn).
  
  线段树的性质:
   1. 所有的输入元素都在叶子节点.
   2. 线段树是一个完全二叉树,共有n个叶子节点,2n-1个节点.
   3. node i的左右孩子节点分别是i*2+1,i*2+2, 其父节点是(i-1)/2.
   4. 树的高度是[log2N],需要开辟的空间是2*2^(log2n)-1.
 *
 */ 
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

/**
  基于数组arr[ss,se]递归创建线段树:
  si是线段树st中的当前节点,
  return 当前节点的值(这里是查询区间的sum)
 */ 
int createSegmentTreeUtil(int arr[], int ss,int se, int *st,int si){
	if(ss == se){//叶子节点
		st[si] = arr[ss];
		return arr[ss];
	}
	// 递归构建子线段树
	int mid = ss + (se-ss)/2;
	st[si] = createSegmentTreeUtil(arr,ss,mid,st,si*2+1)
			+createSegmentTreeUtil(arr,mid+1,se,st,si*2+2);

	return st[si];
}


/**
 *创建线段树
 *
 */ 
int *createSegmentTree(int arr[],int n){
	// 申请线段树的空间
	int x = (int)(ceil(log2(n)));

	//线段树的最大空间
	int max_size = 2*(int) pow(2,x);
	int *st = new int[max_size];
	
	createSegmentTreeUtil(arr,0,n-1,st,0);
	return st;
}

/**
 * 计算区间的和
 *	st: 线段树的树根
 *	si: 线段树的初始化节点
 *	ss & se: 线段树的开始和结束的端点
 *	qs & qe: 查询的区间的端点
 */ 
int getSumUtil(int *st, int ss,int se,int qs,int qe,int si){
	
	// 查询区间包括整个树的区间,返回树的区间的和
	if(qs<=ss && se<=qe){
		return st[si];
	}
	// 查询区间在整个树的区间之外
	if(qe<ss || qs>se) return 0;

	//递归分叉查询
	int mid = ss + (se - ss) / 2;
	return getSumUtil(st,ss,mid,qs,qe,si*2+1) + 
		   getSumUtil(st,mid+1,se,qs,qe,si*2+2);
}

/**
 *查询函数
 *
 */ 
int getSum(int *st, int n, int qs,int qe){
	if(qs <0 || qe > n-1 || qs > qe){
		printf("Invalid Input\n");
		return -1;
	}
	
	return getSumUtil(st,0,n-1,qs,qe,0);
}

/**
 *更新函数调用的操作函数
 *递归更新
 *	st,si,ss,se与getSumUtil()中的一样	
 *	i: 更新的下标
 *	diff: 所有包含i的节点都要增加的差值
 *
 */ 
void updateValueUtil(int *st,int ss,int se,int i,int diff, int si){
	if(i<ss || i>se) return;

	st[si] += diff;
	if(se != ss){
		int mid = ss + (se - ss)/2;
		updateValueUtil(st,ss,mid,i,diff,2*si+1);
		updateValueUtil(st,mid+1,se,i,diff,2*si+2);
	}
}

/**
 *更新
 */ 
void updateValue(int arr[],int *st,int n,int i,int new_val){
	if(i<0 || i>n-1){
		printf("Invalid Input");
		return;
	}
	int diff = new_val - arr[i];
	arr[i] = new_val;
	
	updateValueUtil(st,0,n-1,i,diff,0);
}

int main()
{
	int arr[] = {1,3,5,7,9,11};
	int n = sizeof(arr) / sizeof(arr[0]);

	int *st = createSegmentTree(arr,n);

	printf("Sum of values in given range[1,3] = %d\n",getSum(st,n,1,3));

	updateValue(arr,st,n,1,10);

	printf("Sum of values in given range[1,3] = %d\n",getSum(st,n,1,3));

	return 0;
}

