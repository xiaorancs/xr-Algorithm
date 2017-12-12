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
string int2str(int k){
	string s = "";
	while(k){
		s += '0' + k%10;
		k /= 10;
	}
	reverse(s.begin(),s.end());
	return s;
}


int main()
{

	string s;
	while(cin>>s){
		string res="";
		int k = 1;
		for(int i=1;i<s.size();i++){
			if(s[i] == s[i-1]) k++;
			else{
				res += int2str(k);
				res += s[i-1];
				k = 1;
			}
		}
		res += int2str(k);
		res += s[s.size()-1];
		cout<<res<<endl;
	}
	return 0;
}
