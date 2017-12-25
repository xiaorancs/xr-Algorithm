/**
 *Author: xiaoran
 *Time: 2017-12-25 13:17
 *Problem:
 *	jarvis算法解决凸包问题
 */ 

#include <iostream>
#include <vector>

using namespace std;
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
};

/**
 *三个点的方向,
 * 0: 共线
 * 1: 顺时针
 * 2: 逆时针
 *
 * 根据斜率进行计算,可以画图更明了
 */
int orientation(Point p,Point q,Point r){
	int val = (q.y-p.y) * (r.x-q.x) - 
			  (q.x-p.x) * (r.y-q.y);
	if(val == 0) return 0;

	return (val>0)?1:2;
}

/**
 *找到最小凸包
 *
 */ 
void convexHull(Point points[],int n){
	if (n<3) return ;

	vector<Point> hull;

	//找到最左边的点,作为第一个起始点
	int start = 0;
	for(int i=1;i<n;i++){
		if(points[i].x < points[start].x){
			start = i;
		}
	}
	int p = start,q;

	//迭代找q,并循环更新,直到循环一周
	while(1){
	
		hull.push_back(points[p]);
		q = (p+1)%n;
		for(int i=0;i<n;i++){
			//(p,q,r)是顺时针的时候需要更新
			if(orientation(points[p],points[q],points[i]) == 1){
				q = i;
			}
		}
		// 更新p,继续循环
		p = q;

		//已经搞定
		if(p==start) break;
	}

	for(int i=0;i<hull.size();i++){
		cout<< "(" << hull[i].x <<","<< hull[i].y<<")"<<endl;
	}
}

int main()
{
	Point points[] = {{0,3},{2,2},{1,1},{2,1},{3,1},{0,0},{3,3}};
	int n = sizeof(points) / sizeof(points[0]);
	cout<<n<<endl;	
	convexHull(points,n);
	return 0;
}
