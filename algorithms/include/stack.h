/*****************************************
 * Author: xiaoran
 * Time: 2018-07-06
 *
 * stack data structure
 *
 ****************************************/

#ifndef ALGO_STACK_H_
#define ALGO_STACK_H_


#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

namespace alg {
    template<class T, uint32_t xsize=1024>
    class Stack {
        private:
            uint32_t x_capacity;    // the total capacity
            uint32_t x_size;        // current stack size
            T* x_elements;          // the elements

        public:
            Stack(uint32_t capacity = xsize) {
                this->x_capacity = capacity;
                this->x_size = 0;
                this->x_elements = new T[capacity];
            }

            ~Stack() {
                delete [] x_elements;
            }

        private:
            Stack(const Stack&);
            Stack& operator=(const Stack&);

        public:
            inline bool empty() const {return x_size==0 ? true:false; }

            /**
             * pop stack 
             */ 
            inline void pop() {
                if(x_size!=0) x_size--;
                return;
            }

            /*
             * top
             */ 
            inline const T& top() const {
                assert(x_size > 0);
                return x_elements[x_size-1];
            }

            /*
             * push T element to stack
             */
            inline void push(const T& value) {
                assert(x_size<x_capacity);
                x_elements[x_size++] = value;
            }

            /*
             * size
             */
            inline uint32_t size() {
                return x_size;
            }

            /**
             * return value by index
             */ 
            inline const T& operator[] (uint32_t idx) const {
                assert(idx < x_size);
                return x_elements[x_size-idx-1];
            }

    };


} // alg end

#endif
