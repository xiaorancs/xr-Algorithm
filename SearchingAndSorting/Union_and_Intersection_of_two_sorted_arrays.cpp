/**
 *Author: xiaoran
 *Time: 2017-12-01 16:06
 *Problem:
 *	求出两个有序数组a和b的并集和交集.
 *
 *方法1. 遍历两个数据,类似与归并排序中的一次合并的过程,时间复杂度是O(m+n)
 *方法2. 基于搜索,因为两个数组都有序,对长度较小的数据在两个数组中使用二分查找操作,
 *		 如果能找到,就是并集.
 *
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class UnionAndItersection{
private:
	int* a;
	int* b;
	int alen,blen;
public:
	int* unionSet;
	int* intersectionSet;
	int unionlen,intersectionlen;
	UnionAndItersection(int arr1[],int arr2[],int n1,int n2){
		a = new int[n1];
		b = new int[n2];
		unionSet = new int[n1+n2];
		intersectionSet = new int[n1];
					
		for(int i=0;i<n1;i++){
			a[i] = arr1[i];
		}
		for(int i=0;i<n2;i++){
			b[i] = arr2[i];
		}
		/*
		for(int i=0;i<n1;i++){
			cout<<a[i]<<endl;
		}
		*/
//		memcpy(a, arr1, n1);
//		memcpy(b, arr2, n2);
		alen = n1;
		blen = n2;
		unionlen = intersectionlen = 0;
	}	
	/**
	 *两个数组的并集
	 */ 
	void unions();
	//另个数组的交集
	void intersection();

	int * getUnionSet(){
		return unionSet;
	}

};

void UnionAndItersection::unions(){
	int i=0,j=0,k=0;
	while(i<alen && j<blen){
		if(a[i]<b[j]){
			unionSet[unionlen++] = a[i++];
		}
		else if(a[i]>b[j]){
			unionSet[unionlen++] = b[j++];
		}
		else{//a[i] == b[j]
			unionSet[unionlen++] = a[i++];
			j++;
		}
	}
	while(i<alen){
		unionSet[unionlen++] = a[i++];
	}
	while(j<blen){
		unionSet[unionlen++] = b[j++];
	}
}


void UnionAndItersection::intersection(){
	int i=0,j=0,k=0;
	int n1 = sizeof(a) / sizeof(a[0]);
	int n2 = sizeof(b) / sizeof(b[0]);
	while(i<alen && j<blen){
		if(a[i]<b[j]){
			i++;
		}
		else if(a[i]>b[j]){
			j++;
		}
		else{//a[i] == b[j]
			intersectionSet[intersectionlen++] = a[i++];
			j++;
		}
	}
}


int main()
{
	int arr1[] = {1, 2, 4, 5, 6};
	int arr2[] = {2, 3, 5, 7};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	UnionAndItersection unioniter(arr1,arr2,m,n);

	unioniter.unions();
	unioniter.intersection();
	cout<<"并集的长度:"<<unioniter.unionlen<<endl;
	for(int i=0;i<unioniter.unionlen;i++){
		cout<<unioniter.unionSet[i]<<" ";
	}
	cout<<endl;
	cout<<"交集的长度:"<<unioniter.intersectionlen<<endl;
	for(int i=0;i<unioniter.intersectionlen;i++){
		cout<<unioniter.intersectionSet[i]<<" ";
	}
	cout<<endl;
	return 0;
}
