/**
 *Author: xiaoran
 *Time: 2018-01-22 20:05
 *
 *Problem:
 * 求两个节点的最近公共祖先。
 */

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

// 二叉树的节点个数。
const int V = 9;

int euler[2*V - 1];
int level[2*V - 1];

int firstOccurrence[V+1];

int ind= 0;

struct Node{
	int key;
	struct Node * left;
	struct Node * right;
	Node(){};
	Node(int _key,struct Node* _left,struct Node* _right):
		key(_key),left(_left),right(_right){};
};


Node * newNode(int k){
	Node *temp = new Node(k,NULL,NULL);
	return temp;
}

// get euler, level, firstOccurrence
void eulerTour(Node * root,int l){
	if(root){
		euler[ind] = root->key;
		level[ind] = l;

		ind ++;
		
		// 第一个出现
		if(firstOccurrence[root->key] == -1){
			firstOccurrence[root->key] = ind - 1;
		}


		// left
		if(root->left){
			eulerTour(root->left, l+1);
			
			// 回来之后，还有路过自己的节点
			euler[ind] = root->key;
			level[ind] = l; // 层次不变
			ind ++;
		}

		// right
		if(root->right){
			eulerTour(root->right, l+1);
			euler[ind] = root->key;
			level[ind] = l;

			ind ++;
		}

	}
}

void createSTUtil(int arr[],int ss,int se,int *st,int si){
	if(ss == se){
		st[si] = arr[ss];
		return;
	}
	else{
		int mid = (ss+se)/2;
		// left
		createSTUtil(arr,ss,mid,st,si*2+1);
		
		// right
		createSTUtil(arr,mid+1,se,st,si*2+2);

		st[si] = min(st[si*2+1],st[si*2+2]);
	}
}

// segment tree
int* createST(int arr[], int n){
	int x = log2(n)+1;

	int max_size = pow(2,x);// 线段树的个数

	int *st = new int[max_size];
	
	createSTUtil(arr,0,n-1,st,0);
	
	return st;
}

// RMQUtil
int RMQUtil(int *st,int si,int ss,int se,int qs,int qe){
	if(qs<=ss && se<=qe){
		return st[si];
	}

	if(se < qs || qe < ss){
		return -1;
	}
	
	// 递归
	int mid = (ss + se) / 2;

	// left
	int ql = RMQUtil(st,si*2+1,ss,mid,qs,qe);
	
	// right
	int qr = RMQUtil(st,si*2+2,mid+1,se,qs,qe);
	
	if(ql == -1) return qr;
	else if(qr == -1) return ql;

	return (level[ql] < level[qr]) ? ql:qr;

}

// RMQ
int RMQ(int* st,int n,int qs,int qe){
	if(qs>qe || qs>n-1 || qe<0){
		printf("Invalid Input!");
		return -1;
	}
	
	return RMQUtil(st,0,0,n-1,qs,qe);
}


// LCA
int findLCA(Node* root, int u,int v){
	
	memset(firstOccurrence,-1,sizeof(firstOccurrence));
	ind = 0;

	// 使用欧拉便利得到三个数组
	eulerTour(root,0);

	// 创建segment tree
	int *st = createST(level, 2*V - 1);
		
	// 注意大小顺序
	if(firstOccurrence[u] > firstOccurrence[v]){
		swap(u,v);
	}

	cout<<"euler :";
	for(int i=0;i<2*V-1;i++){
		cout<<euler[i]<<" ";
	}
	cout<<endl;

	cout<<"level :";
	for(int i=0;i<2*V-1;i++){
		cout<<level[i]<<" ";
	}
	cout<<endl;
	
	cout<<"firstOccurrence :";
	for(int i=1;i<=V;i++){
		cout<<firstOccurrence[i]<<" ";
	}
	cout<<endl;

	

	//得到对应的下标
	int qs = firstOccurrence[u];
	int qe = firstOccurrence[v];

//	cout<<qs<<" "<<qe<<endl;

	int index = RMQ(st, 2*V-1, qs, qe);

	return euler[index];
}



int main()
{
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	root->left->right->left = newNode(8);
	root->left->right->right = newNode(9);
	
	int u = 4, v = 9;

	printf("The LCA of node %d and node %d is node %d. \n",
			u,v,findLCA(root,u,v));
	
	return 0;
}
