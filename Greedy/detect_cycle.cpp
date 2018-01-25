/**
 *Author: xiaoran
 *Time: 2018-01-25 21:07
 *Problem:
 *	并查集检查无向图中是否存在环
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Edge{
	int src, dest;// 边的开始和结束节点
};

// 图
struct Graph{
	// 点和边的个数
	int V, E;

	// 边的集合
	struct Edge* edge;
};

// 创建图
struct Graph* createGraph(int V,int E){
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];
	
	return graph;
}


// 查，并查集中的查, i的父节点
int find(int parent[],int i){
	if(parent[i] == -1){
		return i;
	}
	return find(parent,parent[i]);
}

// 并
void Union(int parent[], int x, int y){
	int xset = find(parent, x);
	int yset = find(parent, y);

	// 并
	parent[xset] = yset;
}

// 检查是否是环
int isCycle(struct Graph* graph){
	int *parent = new int[graph->V];
	
	// 默认是-1
	memset(parent,-1,sizeof(parent));
	
	// 遍历所有的边，通过起始和结束点判断是否有环
	for(int i=0;i<graph->E;++i){
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if(x==y) return 1;

		Union(parent, x, y);
	}
	return 0;
}

/*
	0
	|  \
	|    \
	1------2

*/


int main()
{
	int V=3, E=3;
	struct Graph* graph = createGraph(V,E);
	// add Egde
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if(isCycle(graph)){
		printf("graph contains cycle\n");
	}
	else{
		printf("graph doesn't contain cycle\n");
	}
	return 0;
}

