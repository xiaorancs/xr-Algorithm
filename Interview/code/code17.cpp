/**
 *Author: xiaoran
 *座右铭：既来之，则安之
 */
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

void printUnsortedArray(int arr[],int n){
	int i,s,e;
	for(s=1;s<n;s++){
		if(arr[s]<arr[s-1]) break;
	}
	if(s==n){
		printf("Array is sorted!\n");
		return ;
	}
	// printf("%d\n",s);
	for(e=n-1;e>0;e--){
		if(arr[e-1]>arr[e]) break;
	}
	//找到[s,e]之间的最值，
	int maxV,minV;
	maxV = minV = arr[s];
	for(i=s;i<=e;i++){
		if(maxV < arr[i]) maxV = arr[i];
		if(minV > arr[i]) minV = arr[i];
	}
	//在[0,s-1]找到minV的位置
	for(i = 0;i<s;i++){
		if(arr[i] > minV){
			s = i;
			break;
		}
	}
	//在[e+1,n-1]中找到maxV的位置
	for(i=e+1;i<n;i++){
		if(arr[i] < maxV){
			e = i;
			break;
		}
	}
	printf("%d %d\n",s,e);
}
int a[MAXN];

int main()
{

	int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	// printf("%d\n",arr_size);

	int arr1[] = {10, 9,8,7,6,5,4,3,2,1};
	int arr1_size = sizeof(arr)/sizeof(arr[0]);
	
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}	
		printUnsortedArray(a,n);
	}

	// printUnsortedArray(arr,arr_size);
	// printUnsortedArray(arr1,arr1_size);
	return 0;
}
