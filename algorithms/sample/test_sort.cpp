/**
 * Author: xiaoran
 * Time: 2018-07-09
 * test sort
 */

#include <iostream>
#include "../include/sort.h"
#include "../include/shuffle.h"

using namespace std;

bool cmp(int a,int b) {
    return a > b;
}

int main()
{   
    // bubble sort
    int a[5] = {3,2,1,4,3};
    alg::BubbleSort(a,0,4);
    cout<<"BubbleSort ..." <<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    // shuffle a
    cout<<"shuffle a ..."<<endl;
    alg::shuffle(a, 5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // insertion sort
    cout<<"InsertionSort ..."<<endl;
    alg::InsertionSort(a,0,4, cmp);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    // shuffle a
    cout<<"shuffle a ..."<<endl;
    alg::shuffle(a, 5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // insertion sort
    cout<<"InsertionSort ..."<<endl;
    alg::SelectionSort(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    // shuffle a
    cout<<"shuffle a ..."<<endl;
    alg::shuffle(a, 5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // insertion sort
    cout<<"shellSort ..."<<endl;
    alg::ShellSort(a,0,4,cmp);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // shuffle a
    cout<<"shuffle a ..."<<endl;
    alg::shuffle(a, 5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // quickly sort
    cout<<"quickSort ..."<<endl;
    alg::QuickSort(a,0,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // shuffle a
    cout<<"shuffle a ..."<<endl;
    alg::shuffle(a, 5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // quickly sort
    cout<<"MergeSort ..."<<endl;
    alg::MergeSort(a,0,5,cmp);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}