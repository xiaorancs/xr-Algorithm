/**
 *Author: xiaoran
 *Time: 2017-12-07 23:28
 *Problem: 在三个排序数组中找到公共元素.
 *
 *分析:
 *	合并排序中的一个比较合并,O(n1+n2+n3)
 */ 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class Type>
vector<Type> findCommonElements(vector<Type> a,vector<Type> b,vector<Type> c){
	int n1,n2,n3,i=0,j=0,k=0;
	n1 = a.size();
	n2 = b.size();
	n3 = c.size();
	vector<Type> result;
	while(i<n1 && j<n2 && k<n3){
		if(a[i] == b[j] && a[i] == c[k]){
			result.push_back(a[i]);
			i++;
			j++;
			k++;
		}
		else if(a[i] < b[j] && a[i] < c[k]){
			i++;
		}
		else if(b[j] < a[i] && b[j] < c[k]){
			j++;
		}
		else if(c[k] < a[i] && c[k] < b[j]){
			k++;
		}
	}
	return result;
}

int main()
{

	vector<int> a,b,c;
	a.push_back(1);
	a.push_back(5);
	a.push_back(5);

	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(5);
	b.push_back(10);

	c.push_back(5);
	c.push_back(5);
	c.push_back(10);
	c.push_back(20);

	vector<int> ans = findCommonElements(a,b,c);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" "; 
	}
	cout<<endl;

	return 0;
}
