#include <vector>
#include <string>
#include <iostream>

#include "shuffle.h"

using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5};
    vector<int> b(a,a+5);
    string s = "qwer";

    alg::shuffle(a,5);
    cout<<"Test shuffle array a and length :"<<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    cout<<"Test shuffle STL with iterator :"<<endl;
    alg::shuffle(b.begin(),b.end());
    alg::shuffle(s.begin(),s.end());
    alg::shuffle(a,a+5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it;
    for(it=b.begin();it!=b.end();++it){
        cout<< *it <<" ";
    }
    cout<<endl;
    cout<<s<<endl;

    return 0;
}