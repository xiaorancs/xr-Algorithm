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

const int MAXN = 105;
int A[MAXN],count[MAXN];

int main() {
	//code
	int t,n,x;
	cin>>t;
	while(t--){
	    cin>>n;
	    memset(count,0,sizeof(count));
	    for(int i=0;i<n;i++) cin>>A[i];
	    for(int i=0;i<n;i++){
	        cin>>x;
	        count[x] ++;
	    }
	    for(int i=1;i<=100;i++) count[i] += count[i-1];
	    cout<<count[A[0]];
	    for(int i=1;i<n;i++){
	        cout<<","<<count[A[i]];
	    }
	    cout<<endl;
	}
	
	return 0;
}
