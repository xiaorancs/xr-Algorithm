#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int a[] = {10,22,5,75,65,80};

//时间复杂度是O(n^2)
vector<int> maxDifference(int *a, int n){
	vector<int> result;
	for(int i=0;i<n;i++){
		int maxdiff = 0;
		for(int j=i+1;j<n;j++){
			maxdiff = max(maxdiff,a[j] - a[i]);
		}
		result.push_back(maxdiff);
	}
	for(int i=0;i<n;i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;	
	return result;
}

vector<int> maxDifferencePlus(int *a,int n){
	vector<int> result(n,0);//后面没有比当前值大的数，就返回0
	int maxvalue = a[n-1];
	for(int i=n-1;i>=0;i--){
		if(a[i]>maxvalue) maxvalue = a[i];
		result[i] = maxvalue - a[i];
	}
	for(int i=0;i<n;i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return result;
}
vector<int> maxDifferencePlus(int *a,int begin,int end){
	vector<int> result(end-begin+1,0);//后面没有比当前值大的数，就返回0
	int maxvalue = a[end];
	for(int i=end;i>=begin;i--){
		if(a[i]>maxvalue) maxvalue = a[i];
		result[i] = maxvalue - a[i];
	}
	for(int i=begin;i<=end;i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return result;
}
int getmaxValue(vector<int> a){
	int v = 0;
    for(int i=0;i<a.size();i++){
        v = max(v,a[i]);
    }
    return v;
}


int buy2sale(int *a,int n){
	
	int result = 0;
	vector<int> left;
	vector<int> right;
	for(int i=1;i<n-1;i++){
		left = maxDifferencePlus(a,0,i);
		right = maxDifferencePlus(a,i+1,n-1);
		
		result = max(result, getmaxValue(left)+getmaxValue(right));
		
	}
	
	return result;
}

int main()
{	
	maxDifference(a,6);
	maxDifferencePlus(a,6);
	maxDifferencePlus(a,1,4);
	cout<<buy2sale(a,6)<<endl;
		
	return 0;
}
