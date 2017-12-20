/**
 *Author: xiaoran
 *Time: 2017-12-18 23:05
 *Problem:
 *	判断点p是否在多边形内部
 *
 */ 

#include <iostream>

using namespace std;

#define INF 1000
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


/**
 *点p,是否在多边形内部
 *
 */

bool isInside(Point polygon[],int n,Point p){
	//不是多变形
	if(n<3) return false;

	// 创建一个无穷的点,成为一个水平线
	Point extr = {INF, p.y};

	//计算相交线段的个数
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(doIntersect(polygon[i],polygon[(i+1)%n],p,extr)){
			// 检查p是否在线段上
			if(orientation(polygon[i],polygon[(i+1)%n],p) == 0)
				return onSegment(polygon[i],polygon[(i+1)%n],p);
			//记录相交的个数
			cnt ++;
		}
	}
	return cnt & 1; //是否是奇数
}

int main()
{
	Point polygon1[] = {{0,0},{10,0},{10,10},{0,10}};
	int n = sizeof(polygon1) / sizeof(polygon1[0]);
	Point p ={20,20};
	isInside(polygon1,n,p) ? cout<<"Yes\n": cout<<"No \n";
	
	p = {5,5};
	isInside(polygon1,n,p) ? cout<<"Yes\n": cout<<"No \n";

	p = {-1,10};
	isInside(polygon1,n,p) ? cout<<"Yes \n": cout<<"No\n";
	

	Point polygon2[] = {{0,0},{5,5},{5,0}};
	p = {3,3};
	n = sizeof(polygon2) / sizeof(polygon2[0]);
	isInside(polygon2,n,p) ? cout<<"Yes \n": cout<<"No\n";

	p = {4,0};
	isInside(polygon2,n,p) ? cout<<"Yes \n": cout<<"No\n";

	p = {8,1};
	isInside(polygon2,n,p) ? cout<<"Yes \n": cout<<"No\n";

	return 0;	
}
