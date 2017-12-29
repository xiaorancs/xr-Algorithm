/**
 *Author: xiaoran
 *Time: 2017-12-29 13:52
 *Problem:
 *	判断四个点是否是正方形
 */ 

#include <stdio.h>
#include <math.h>

struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
};

int distSq(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool isSquare(Point p1,Point p2,Point p3,Point p4){
	int d2 = distSq(p1,p2);
	int d3 = distSq(p1,p3);
	int d4 = distSq(p1,p4);
	
	if(d2 == d3 && 2*d2 == d4){
		if(distSq(p4,p2) == distSq(p4,p3) && distSq(p4,p2) == d2)
			return true;
	}

	if(d2 == d4 && 2*d2 == d3){
		if(distSq(p3,p2) == distSq(p3,p4) && distSq(p3,p2) == d2)
			return true;
	}
	
	if(d3 == d4 && 2*d3 == d2){
		if(distSq(p2,p3) == distSq(p2,p4) && distSq(p2,p3) == d3)
			return true;
	}
	return false;
}



int main()
{
	Point p1 = {1,1},p2={1,2},p3={2,2},p4={2,1},p5={3,1};
	
	if(isSquare(p1,p2,p3,p4)) printf("Yes\n");
	else printf("No\n");

	if(isSquare(p1,p2,p3,p5)) printf("Yes\n");
	else printf("No\n");

	return 0;
}


