/*****************************************
 * Author: xiaoran
 * Time: 2018-07-06
 *
 * heap data structure
 *
 ****************************************/
#ifndef ALGO_HEAP_H_
#define ALGO_HEAP_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "xmath.h"

namespace alg {

    template<class T, uint32_t xsize=1024>
    class Heap {
        public:
            struct elem {
                public: // 设置堆的元素的值，key表示堆的比较的值
                    int key;
                    T data;
                elem(int _key,T _data):key(key),data(_data) {}
            };
        private:
            int x_size;     // current heap szie
            int x_capacity; // total heap size
            elem * x_elements; // key value struct 

        public:
            Heap(int size=xsize) {
                x_size = 0;
                x_capacity = size;
                x_elements = new elem[size];
            }

            ~Heap() {
                delete [] x_elements;
            }
        
        private:
            Heap(const Heap &);
            Heap& operator=(const Heap&);
        public:
            // heap size
            inline int size() const {return x_size; }

            /**
             * push(key, value) into heap 
             */ 
            void push(int key, const T & data) {
                if(x_size == x_capacity) return;

                // put in the back, and try move upward the heap
                x_elements[x_size].key = key;
                x_elements[x_size].data = data;
                up(x_size); // update this index
                x_size ++;
            }


            /**
             * empty 
             */ 
            inline bool empty() cosnt { return x_size==0? true: false;}

            // clear
            inline void clear() { x_size = 0;}

            // pop 优先级最高的一个
            elem pop() {
                int n = x_size - 1;
                swap(x_elements[0], x_elements[n]);
                down(0, n);
                x_size --;
                return x_elements[x_size];
            }

            // top
            elem top() {
                return x_elements[x_size-1];
            }
            
            // remove the given data
            bool remove(const T & data) {
                for(int i=0;i<x_size;i++) {
                    if(x_elements[i].data == data) { // find
                        int n = x_size - 1;
                        if(n != i) { // i不是最后一个
                            swap(x_elements[i], x_elements[n]);
                            down(i, x_size); // 保证i的位置的堆的性质
                            up(i); 
                        }
                        x_size --;
                        return true;
                    }
                }
                return false;
            }

            /*
             * decrease key
             * 
             */
            void decrease_key(const T &data, int newkey) {
                if(remove(data)) {
                    push(newkey, data);
                }
            }


            /*
             * compare (the element, parent)
             * cmp
             */
            void up(int j) {
                while(1) {
                    int i = j / 2; // index start from 0
                    if(i==j || !cmp(j,i)) { // define less function
                        break;
                    }
                    swap(x_capacity[j], x_capacity[i]);
                    j = i;
                }
            }

            /*
             * current index j, and size of the heap: n 
             */
            void down(int i,int n) {
                while(1) {
                    int left = i * 2;
                    int right = i*2 + 1;

                    if(left >= n || left < 0) break;
                    int j = left;
                    if(right < n && !cmp(left, right)){
                        j = right;
                    }
                    if(!cmp(j,i)) {
                        break;
                    }
                    swap(x_elements[i], x_elements[j]);
                    i = j;
                }
            }


            bool cmp(int j, int i){
                return x_elements[j].key < x_elements[i].key;
            }

    };

} // alg end

#endif