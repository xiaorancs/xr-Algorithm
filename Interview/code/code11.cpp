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

const int MAXN = 15;
vector<string> vecs;
int visit[10] = {0};
int n,sum = 0;
void dfs(int i){
	if(i==n) sum++;
	else {
		for(int j=0;j<vecs[i].size();j++){
			if(visit[vecs[i][j] - '0'] == 0){
				visit[vecs[i][j] - '0'] = 1;
				dfs(i+1);
				visit[vecs[i][j] - '0'] = 0;
			}
		}
	}
}

int main()
{
	string s;
	while(cin>>n){
		vecs.clear();//清除上次的赋值
		memset(visit,0,sizeof(visit));
		sum = 0;
		for(int i=0;i<n;i++){
			cin>>s;
			vecs.push_back(s);
		}
		dfs(0);
		
		cout<<sum<<endl;
	}
	
	return 0;
}
