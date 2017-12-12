#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int MAXN = 1005;

int a[MAXN];
int test1(int n){//模拟的代码
	memset(a,0,sizeof(a));
	int k = 1;
	while(true){
		int cnt = 0;
		for(int i=0;i<=n;i++){
			if((i+1)/k % 2 == 1 && a[i] == 0){
				a[i] = 1;
			}
			if(a[i] == 0) cnt++;

			//cout<<i<<" "<<a[i]<<endl;
		}
//		cout<<cnt<<endl;
		//这是已经剩下一个值，没有被处理。
		if(cnt == 1) break;
		if(cnt>1){//还有两个以上的数，继续迭代
			k *= 2;
		}
		cnt = 0;
	}
	/**
	for(int i=0;i<=n;i++){
		cout<<i<<" ";
	}
	cout<<endl;
	for(int i=0;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	**/
	
	int value = 1;
	for(int i=0;i<=n;i++){
		if(a[i] == 0) {value = i;break;}
	}
	cout<<2*k-1<<endl;//这里就是n的位置
	return value;
}



int main()
{
	
	int n;
	while(cin>>n){
		cout<<test1(n)<<endl;	
		cout<<(int)pow(2,floor(log2(n)))-1<<endl;
	}	
	return 0;
}










