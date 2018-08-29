/**
 * Author: xiaoran
 * Time: 2018-08-29 20:11
 * Demo: Test skip lsit
 */ 

#include <stdio.h>
#include <time.h>
#include "../include/skiplist.h"

using namespace alg;

int main()
{
    SkipList<int, int> ss;
    const int MAX_ELEMENTS = 20;
    int i = 0;
    srand(time(NULL));
    int a[] = {1,2,3,4,5,6,7,7,8,9};

    for(i = 0; i < 10; i++){
        ss.insert(i, a[i]);
    }
    printf("The skip list: \n");
    ss.print();

    printf("Delete key: 6 \n");
    ss.delete_key(6);
    printf("The skip list: \n");
    ss.print();

    return 0;
}