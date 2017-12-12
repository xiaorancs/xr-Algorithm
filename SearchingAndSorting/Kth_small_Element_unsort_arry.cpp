/**
 *Author:xiaoran
 *Time: 2017-11-13 14:17
 *Problem:
 *	在无序数组中找到第K小的数，返回
 *
 *Solution： 
 *	1、排序，返回第k个数，O(nlong)
 *	2、使用快速排序中使用到的一次划分，根据随机的性质，期望的时间复杂度O(n)
 *	3、最坏线性时间的算法，最坏情况下O(n)
 *	4、
 */ 

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int kthSmallest_1(int arr[],int n,int k){
	sort(arr,arr+n);
	return arr[k-1];
}

/**
 *核心思想：快排的一次随机划分，每次找到一个确定的位置i
 *	1、i == k return arr[k]
 *	2、i < k 对i+1 - n重复上诉操作
 *	3、i > k 对0 - i-1重读上述操作
 *	直到结束
 */ 
int randPartition(int arr[],int l,int r){
	int x = arr[l];
	int i=l+1,j=r;
	while(i<j){
		while(arr[i]<x && i<r) i++;
		while(arr[j]>=x && j>l) j--;
		if(i<j){
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	// 交换最后一个位置
	swap(arr[l],arr[j]);
	return j;
}


int kthSmallest_2(int arr[],int l,int r,int k){
	if(k<0 || k > r-l+1) return -1;
	
	int pos = randPartition(arr,l,r);

//	cout<<pos<<endl;

	//使用相对位置
	if(pos-l+1 == k){
		return arr[pos];
	}
	else if(pos-l+1 > k){//在左边
		return kthSmallest_2(arr,l,pos-1,k);
	}
	else{//在右边，因为使用的是相对位置，所以k要减去左边丢弃的数的个数
		return kthSmallest_2(arr,pos+1,r,k-(pos-l+1));
	}
}


/**
 * 最坏情况下时间复杂度是O(n)
 * 仍然使用快速排序的一次划分，将数据分成n/5组，
 * 1、将数组arr等份成 n/5 组，每组有5个元素，当然最后一组可能少于5个元素。
 * 2、对每一个小组排序得到中位数，sort(arr,arr+5), arr[n/2]创建一个中位数数组
 *	  median[]存储所有的n/5组数的中位数。
 * 3、medOfMed = kthSmallest(median[0...n/5-1],n/10)
 * 4、partition arr[] 根据medOfMed,返回其下标，position。
 * 5、if pos = k return modOfMed
 *	  if pos < k return kthSmallest(arr[l ... pos-1],k)
 *	  if pos > k return lthSmallest(arr[pos+1 ... r],k-pos+l-1)
 *
 */ 

/**
 *找个中位数
 */ 
int findMedian(int arr[],int n){
	sort(arr,arr+n);
	return arr[n/2];
}

/**
 *一次快速的划分
 */ 
int partition(int arr[],int l,int r,int x){
	int i,j;
	for(i=l;i<=r;i++){
		if(arr[i]==x) break;
	}
	swap(arr[i],arr[l]);
	
	/**
	i = l+1;
	j = r;
	while(i<j){
		while(arr[i]<=x && i<r) i++;
		while(arr[j]>=x && j>l) j--;
		
		if(i<j){
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}**/

	i = l;
	for(j=i;j<r;j++){
		if(arr[j]<=x){
			swap(arr[i],arr[j]);
			i++;
		}
	}
	

	swap(arr[j],arr[l]);
	return i;
}

int kthSmallest_3(int arr[],int l,int r,int k){
	if(k>0 && k<=r-l+1){
		int n = r-l+1;
		int i,median[(n+4)/5];

		for(i=0;i<n/5;i++){
			median[i] = findMedian(arr+l+i*5,5);
		}
		//处理尾端
		if(i*5<n){
			median[i] = findMedian(arr+l+i*5,n%5);
		}
		//得到中位数数组的中位数
		int medOfMed = (i==1) ? median[i-1]:kthSmallest_3(median,0,i-1,i/2);
		
		// 4根据中位数划分数据集
		int pos = partition(arr,l,r,medOfMed);
		
	//	cout<<pos<<endl;

		// 5找到第k小的数
		if(pos-l == k-1) return arr[pos];
		if(pos-l > k-1) return kthSmallest_3(arr,l,pos-1,k);

		return kthSmallest_3(arr,pos+1,r,k-pos+l-1);
	}
	//不存在
	return -1;
}


int main()
{
	int arr[] = {12,3,5,7,4,19,26};
	int arr1[] = {10,5,6,2,8,1,9};
	int n = sizeof(arr) / sizeof(arr[0]);

	int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k = 1;
	int k1 = 3;
	cout << "Test1 kthsmallest_1 "<< k <<"th smallest element is " << kthSmallest_1(arr,n,k)<<endl;
	cout << "Test1 kthsmallest_2 "<< k <<"th smallest element is " << kthSmallest_2(arr,0,n-1,k)<<endl;
	cout << "Test1 kthsmallest_3 "<< k << "th smallest element is " << kthSmallest_3(arr,0,n-1,k)<<endl;
	
	cout << "Test2 kthsmallest_1 "<< k1 <<"th smallest element is " << kthSmallest_1(arr1,n1,k1)<<endl;
	cout << "Test2 kthsmallest_2 "<< k1 <<"th smallest element is " << kthSmallest_2(arr1,0,n1-1,k1)<<endl;
	cout << "Test2 kthsmallest_3 "<< k1 << "th smallest element is " << kthSmallest_3(arr1,0,n1-1,k1)<<endl;
	return 0;
}



/**
 *注意：kthSmallest_3()函数有bug。
 *
 */ 
