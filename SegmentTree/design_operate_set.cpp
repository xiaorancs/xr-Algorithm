/**
 *Author: xiaoran
 *Time: 2017-12-19 11:36
 *Problem:
 *	设置一个数据结构,支持插入一个数,删除一个数,查找中位数的操作
 */ 

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class OperateSet{
	public:
		int *data;
		int MAX_ELEM;
		int length;

		OperateSet(){
			// 默认使用内部初始化的大小
			MAX_ELEM = 1000005;
			data = new int[MAX_ELEM];
			memset(data,0,sizeof(data));
			length = 0;

		}
		OperateSet(int max_elem){
			MAX_ELEM = max_elem;
			data = new int[MAX_ELEM];
			memset(data,0,sizeof(data));
			length = 0;
		}
		void insertElem(int x);
		void deleteElem(int x);
		int getMedian();
};

/**
 *实现类的函数
 *insert element
 */ 
void OperateSet::insertElem(int x){
	data[x] ++;
	if(x > OperateSet::MAX_ELEM){
		OperateSet::MAX_ELEM = x;
	}
	OperateSet::length ++;
}

/**
 *删除
 */ 
void OperateSet::deleteElem(int x){
	if(data[x] > 0){
		data[x] --;
	}
	OperateSet::length --;
}

/**
 *得到中位数
 */ 
int OperateSet::getMedian(){
	int sum = 0;
	int i = 0;
	while(sum <= OperateSet::length / 2){
		i++;
		sum += data[i];
	}
	return i;
}


/**
 *用线段树的方式解决这个问题
 *
 */ 

class SegmentTreeSet{
	public:
		int *segmentTree;
		int MAX_ELEM;// 最大值
	
	SegmentTreeSet(){
		MAX_ELEM = 1000005;
		segmentTree = new int[MAX_ELEM];
		memset(segmentTree,sizeof(segmentTree),0);
	}
	
	SegmentTreeSet(int max_elem){
		MAX_ELEM = max_elem;
		segmentTree = new int[MAX_ELEM];
		memset(segmentTree,sizeof(segmentTree),0);
	}
	
	/**
	 *更新节点,
	 *[a,b]: 线段树的区间
	 *x: 修改的下标
	 *diff: 增加的值,1: insert, -1: delete
	 *
	 */ 
	void update(int node,int a,int b,int x,int diff);

	int findKth(int node,int a,int b,int k);

	void insertElem(int x){
		update(1,0,MAX_ELEM,x,1);
	}
	void deleteElem(int x){
		update(1,0,MAX_ELEM,x,-1);
	}
	int getMedian(){
		int k = (segmentTree[1]+1)/2;//根节点的一半值
		return findKth(1,0,MAX_ELEM,k);
	}	

};

void SegmentTreeSet::update(int node,int a,int b,int x,int diff){
	if(a==b && a==x){
		SegmentTreeSet::segmentTree[node] += diff;
		return ;
	}
	//递归更新
	if(x<a || x>b) return;

	//注意这里的下标从1开始,与前几个文件不一样
	int mid = (a+b)/2;
	SegmentTreeSet::update(node*2,a,mid,x,diff);
	SegmentTreeSet::update(node*2+1,1+mid,b,x,diff);
	
	SegmentTreeSet::segmentTree[node] = SegmentTreeSet::segmentTree[node*2]
									  +SegmentTreeSet::segmentTree[node*2+1];
}

/**
 *返回线段树的第k个节点,
 *
 */ 

int SegmentTreeSet::findKth(int node,int a,int b,int k){
	if(a == b){//叶节点
		return SegmentTreeSet::segmentTree[node]? a : -1;
	}

	int mid = (a + b) / 2;

	if(SegmentTreeSet::segmentTree[node*2] >= k){
		return SegmentTreeSet::findKth(node*2,a,mid,k);
	}
	else{
		return SegmentTreeSet::findKth(node*2+1,mid+1,b,k-SegmentTreeSet::segmentTree[node*2]);
	}
}








int main()
{
	
	OperateSet opset;
	opset.insertElem(1);
	opset.insertElem(4);
	opset.insertElem(7);

	cout<< "{1,4,7}的中位数 = "<< opset.getMedian() << endl;
	
	opset.insertElem(8);
	opset.insertElem(9);
	
	cout<< "{1,4,7,8,9}的中位数 = "<< opset.getMedian() << endl;
	
	opset.deleteElem(1);
	opset.deleteElem(8);

	cout<< "{4,7,9}的中位数 = "<< opset.getMedian() << endl;
	
	cout<<"长度="<<opset.length<<endl;

	cout<<"segment tree set:"<<endl;
	SegmentTreeSet sts;

	sts.insertElem(1);
	sts.insertElem(4);
	sts.insertElem(7);
	cout<< "{1,4,7}的中位数 = "<< sts.getMedian() << endl;
	
	sts.insertElem(8);
	sts.insertElem(9);
	
	cout<< "{1,4,7,8,9}的中位数 = "<< sts.getMedian() << endl;
	
	sts.deleteElem(1);
	sts.deleteElem(8);

	cout<< "{4,7,9}的中位数 = "<< sts.getMedian() << endl;
	
	cout<<"长度="<<sts.segmentTree[1]<<endl;


	return 0;
}
