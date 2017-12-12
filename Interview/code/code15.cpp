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
#include<queue>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
typedef long long LL;
const int MAXN = 1005;

int main() {
	//code
	int n,x;
	while(cin>>n){
	    vector<int> a;
	    priority_queue <int> minheap;//count left part 值越大优先级越大
        priority_queue <int,vector<int>,greater<int> > maxheap;// right part值越小优先级越大
        int minsize,maxsize,current_med;
        minsize = maxsize = current_med = 0;
	    for(int i=0;i<n;i++){
	       cin>>x;
	       a.push_back(x);
	       //如果当前的值大于中位数，就插入到右边的小根堆
	       if(x <= current_med){
	           minheap.push(x);
	           minsize ++;
	       }
	       else{
	           maxheap.push(x);
	           maxsize ++;
	       }
	       //有一边超过了两个数，证明二者必须分开
	       if(maxsize - minsize >= 2){
	           int tmp = maxheap.top();
	           maxheap.pop();
	           maxsize --;
	           minheap.push(tmp);
	           minsize ++;
	       }
	       if(minsize - maxsize >= 2){
	           int tmp = minheap.top();
	           minheap.pop();
	           minsize --;
	           maxheap.push(tmp);
	           maxsize ++;
	           
	       }
	       //cout<<"minsize:"<<minsize<<endl;
	       //cout<<"maxsize:"<<maxsize<<endl;

	       //根据三种情况得到中位数
	       if(maxsize == minsize){
	           current_med = (maxheap.top() + minheap.top()) / 2;
	       }
	       if(maxsize < minsize){
	           current_med = minheap.top();
	       }
	       if(maxsize > minsize){
	           current_med = maxheap.top();
	       }
            cout<<current_med<<endl;	       
	    }
	}
	return 0;
}
