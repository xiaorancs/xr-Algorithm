#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;

const int MAXN = 105;
struct Point{
	int x;
	int y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
};
int Distance(Point p1,Point p2){
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

Point p[MAXN];
int main()
{
	int n,wt,tt,x,y;
	Point start(0,0),tmp(2,2);
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>x;
			p[i].x = x;
		}
		for(int i=0;i<n;i++){
			cin>>y;
			p[i].y = y;
		}
		cin>>x>>y;
		Point end(x,y);
		cin>>wt>>tt;
		int ans = Distance(start,end) * wt;
		for(int i=0;i<n;i++){
			ans = min(ans, Distance(start,p[i]) * wt + Distance(p[i],end) * tt);
		}
		cout<<ans<<endl;
	}	

	return 0;
}
