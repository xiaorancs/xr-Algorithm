/**
 *给定一个广场，把它分为M行N列的正方形小框。现在给定有K个拉拉队员，
 *每一个拉拉队员需要站在小框内进行表演。  *但是表演过程中有如下要求：
 *（1）每一个小框只能站立一个拉拉队员；
 *（2）广场的第一行，最后一行，第一列，最后一列都至少站有一个拉拉队员；
 *（3）站在广场的四个角落的拉拉队员可以认为是同时占据了一行和一列。
 *sum = C[n*m][k] 从所有的而里面选则k个，减去不满足的条件
 *A[] = {A,B,C,D} = {2*C[(m-1)*n][k],2*C[(n-1)*m][k]} 
 *第一行不站拉拉队员的所有的站立方法有A种
 *
 *B[] = {AB,AC,AD,BC,BD,CD} = {2 * C[(m-2)*n][k],4 * C[(m-1)*(n-1)][k]}
 *最后一行不站拉拉队员的所有的方法有B种
 *
 *C[] = {ABC,ABD,ACD,BCD} = {2 * C[(m-2)*(n-1)][k],2 * C[(m-1)*(n-1)][k]}
 *第一列不站拉拉队员的所有的站立方法有C种
 *
 *D[] = {ABCD} = C[(m-2)*(n-2)][k]
 *最后一列不站拉拉队员的站立方法有D种
 *
 *sum = sum - A + B - C + D
 */

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int MOD = 1000007;
const int MAXN = 505;
int C[MAXN][MAXN];
int main()
{
	//得到组合数
	memset(C,0,sizeof(C));
	C[0][0] = 1;	
	for(int i=0;i<=MAXN;i++){
		C[i][0] = C[i][i] = 1;		
		for(int j=1;j<i;j++){
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
		}
	}	
	
		

	int T;
	int m,n,k;
	cin>>T;

	for(int i=1;i<=T;i++){
		cin>>m>>n>>k;
		int sum = C[m*n][k];
		//sum -= A,B,C,D
		sum = (sum - (2*C[(m-1)*n][k] + 2*C[(n-1)*m][k]));
		//sum += AB,AC,AD,BC,BD,CD
		sum = sum + (C[(n-2)*m][k] + C[(m-2)*n][k]+4 * C[(m-1)*(n-1)][k]);
		//sum -= ABC,ABD,ACD,BCD
		sum = sum - 2 * C[(m-2)*(n-1)][k]-2 * C[(m-1)*(n-2)][k];
		//sum += ABCD
		sum = (sum + 6*MOD + C[(m-2)*(n-2)][k]) % MOD;

		cout<<"Case "<<i<<": "<<sum<<endl;
	}	


	return 0;
}












