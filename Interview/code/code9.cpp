#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
typedef long long LL;

const int MAXN = 1005;

int main()
{

	int n,v;
	while(cin>>n){
		vector<int> a;
		map<int,int> vis;
		for(int i=0;i<n;i++){
			cin>>v;
			a.push_back(v);
		}	
		int j=n-1;
		vis[a[n-1]] = 1;
		for(int i=n-1;i>=0;i--){
			if(vis[a[i]] == 0){
				a[--j] = a[i];
				vis[a[i]] = 1;
			}
		}
		cout<<a[j];
		for(int i=j+1;i<n;i++){
			cout<<" "<<a[i];
		}
		cout<<endl;
	
	}
	return 0;
}
