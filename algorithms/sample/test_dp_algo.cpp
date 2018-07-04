/**
 *test dp_algo
 */

#include <stdio.h>
#include <string.h>

#include "../include/dp_algo.h"

int main()
{
    int a[5] = {1,-2,3,-2,5};
    int b[5] = {1,4,3,-2,6};
    int lena = 5, lenb = 5;
    int sum,len, begin,end;

    alg::max_subarray(a,lena,begin, end,sum);
    printf("a max_subarray, [%d,%d) sum = %d\n",begin,end,sum);

    alg::lcs(a,lena,b,lenb,len);
    printf("lcs(a,b) = %d\n", len);

    alg::lis(a,lena,len);
    printf("lis(a) = %d\n", len);


    return 0;
}