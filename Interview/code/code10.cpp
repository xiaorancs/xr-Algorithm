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
vector<int> operate(vector<int> a){
	vector<int> ans;
	int n = a.size();
	for(int i=0;i<n;i++){
		ans.push_back((a[i] + a[(i+1)%n])%100);
		//cout<<ans[i]<<" ";
	}
	//cout<<endl;
	return ans;
}


int main()
{
	int n,k,b;
	while(cin>>n>>k){
		vector<vector<int> > totalQue;
		
		vector<int> a;
		for(int i=0;i<n;i++){
			cin>>b;
			a.push_back(b);
		}
		map<vector<int>,bool> visit;
		visit[a] = true;
		totalQue.push_back(a);
		int qk = k+1;
		for(int i=0;i<k;i++){
			vector<int> b = operate(a);
			a = b;
			if(visit[a] == true){//出现循环节
				qk = i;
				break;
			}
			else{
				visit[a] = true;
				totalQue.push_back(a);
			}
		}
		cout<<qk<<endl;
		cout<<totalQue[k%qk][0];
		for(int i=1;i<totalQue[k%qk].size();i++){
			cout<<" "<<totalQue[k%qk][i];
		}
		cout<<endl;
		
	}
	
	return 0;
}
