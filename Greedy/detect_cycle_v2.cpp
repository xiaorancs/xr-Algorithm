/**
 *Author: xiaorn
 *Time: 2018-01-29 21:25
 *Problem:
 *	使用rank和路径压缩技术判断图中是否有环
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>


using namespace std;

// 图的边
struct Edge{
	int src;
	int dest;
};

// 图的结构
struct Graph{
	int V,E;// 点和边的个数
	Edge* edge;
};

struct subset{
	int rank;
	int parent;
};


// find 点i的祖先
int find(subset subsets[], int i){
	// 查的时候修改i的祖先的值
	if(subsets[i].parent != i){
		subsets[i].parent = find(subsets,subsets[i].parent);
	}
	return subsets[i].parent;
}


// union x, y
void Union(subset subsets[],int x,int y){
	int xroot = find(subsets,x);
	int yroot = find(subsets,y);

	// 比较rank，采取合并的操作
	if(subsets[xroot].rank < subsets[yroot].rank){
		subsets[xroot].parent = yroot;
	}
	else if(subsets[yroot].rank < subsets[xroot].rank){
		subsets[yroot].parent = xroot;
	}
	else{// 相等, xroot就有一个子树，增加xroot的高度
		subsets[yroot].parent = xroot;
		subsets[xroot].rank ++;
	}

}

// 创建图
Graph* createGraph(int V,int E){
	Graph* graph = (struct Graph *) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = (struct Edge*) malloc(sizeof(struct Edge));
	
	return graph;
}


// is cycle
int isCycle(Graph* graph){
	subset* subsets = (struct subset*)malloc(sizeof(struct subset) * graph->V);

	// init
	for(int v=0;v<graph->V;v++){
		subsets[v].parent = v;
	}
	
	// 便利所有的边
	for(int e=0;e<graph->E;e++){
		int x = find(subsets,graph->edge[e].src);
		int y = find(subsets,graph->edge[e].dest);

		if(x==y){// is cycle
			return 1;
		}
		
		// 合并
		Union(subsets,x,y);
	}
	return 0;
}


int main()
{
	int V=3,E=3;
	Graph* graph = createGraph(V,E);
	
	//add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	//add edge 1-2
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	//add edge 0-2
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;
	
	if(isCycle(graph))
	    printf( "Graph contains cycle\n");
    else
		printf( "Graph doesn't contain cycle\n");

	return 0;
}
