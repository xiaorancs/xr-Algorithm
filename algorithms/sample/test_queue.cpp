/**
 *Author: xiaoran
 *Time: 2018-07-05
 *
 *test queue 
 */

#include <stdio.h>
#include <iostream>
#include "../include/queue.h"

using namespace std;

int main()
{
    alg::Queue<int> queue;
    queue.push(4);
    queue.push(5);
    queue.push(6);

    cout<<"front = "<<queue.front()<<endl;
    cout<<"back = "<<queue.back()<<endl;
    cout<<"size = "<<queue.size()<<endl;
    cout<<queue.empty()<<endl;

    queue.pop();
    cout<<"front = "<<queue.front()<<endl;
    cout<<"size = "<<queue.size()<<endl;

    return 0;
}