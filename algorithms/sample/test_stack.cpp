/**
 *Author: xiaoran
 *Time: 2018-07-05
 *
 *test stack 
 */

#include <stdio.h>
#include <iostream>
#include "../include/stack.h"

using namespace std;

int main()
{
    alg::Stack<char> sta;
    sta.push('4');
    sta.push('5');    
    sta.push('6');

    cout<<"Top: "<<sta.top()<<endl;
    cout<<"Size: "<<sta.size()<<endl;

    sta.pop();
    cout<<"POP --- "<<endl;
    cout<<"Top: "<<sta.top()<<endl;
    cout<<"Size: "<<sta.size()<<endl;
    
    return 0;
}