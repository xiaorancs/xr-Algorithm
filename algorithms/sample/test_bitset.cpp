/**
 *Author: xiaoran
 *Time: 2018-07-04
 */

#include <stdio.h>
#include <string>
#include <iostream>

#include "../include/bitset.h"

using namespace std;

int main()
{

    alg::BitSet bitset(20);

    bitset.set(10);
    cout<<bitset.to_string()<<endl;

    bitset.set(13);
    cout<<bitset.to_string()<<endl;


    bitset.unset(10);
    cout<<bitset.to_string()<<endl;

    cout<<bitset.test(10)<<endl;
    cout<<bitset.test(13)<<endl;

    cout<<bitset.any()<<endl;
    cout<<bitset.none()<<endl;

    bitset.set(3);
    bitset.set(4);
    cout<<bitset.size()<<endl;
    cout<<bitset.count()<<endl;

    return 0;
}