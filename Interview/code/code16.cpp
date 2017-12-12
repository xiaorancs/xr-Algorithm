/**
 *Author: xiaoran
 *座右铭：既来之，则安之
 */
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;

const int MAXN = 1000;
char s[MAXN];
int urlify(char s[]){
    
    int len = 0;
    for(len = 0;s[len];len++);
    
    int space_cnt = 0;
    // 计算所有空格的个数
    for(int i=0;i<len;i++){
        if(s[i] == ' ') space_cnt ++;
    }
    //去掉最后空格的情况
    while(s[len-1] == ' '){
        space_cnt --;
        len --;
    }
    // 表示char数组的结尾的'/0'
    int newlen = len + 2 * space_cnt;
    
    if(newlen > MAXN) return -1;
    int index = newlen;
    s[index --] = '\0';
    
    for(int i=len-1;i>=0;i--){
        if(s[i] == ' '){
            s[index--] = '0';
            s[index--] = '2';
            s[index--] = '%';
        }
        else{
            s[index--] = s[i];
        }
    }
    return newlen;
}
int main(){
	int t,len;
    scanf("%d\n",&t);
	while(t--){
	    //这是一个神奇的用法，受教了
        scanf("%[^\n]s", s);
	    scanf("%d\n", &len);
        int newlen = urlify(s);
        for(int i=0;i<newlen;i++){
		    cout<<s[i];
        }
        cout<<endl;
	}
}
