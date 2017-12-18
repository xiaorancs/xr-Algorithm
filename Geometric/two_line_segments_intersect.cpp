/**
 *Author: xiaoran
 *Time: 2017-12-18 23:05
 *Problem:
 *	判断两个线段是否相交
 *
 */ 

#include <iostream>

using namespace std;

struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}

};


/**
 *判断三个点是否共线
 *x和y坐标都有重叠
 *
 * 判断q是否在pr上
 */ 
bool onSegment(Point p,Point r,Point q){
	if(q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
	   q.y <= max(p.y, r.y) && q.y >= min(p.x, r.x)) 
		return true;
	return false;
}


/**
 *计算三个点的方向:
 *0: p,q,r共线
 *1: 顺时针
 *2: 逆时针
 *
 */ 
int orientation(Point p,Point q,Point r){
	int val = (q.y - p.y) * (r.x - q.x) - 
			  (q.x - p.x) * (r.y - q.y);
	
	// 这里判断的时候建议画个图看依稀
	if(val == 0) return 0; // 共线

	return val > 0? 1: 2;
}


/**
 *验证两个线段是否相交,用两个点表示一条线段
 *p1,q1 --> 线段1
 *p2,q2 --> 线段2
 */ 
bool doIntersect(Point p1,Point q1,Point p2,Point q2){
	// 判断四中组合的方向
	int o1 = orientation(p1,q1,p2);
	int o2 = orientation(p1,q1,q2);
	int o3 = orientation(p2,q2,p1);
	int o4 = orientation(p2,q2,q1);

	//一般情况
	if(o1 != o2 && o3 != o4){
		return true;
	}
	// 特殊情况(共线)
	// p1,q1,p2共线,而且p2在线段p1q1上
	if(o1 == 0 && onSegment(p1,q1,p2)) return true;
	
	// p1,q1,q2共线,而且q2在线段p1q1上
	if(o2 == 0 && onSegment(p1,q1,q2)) return true;

	// p2,q2,p1共线,而且p1在线段p2q2上
	if(o3 == 0 && onSegment(p2,q2,p1)) return true;

	// p2,q2,q1共线,而且q1在线段p2q2上
	if(o4 == 0 && onSegment(p2,q2,q1)) return true;

	return false;

}


int main(){
	
	Point p1 = {1,1}, q1 = {10,1};
	Point p2 = {1,2}, q2 = {10,2};
	doIntersect(p1,q1,p2,q2) ? cout <<"Yes\n" : cout<<"No\n";
	
	p1 = {10,0}, q1 = {0,10};
	p2 = {0,0}, q2 = {10,10};
	doIntersect(p1,q1,p2,q2) ? cout <<"Yes\n" : cout<<"No\n";
	
	p1 = {-5,-5}, q1 = {0,0};
	p2 = {1,1}, q2 = {10,10};
	doIntersect(p1,q1,p2,q2) ? cout <<"Yes\n" : cout<<"No\n";
	
	return 0;
}


