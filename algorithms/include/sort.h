/*****************************************
 * Author: xiaoran
 * Time: 2018-07-09
 *
 * bubble sort
 * insertion sort
 * selection sort
 * shell sort
 * quickly sort
 * merge sort
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


    /**
     * sort_util()
     */ 
    template<class T>
    int Poivt(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        int t = randint(start, end);
        swap(list[t],list[start]);
        int p,i,j;
        i = start+1;
        j = end;
        p = start;
        while(1) {
            while(i<end && cmp(list[i],list[p])) ++i;
            while(j>start && !cmp(list[j],list[p])) --j;
            if(j<=i) break;
            else{
                swap(list[i],list[j]);
                ++i;
                --j;
            }
        }
        swap(list[j],list[p]);
        return j;
    }

    /**
     * quickly sort
     * 
     */ 
    template<class T>
    void QuickSort(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        if(start>=end) return;
        int p = Poivt(list,start,end,cmp);
        QuickSort(list,start,p-1,cmp);
        QuickSort(list,p+1,end,cmp);
    }

    /*
     * Merge list[start, mid] and list[mid+1, end]
     */ 
    template<class T>
    void Merge(T list[], int start, int mid, int end, bool (*cmp)(T, T)=cmp) {
        T *temp = new T[end-start+1];
        int i=start,j=mid+1,k=0;
        while(i<=mid && j<=end) {
            if(cmp(list[i],list[j])) temp[k++] = list[i++];
            else temp[k++] = list[j++];
        }
        while(i<=mid) {
            temp[k++] = list[i++];
        }
        while(j<=end) {
            temp[k++] = list[j++];
        }
        // copy 
        for(i=start;i<=end;i++){
            list[i] = temp[i-start];
        }
        delete [] temp;
    }
    
    /**
     * MergeSortUtil
     */ 
    template<class T>
    void MergeSortUtil(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        if(start>=end) return;
        int mid = (start+end) / 2;
        MergeSortUtil(list,start,mid,cmp);
        MergeSortUtil(list,mid+1,end,cmp);
        
        Merge(list,start,mid,end,cmp);
    }
    /**
     * MergeSort
     */ 
    template<class T>
    void MergeSort(T list[], int start,int end, bool (*cmp)(T, T)=cmp) {
        MergeSortUtil(list,start,end-1,cmp);
    }



}



#endif