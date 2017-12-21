/**
 *Author: xiaoran
 *Time: 2017-12-21 19:13
 *Problem:
 *	区间的最小公倍数
 */ 

#include <iostream>
using namespace std;

const int MAXN = 1004;

int gcd(int a,int b){
	if(b==0) return a;

	return gcd(b,a%b);
}

int lcm(int a,int b){
	
	return a/gcd(a,b)*b;
}

int segmentTree[4*MAXN];

void createSegmentTree(int node,int arr[],int start,int end){
	if(start == end){
		segmentTree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	createSegmentTree(node*2+1,arr,start,mid);
	createSegmentTree(node*2+2,arr,1+mid,end);
	
	// 更新父节点
	segmentTree[node] = lcm(segmentTree[node*2+1],segmentTree[node*2+2]);

}

int query(int node,int start,int end,int l,int r){
	if(l>end || r<start || l > r){
		return 1;
	}

	if(l<=start && r>=end){
		return segmentTree[node];
	}
	int mid = (start+end) / 2;

	return lcm(query(node*2+1,start,mid,l,r),query(node*2+2,mid+1,end,l,r));

}


int main()
{	
	int arr[] = {5,7,5,2,10,12,11,17,14,1,44};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	createSegmentTree(0,arr,0,n-1);
	
	cout<<"lcm [2,5] = " << query(0,0,n-1,2,5)<<endl;
	
	cout<<"lcm [5,10] = " << query(0,0,n-1,5,10)<<endl;

	cout<<"lcm [0,10] = " << query(0,0,n-1,0,10)<<endl;


	return 0;
}
