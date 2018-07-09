/*****************************************
 * Author: xiaoran
 * Time: 2018-07-09
 *
 * bubble sort
 * insertion sort
 *
 ****************************************/

#ifndef ALGO_BUBBLE_SORT_H_
#define ALGO_BUBBLE_SORT_H_


#include <assert.h>
#include "xmath.h"

namespace alg {
    
    template<class T>
    static bool cmp(const T a, const T b) {
        return a < b;
    }

    /**
     * bubble sort , default ascend true
     */ 
    template<class T>
    static void BubbleSort(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        assert(start < end);
        bool swapped = true;

        bool flag;
        while(swapped){
            swapped = false;
            for(int i=start+1;i<=end;i++){
                flag = cmp(list[i], list[i-1]);  
                if(flag) {
                    swap(list[i-1], list[i]);
                    swapped = true;
                }
            }
        }
    }

    /**
     * insertion sort
     */ 
    template<class T>
    void InsertionSort(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        assert(start <= end);
        for(int i=start+1;i<=end;i++){
            T key = list[i];
            int j = i - 1;
            while(j>=start && cmp(key, list[j])){
                list[j+1] = list[j];
                j --;
            }
            list[j+1] = key;
        }
    }
    /**
     * selection sort
     */ 
    template<class T>
    void SelectionSort(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        assert(start <= end);
        int index;
        for(int i=start;i<end;i++){
            index = i;
            for(int j=i+1;j<=end;j++){
                if(cmp(list[j], list[index])){
                    index = j;
                }
            }
            if(index != i) {
                swap(list[i], list[index]);
            }
        }
    }

    /**
     * shell sort
     */ 
    template<class T>
    void ShellSort(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        int h = 1;
        int len = end - start + 1;
        while(h < len - 1) {
            h = 3 * h + 1;
        }
        while(h >= 1) {
            for(int i=h;i<len;i++){
                int cur = list[i];
                int j = i - h;
                while(j >= start && cmp(cur, list[j])) {
                    list[j+h] = list[j];
                    j -= h;
                }
                list[j+h] = cur;
            }
            h /= 3;
        }


    }
}



#endif