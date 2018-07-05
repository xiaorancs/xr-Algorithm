/*****************************************
 * Author: xiaoran
 * Time: 2018-07-04
 *
 * queue data structure
 *
 ****************************************/

#ifndef ALGO_QUEUE_H_
#define ALGO_QUEUE_H_

#include <string.h>
#include <stdint.h>
#include <exception>
#include <stdbool.h>
#include <assert.h>

namespace alg {
    template<class T,uint32_t xsize=2048>
    class Queue {
        private:
            uint32_t x_capacity; // queue capacity
            uint32_t x_size;     // queue size
            uint32_t x_front;    // index of the first element
            uint32_t x_back;     // index of the last element
            T * x_elements;      // the elements


        public:
            Queue() {
                this->x_elements = new T[xsize];
                this->x_size = 0;
                this->x_capacity = xsize;
                this->x_front = 0;
                this->x_back = -1;
            }

            ~Queue() {
                delete [] x_elements;
            }

        private:
            Queue(const Queue &);
            Queue& operator=(const Queue &);
        public:
            /*
             * front
             */
            inline const T& front() const {
                assert(x_size!=0);
                return x_elements[x_front];
            } 
            /*
             * back
             */
            inline const T& back() const {
                assert(x_size!=0);
                return x_elements[x_back];
            } 

            /*
             * pop
             */
            inline void pop() {
                assert(x_size!=0);
                ++ x_front;
                -- x_size;
            } 



            /*
             * is empty
             */
            inline bool empty() const {
                if(x_size == 0) return true;
                return false;
            }

            /*
             *size
             */
            inline uint32_t size() const {
                return x_size;
            }   

            /*
             *
             */
            inline void push(T element) {
                if(x_size == x_capacity){
                    return;
                }
                else{
                    x_size ++;
                    x_back ++;
                    // 循环数组
                    if(x_back == x_capacity) {
                        x_back = 0;
                    }
                    x_elements[x_back] = element;
                }
            }

            inline void clear(){
                this->x_size = 0;
                this->x_capacity = xsize;
                this->x_front = 0;
                this->x_back = -1;
            }

            inline uint32_t capacity() const { return x_capacity; }
    };
} // alg end

#endif