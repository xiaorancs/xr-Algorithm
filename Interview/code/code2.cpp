#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int a[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

vector<int> print(int n){
	vector<int> result;
	int begin=0,end=n-1,k = 0;	
	//前半部分
	while(end > -1){
		//每次的行都是从0开始，列递加
		int i = end;
		begin = 0;
		while(i <= n-1){
			result.push_back(a[begin][i]);
			begin ++;
			i ++;
		} 
		--end;
	}
	//下半部分
	begin = 1; end = 0;
	while(begin < n){
		//每次的列都是从0开始，行递加
		int i = begin;
		end = 0;
		while(i <= n-1){
			result.push_back(a[i][end]);
			i++;
			end++;
		} 
		++begin;
	}	
	return result;
	
}

int main()
{
	vector<int> result = print(4);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}	
	cout<<endl;
	return 0;
}
