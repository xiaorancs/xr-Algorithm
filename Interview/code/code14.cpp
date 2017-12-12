/**
 *Author: xiaoran
 *座右铭：既来之，则安之
 */
/**
 * 
 *从一个数组中，选出2或者3个数，使得他们的和能够被3整除，
 * 为有多少中选择的方式。
 * 余数定理，如果a % 3 = 1，b % 3 = 2则 (a+b)%3=0
 * 我们只需要纪录每个数模3之后的余数的个数，从余数中进行2、3组合即可
 * 共有以下集中情况：直接用0,1,2表示余数为0,1,2的数字
 * 1、 0+0 (选2个能够被3整除的数)
 * 2、 0+0+0 (选3个能够被3整除的数)
 * 3、 1+2
 * 4、 0+1+2
 * 5、 1+1+1
 * 6、 2+2+2
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
int main() {
	//code
	int t,n,x;
	cin>>t;
	while(t--){
	    cin>>n;
	    int c[3] = {0};
	    for(int i=0;i<n;i++){
	        cin>>x;
	        c[x%3]++;
	    }
	    int sum = 0;
	    // 按照上述的情况进行加法原则
	    sum += c[0]*(c[0]-1) / 2;
	    sum += c[0]*(c[0]-1)*(c[0]-2) / 6;
	    sum += c[1]*c[2];
	    sum += c[0]*c[1]*c[2];
	    sum += c[1]*(c[1]-1)*(c[1]-2) / 6;
        sum += c[2]*(c[2]-1)*(c[2]-2) / 6;
	    
	    cout<<sum<<endl;
	}
	
	return 0;
}
