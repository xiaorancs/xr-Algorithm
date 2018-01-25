/**
 *Author: xiaoran
 *Time: 2018-01-25 18:33
 *
 *Problem:
 * action select problem
 */

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
	int start;
	int end;
};

const int MAXN = 10005;

//Node node[MAXN];

int cmp(Node a,Node b){
	return a.end < b.end;
}

// get number of action
int getActionNumbers(Node node[],int n){
	
	sort(node,node+n,cmp);
	int result = 1;
	int t = 0;
	for(int i=1;i<n;i++){
		if(node[i].start >= node[t].end){
			result ++;
			t = i;
		}
	}
	return result;
}

int main()
{
	Node node[] = {{1,2},{0,6},{3,4},{8,9},{5,7},{5,9}};
	
	int n = sizeof(node) / sizeof(node[0]);
	cout<<getActionNumbers(node,n)<<endl;

	return 0;
}
