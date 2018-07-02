/*****************************************
 * Author: xiaoran
 * Time: 2018-07-02
 * Algorithm implementations
 * Shuffle list o(n) time.
 * Reference:
 *  http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 *
 ****************************************/

#ifndef ALGO_SHUFFLE_H_
#define ALGO_SHUFFLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

namespace alg {
    /**
     * shuffle the list of length len
     */ 

    template<typename T>
    static void shuffle(T* list, int len) {
        srand(time(NULL));
        int j;
        T temp;

        if(len==0) return;

        for(int i=0;i<len;i++){
            j = rand() % (i+1);
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }

    template<class Iterator>
    static void shuffle(Iterator first, Iterator last) {
        if(first >= last || first+1 == last) 
            return;
        int i = 0, len = last-first;
        
        for(Iterator it=first; it!=last;++it){
            int j = rand() % (i+1);
            Iterator temp = it;
            *it = *(it+j);
            *(it+j) = *temp;
        }
    }

} // alg end.

#endif
