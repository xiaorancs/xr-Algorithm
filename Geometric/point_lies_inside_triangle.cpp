/**
 *Author: xiaoran
 *Time: 2017-12-29 13:36
 *Problem:
 *	判断一个点是否在三角形的内部。
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
};

// 向量叉乘计算面积
double Area(Point a,Point b,Point c){
	Point aa(b.x-a.x,b.y-a.y);
	Point bb(c.x-a.x,c.y-a.y);

	return fabs(aa.x*bb.y - aa.y*bb.x) / 2;
}

// 保证输入是三角形
bool isInside(Point a,Point b,Point c,Point p){
	double A = Area(a,b,c);
	double A1 = Area(a,b,p);
	double A2 = Area(a,p,c);	
	double A3 = Area(p,b,c);
	
	return A == A1 + A2 + A3;
}


int main()
{
	Point a(0,0);
	Point b(2,0);
	Point c(1,3);
	Point p1(1,1);
	Point p2(5,6);

	if(isInside(a,b,c,p1)) cout<<"Inside!"<<endl;
	else cout<<"Not Inside!"<<endl;

	if(isInside(a,b,c,p2)) cout<<"Inside!"<<endl;
	else cout<<"Not Inside!"<<endl;

	return 0;
}
