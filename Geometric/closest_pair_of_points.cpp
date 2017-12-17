/**
 *Author: xiaoran
 *Time: 2017-12-17 13:37
 *Problem:
 *	最近点对问题
 */ 

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Point{
	int x,y;
	Point(){};
	Point(int _x,int _y):x(_x),y(_y){}
};

int compareX(Point a,Point b){
	return a.x < b.x;
}

int compareY(Point a,Point b){
	return a.y < b.y;
}


double dist(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


/**
 *个数少的时候,直接暴力解决
 *n < 3
 */ 
double bruteForce(Point P[],int n){
	double min = DBL_MAX;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(min > dist(P[i],P[j])){
				min = dist(P[i],P[j]);
			}	
		}
	}
	return min;
}

/**
 *计算strip数组的最最小距离
 *注意,我们只计算d距离的正方形的方块内的值
 *可以看看理论
 */
double stripClosest(Point strip[],int n,double d){
	double mind = d;
	sort(strip,strip+n,compareY);
	
	if(n<2){
		return mind;
	}
	/**
	cout<<"strip11"<<endl;
	for(int i=0;i<n;i++){
		cout<<strip[i].x<<" "<<strip[i].y<<endl;
	}**/

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n && (strip[j].y-strip[i].y)<mind;j++){
			if(dist(strip[i],strip[j]) < mind){
				mind = dist(strip[i],strip[j]);
			}
		}
	}
	return mind;
}


double closestUtil(Point P[],int n){
	if(n<=3){//直接暴力
		return bruteForce(P,n);
	}

	// 找到中心线
	int mid = n / 2;
	Point midPoint = P[mid];

	// 递归计算左右子集的值
	double d = min(closestUtil(P,mid), closestUtil(P+mid,n-mid));
	
	//得打strip数组,所有距离中线d的值
	Point strip[n];
	int j = 0;
	for(int i=0;i<n;i++){
		if(abs(P[i].x-midPoint.x)<d){
			strip[j++] = P[i];
		}
	}
	/*
	cout<<"strip "<<endl;
	for(int i=0;i<j;i++){
		cout<<strip[i].x<<" "<<strip[i].y<<endl;
	}*/
	return min(d, stripClosest(strip,j,d));
}

double closest(Point P[],int n){
	sort(P,P+n,compareX);
	
	return closestUtil(P,n);
}


int main()
{
	Point P[] = {{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
	int n = sizeof(P) / sizeof(P[0]);
	
	printf("The smallest distance is %lf \n.", closest(P,n));
	return 0;
}
