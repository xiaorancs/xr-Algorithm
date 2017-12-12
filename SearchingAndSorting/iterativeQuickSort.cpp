#include<iostream>
#include<cstdio>
using namespace std;

// 交换函数
void swap(int* a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


// 一次划分函数
int partition(int arr[],int l, int h){
    int x = arr[h];// 最后一个作为划分基准
    int i =l;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<=x){//后面所有的小于基准的值都放到前面
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    //设置基准的最后位置
    swap(&arr[i],&arr[h]);
    return i;//返回基准值的位置
}

void quickSortIterative(int arr[],int l,int h){
    // 使用栈来替代地柜
    int stack[h-l+1];

    // 初始化栈的大小
    int top = -1;

    // 放入l和h的初始值 
    stack[++top] = l;
    stack[++top] = h;

    while(top>=0){
        // 每次pop出h和l
        h = stack[top--];
        l = stack[top--];
        
        // 完成一次划分，得到基准值的下标
        int p = partition(arr, l, h);

        //if 左边还有数据，将左边的数据放入栈中，右边同理
        if(p-1>l){
            stack[++top] = l;
            stack[++top] = p-1;
        }

        if(p+1<h){
            stack[++top] = p+1;
            stack[++top] = h;
        }

    }
}

void printArr(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {4,3,5,2,1,3,2,3};
    int n = sizeof(arr) / sizeof(*arr);
    quickSortIterative(arr,0,n-1);
    printArr(arr,n);

    return 0;
}

