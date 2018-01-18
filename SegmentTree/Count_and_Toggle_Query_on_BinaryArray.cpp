/**
 *Author: xiaoran
 *Time: 2018-01-18 11:00
 *
 *Problem:
 * 基于懒更新的线段树。
 */

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 10005;

int tree[MAXN] = {0};
int lazy[MAXN] = {false};

/**
  参数：
	node: 根节点
	[ss,se] node对应的区间
	[us,ue] 更新的区间

 */

void toggleUtil(int node,int ss,int se,int us,int ue){

	// this node need update
	if(lazy[node]){
		lazy[node] = false;// 更新之后修改标志
		// 修改线段树的值，这里稍微计算一个，更新之后的值是区间和-原来的值
		tree[node] = se - ss + 1 - tree[node];

		// 不是叶子节点，需要设置其子节点的lazy值
		if(se != ss){
			// 注意这里的值，如果node*2 ==> node从1开始
			// node*2+1 ==> node 从0开始，
			lazy[node*2+1] = !lazy[node*2+1];
			lazy[node*2+2] = !lazy[node*2+2];
		}
	}

	if(ue < ss || us > se || ss > se){
//		cout<<"Invalid Range!"<<endl;
		return;
	}

	// 递归更新值
	if(us <= ss && se <= ue){
		// 当前节点在修改区间内，修改当前节点的值
		tree[node] = se - ss + 1 - tree[node];
		// 设置更新标志，使用时在进行更新
		// 不是叶子节点
		if(ss != se){
			lazy[node*2+1] = !lazy[node*2+1];
			lazy[node*2+2] = !lazy[node*2+2];
		}
		return; 
	}

	int mid = (ss+se)/2;

	// left
	toggleUtil(node*2+1,ss,mid,us,ue);
	// right
	toggleUtil(node*2+2,mid+1,se,us,ue);

	if(ss < se){ // 不是叶节点，反向更新父节点
		tree[node] = tree[node*2+1] + tree[node*2+2];
	}
}


/**
  参数：
	node: segment tree的根节点
	n: 数组的大小
	[us,ue]: 更新的区间节点 

 */
void toggle(int node,int n, int us,int ue) {
	if(us < 0 || ue >=n || us>ue){
//		cout<<"Invalid Input!"<<endl;
		return;
	}

	toggleUtil(node,0,n-1,us,ue);
}




/**
  参数：
	node: 根节点
	[ss,se]: node对应的区间
	[qs,qe]: 查询的区间

 */
int countQueryUtil(int node, int ss,int se,int qs,int qe ){
	if(ss > se || qs>se || qe<ss){
		return 0;
	}

	// 更新值
	if(lazy[node]){
		tree[node] = se-ss+1-tree[node];
		lazy[node] = false;

		// 不是根节点
		if(ss!=se){
			lazy[node*2+1] = !lazy[node*2+1];	
			lazy[node*2+2] = !lazy[node*2+2];	
		}
	}

	// [ss,se] 在 [qs,qe]之内
	if(qs<=ss && se<=qe ){
		return tree[node];
	}

	int mid = (ss+se)/2;

	return countQueryUtil(node*2+1,ss,mid,qs,qe) + 
		countQueryUtil(node*2+2,mid+1,se,qs,qe);
}


/**
  参数：
	node: 线段树的根节点
	n: 数组的大小
	[qs,qe]: 查询的区间

 */
int countQuery(int node,int n,int qs,int qe){

	if(qs > qe){
		cout<<"Invalid Input!"<<endl;
		return 0;
	}
	return countQueryUtil(node,0,n-1,qs,qe);
}


int main(){

	int n = 15;
	toggle(0,n,1,12);
	toggle(0,n,2,7);

	cout<<"[2,13] sum is "<<countQuery(0,n,2,13)<<endl;

	toggle(0,n,12,14);

	cout<<"[1,14] sum is "<<countQuery(0,n,1,14)<<endl;

	return 0;
}
