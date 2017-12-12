#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;

const int MAXN = 1005;

int main()
{
	string s;
	while(cin>>s){
		//所有的G在左边，B在后边，对于任何一个G，我们不用就行交换
		//只需要纪录在其前面有几个B，就需要交换多少次
		int ans = s.size()*s.size();
		int sum = 0, countb = 0;
		for(int i=0;i<s.size();i++){
			if(s[i] == 'B') countb ++;
			if(s[i] == 'G') sum += countb;
		}
		ans = sum;
		sum = 0;
		//所有的B在左边，G在后边，对于任何一个B，我们不用就行交换
		//只需要纪录在其前面有几个G，就需要交换多少次
		int countg = 0;
		for(int i=0;i<s.size();i++){
			if(s[i] == 'G') countg ++;
			if(s[i] == 'B') sum += countg;
		}
		ans = min(ans,sum);
		cout<<ans<<endl;
	}

	return 0;
}
