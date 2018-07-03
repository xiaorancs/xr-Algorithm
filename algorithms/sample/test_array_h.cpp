/**
 *Author: xiaoran 
 *Time: 2018-07-03
 *test class Array2D 
 * 
 */ 

#include <iostream>
#include <stdio.h>

#include "../include/array.h"

int main()
{
    alg::Array2D<int> arr(2,3);
    arr.set_value(1);

    std::cout<<arr.row()<<std::endl;
    std::cout<<arr.col()<<std::endl;

    // get index 0 row; print
    int* a = arr[0];
    for(int i=0;i<arr.col();i++){
        std::cout<<a[i]<<" ";
    }

    // update (1,2) value
    std::cout<<std::endl;
    arr[1][2] = 5;
    std::cout<<arr[1][2]<<std::endl;

    // get value of  (row, col)
    arr(1,2);
    // std::cout<<arr(1,2)<<std::endl;

    return 0;
}