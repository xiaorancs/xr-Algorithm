#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
//这里的测试数据默认是a数组
int a[] = {1,2,3,2,2};
//int a[] = {1,2,3,4,5};
bool isThisDigit(int res,int n){
	int k = 0;
	for(int i=0;i<n;i++){
		if(res == a[i]) k++;
	}
	return k > n/2;
}


//排序+验证
int test1(int n){
	sort(a,a+n);
	int result = a[n/2];
	//验证
	if(isThisDigit(result,n)) return result;
	else return 0;	
}

int test2(int n){
	map<int,int> cnt;
	for(int i=0;i<n;i++){
		cnt[a[i]] ++;
	}
	map<int,int>::iterator it;
	int result = 0,k = 0;
	for(it = cnt.begin();it!=cnt.end();++it){
		if(it->second > k){
			result = it -> first;
			k = it->second;
		}
	}
	if(isThisDigit(result,n)) return result;
	else return 0;
}

int test3(int n){
	int result=a[0],k=1;

	for(int i=1;i<n;i++){
		if(a[i] == result) k++;
		else k--;
		
		if(k==0){//更新候选值
			result = a[i];
			k = 1;
		}
	}
	if(isThisDigit(result,n)) return result;
	else return 0;
}


int main()
{
	cout<<test1(5)<<endl;
	cout<<test2(5)<<endl;
	cout<<test3(5)<<endl;
	
	return 0;
}

