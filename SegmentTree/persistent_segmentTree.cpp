/**
 *Author:xiaoran
 *Time: 2017-12-18 13:16
 *Problem:
 *	线段树的持久化,使用O(logn)的时间和空间,记录每一更新后的线段树
 *	并保留之前的原有线段树.
 */ 
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define MAXN 1000



/**
 *线段树的节点
 */
struct Node{
	//值
	int val;
	//左右子树
	Node *left, *right;
	
	//定义两种构造函数
	Node(){}
	Node(Node* l,Node* r,int v){
		left = l;
		right = r;
		val = v;
	}
};

int arr[MAXN];

// 记录不同版本的线段树,只要记录根节点即可.
Node* version[MAXN];

/*
 *建立第0版本的线段树,
 *时间复杂度O(nlogn)
 */ 

void buildSegmentTree(int *arr,Node* root,int low,int high){
	if(low==high){//叶节点
		root->val = arr[low];
		return ;
	}
	//递归建立线段树
	int mid = (low+high)/2;
	root->left = new Node(NULL,NULL,0);
	root->right = new Node(NULL,NULL,0);
	buildSegmentTree(arr,root->left,low,mid);
	buildSegmentTree(arr,root->right,mid+1,high);
	
	//反向更新父节点的和
	root->val = root->left->val + root->right->val;

}

/**
 *更新到新版本,
 *参数:
 *	Node* prev, 上一个版本的根节点
 *	Node* cur, 当前版本的根节点
 *	[low,high] 数组的长度
 *	idx,value,: 更新值arr[idx] = value
 */ 

void upgrade(Node* prev, Node * cur, int low,int high,int idx,int value){
	
	//下标非法
	if(idx < low || low > high || idx > high){
		return ;
	}
	//update leaf node
	if(low == high){
		cur->val = value;
		return ;
	}
	//递归更新
	int mid = (low + high) / 2;
	if(idx <= mid){//更新的节点在左子树,
		// 右子树不变,和原来的版本一致
		cur->right = prev->right;

		//创建新的版本的节点,需要纪录的新的节点,递归更新
		cur->left = new Node(NULL,NULL,0);
		
		upgrade(prev->left,cur->left,low,mid,idx,value);
	}
	else{//更新节点在右子树
		cur->left = prev->left;

		cur->right = new Node(NULL,NULL,0);
		
		upgrade(prev->right,cur->right,mid+1,high,idx,value);
	}
	
	// 不要忘记更新当前版本的父节点的值
	cur->val = cur->left->val + cur->right->val;
}

/**
 *查询指定版本的区间的和
 *
 */ 
int query(Node *root, int low,int high,int l,int r){
	if(l>high || r<low || low>high){
	//	cout<<"非法查询"<<endl;
		return 0;
	}
	
	if(l<=low && high<=r){
		return root->val;
	}
	int mid = (low+high) / 2;
	
	return query(root->left,low,mid,l,r) + 
		   query(root->right,mid+1,high,l,r);
}



int main()
{
	int A[] = {1,2,3,4,5};
	int n = sizeof(A) / sizeof(A[0]);
	for(int i=0;i<n;i++){
		arr[i] = A[i];
	}
	// 创建version-0
	Node * root = new Node(NULL,NULL,0);
	buildSegmentTree(arr,root,0,n-1);
	
	// 纪录所有版本的线段树的根节点
	version[0] = root;

	//更新到version-1
	version[1] = new Node(NULL,NULL,0);
	upgrade(version[0],version[1],0,n-1,4,1);

	//更新到version-2
	version[2] = new Node(NULL,NULL,0);
	upgrade(version[1],version[2],0,n-1,2,10);
	
	cout<<"In version 1, query(0,4) :";
	cout<<query(version[1],0,n-1,0,4)<<endl;
	
	cout<<"In version 2, query(3,4) :";
	cout<<query(version[2],0,n-1,3,4)<<endl;
	
	cout<<"In version 0, query(0,3) :";
	cout<<query(version[0],0,n-1,0,3)<<endl;
	

	return 0;
}
