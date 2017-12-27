/**
 *Author: xiaoran
 *Time: 2012-12-27 20:11
 *Problem:
 *	graham scan 算法解决凸包问题
 */

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
};

Point p0;//左下角的点

// 距离函数
int distSq(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

//(p,q,r)的角度，画图根据斜率考虑
// 0 --> 共线
// 1 --> 顺时针
// 2 --> 逆时针

int orientation(Point p,Point q,Point r){
	int val = (q.y-p.y)*(r.x-q.x) - 
			  (q.x-p.x)*(r.y-q.y);
	
	if(val == 0) return 0;
	return val > 0 ? 1:2;

}


// 比较方式,找到左下角的坐标
int cmp(Point a,Point b){
	if(a.y < b.y) return 1;
	if(a.y==b.y && a.x < b.x) return 1;
	return 0;
}	

// 定义极角的比较方式,逆时针比较的方式，看图
int cmpo(Point a,Point b){
	int flag = 0;
	int o = orientation(p0,a,b);// 三个点共线，返回距离远的优先
	if (o == 0 && distSq(p0,a) < distSq(p0,b)){
		flag = 1;
	}
	// (p0,a,b)逆时针，表示(p0,a) > (p0,b) 
	if(o==2) flag = 1;
	return flag;
}

// 得到栈的栈顶的第二个点
Point secondPoint(stack<Point> &s){
	Point a = s.top();
	s.pop();
	Point b = s.top();
	s.push(a);

	return b;
}


// 计算凸包
void convexHull(Point points[],int n){
	
	// 找到左下角的点
	sort(points,points+n,cmp);
	p0 = points[0];


	//根据极角值排序剩下的N-1个点
	sort(points+1,points+n,cmpo);

	// 检查时候有共线的点(极角相同的点),移除距离p0近的点
	int m = 1;
	for(int i=1;i<n;i++){
//		cout<<points[i].x<<" "<<points[i].y<<endl;

		while(i<n-1 && orientation(p0,points[i],points[i+1]) == 0) i++;
		
		// 纪录唯一极角的点,排序时，是根据距离远的优先
		points[m++] = points[i];
	}
	// 在新的数组中，找到凸包，每次根据最新的两个点判断是否接受下一个点
	// 如果p,c,n,(p,c,n)是逆时针或者共线就接受，
	// 否则就不接受,用n更新c
	
	// 不能组成多边形
	if(m < 3) return;

	stack<Point> s;
	s.push(points[0]);
	s.push(points[1]);
	s.push(points[2]);

	// 根据最后入栈的两个点，判断时候接受下一个点
	for(int i=3;i<m;i++){
		//不是逆时针，就更新当前的点
		while(orientation(secondPoint(s),s.top(),points[i])!=2){
			s.pop();
		}
		s.push(points[i]);
	}

	//打印点
	while(!s.empty()){
		Point p = s.top();
		cout<<"("<<p.x<<","<<p.y<<")"<<endl;
		s.pop();
	}
}

int main()
{
	
	Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
		             {0, 0}, {1, 2}, {3, 1}, {3, 3}};
	int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);

	return 0;
}
