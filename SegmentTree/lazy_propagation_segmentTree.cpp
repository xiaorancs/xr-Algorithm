/**
 *Author: xiaoran
 *Time: 2017-12-15 17:09
 *Problem:
	基于区间和的线段树的延迟传播,

 *
 */

#include <stdio.h>
#include <math.h>

#define MAX 10000

// 默认lazy数组为0,大小和SegmentTree大小一样
int lazy[MAX] = {0};

/**
 * 更新区间[us,ue],全部加上diff
 * si->当前的节点
 * [ss,se]: 线段树当前节点对应的区间
 * [us,ue]: 更新的区间
 * diff: 更新的差值
 */
void updateRangeUtil_pass(int *st,int si,int ss,int se,int us,int ue,int diff){
	// out of range
	if(ss > se || ss > ue || se<us){
		return ;
	}
	// 叶子节点
	if(ss==se){
		st[si] += diff;
		return;
	}
	// 不是叶子节点
	int mid = (ss+se)/2;
	updateRangeUtil_pass(st,si*2+1,ss,mid,us,ue,diff);
	updateRangeUtil_pass(st,si*2+2,1+mid,se,us,ue,diff);
	
	st[si] = st[si*2+1] + st[si*2+2];
}



/**
  基于数组arr[ss,se]递归创建线段树:
  si是线段树st中的当前节点,
  return 当前节点的值(这里是查询区间的sum)
 */ 
int createSegmentTreeUtil(int arr[], int ss,int se, int *st,int si){
	if(ss == se){//叶子节点
		st[si] = arr[ss];
		return arr[ss];
	}
	// 递归构建子线段树
	int mid = ss + (se-ss)/2;
	st[si] = createSegmentTreeUtil(arr,ss,mid,st,si*2+1)
			+createSegmentTreeUtil(arr,mid+1,se,st,si*2+2);

	return st[si];
}


/**
 *创建线段树
 *
 */ 
int *createSegmentTree(int arr[],int n){
	// 申请线段树的空间
	int x = (int)(ceil(log2(n)));

	//线段树的最大空间
	int max_size = 2*(int) pow(2,x);
	int *st = new int[max_size];
	createSegmentTreeUtil(arr,0,n-1,st,0);
	return st;
}


/**
 *更新区间的值
 *st: 线段树
 *si: 当前节点
 *ss & se: 线段树的起始点和结束点 
 *qs & qe: 查询的区间端点
 *
 */ 
void updateRangeUtil(int *st,int si,int ss,int se,int us,int ue,int diff){
	//lazy[si]!=0 在更新之前,如果有没有完成的更新进先进行更新
	//再进行更新当前的值.
	if(lazy[si] != 0){
		// 需要将lazy[si]的值添加到线段树的si节点
		st[si] += (se - ss + 1) * lazy[si];

		if(ss != se){//不是叶节点
			//现在不更新子节点,设置lazy值,之后用到的时候
			//在进行更新
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2]  += lazy[si];
		}
		// 更新之后,设置lazy[si]=0
		lazy[si] = 0;
	}
	// out of range
	if(ss>se || ss>ue || se<us)
	  return ;
	
	// 当前节点在更新节点的内部
	if(ss>=us && se<=ue){
		st[si] += (se-ss+1)*diff;
		if(ss != se){//如果不是叶节点,就设置子节点作为lazy的值
			lazy[si*2+1] += diff;
			lazy[si*2+2] += diff;
		}
		return ;
	}
	// 循环更新子节点
	int mid = (ss+se) / 2;
	updateRangeUtil(st,si*2+1,ss,mid,us,ue,diff);
	updateRangeUtil(st,si*2+2,1+mid,se,us,ue,diff);

	//别忘了更新父节点
	st[si] = st[si*2+1] + st[si*2+2];
}

/**
 *更新区间节点,
 *us & ue 更新节点的区间
 *diff:  区间[us,ue] + diff
 *
 */
void updateRange(int *arr,int *st,int n,int us,int ue,int diff){
	for(int i=us;i<=ue;i++){
//		printf("%d\n",arr[i]);
		arr[i] += diff;
	}
	updateRangeUtil(st,0,0,n-1,us,ue,diff);
}


/**
 *递归函数,查询区间的和
 	st: 线段树的树根
 *	si: 线段树的初始化节点
 *	ss & se: 线段树的开始和结束的端点
 *	qs & qe: 查询的区间的端点
 *
 */
int getSumUtil(int *st,int ss,int se,int qs,int qe,int si){
	// lazy[si] !=0,需要更新后再查询.
	if(lazy[si] != 0){
		// 这个区间中的每一个值都要加上diff,lazy[si]表示需要夹的值
		st[si] += (se-ss+1)*lazy[si];

		//不是叶节点,父节点更新,添加子节点的后更新值
		if(ss!=se){
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2] += lazy[si];
		}
		// 修改si
		lazy[si] = 0;
		//printf("test");
	}
	// out of range
	if(ss>se || ss>qe || se<qs)
		return 0;
	

	if(ss>=qs && se<=qe){
		return st[si];
	}
	// 递归子树
	int mid = (ss + se) / 2;
	return getSumUtil(st,ss,mid,qs,qe,si*2+1) + 
		   getSumUtil(st,mid+1,se,qs,qe,si*2+2);
}

/**
 *sum
 */ 
int getSum(int *st,int n,int qs,int qe){
	if(qs<0 || qe>=n || qs>qe){
		printf("Invaalid Input");
		return -1;
	}
	return getSumUtil(st,0,n-1,qs,qe,0);
}



int main()
{
	int arr[] = {1,3,5,7,9,11};
	int n = sizeof(arr) / sizeof(arr[0]);

	int *st = createSegmentTree(arr,n);
	
	printf("Sum of values in given range = %d \n", getSum(st,n,1,3));

	// 更新区间
	updateRange(arr,st,n,1,5,10);

	printf("Updated sum of values in given range = %d \n", getSum(st,n,1,3));	

	return 0;
}


