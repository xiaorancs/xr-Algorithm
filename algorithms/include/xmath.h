/*****************************************
 * Author: xiaoran
 * Time: 2018-07-04
 *
 ****************************************/

#ifndef XMATH_H_
#define XMATH_H_


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

namespace alg {

    template<class T> const T& max(const T& a, const T& b){
        return (a<b)?b:a;
    }

    template<class T> const T& max(const T& a, const T& b, const T& c){
        T temp = (a<b)?b:a;
        return (temp<c)?c:temp;
    }

    template<class T>
    static inline void swap(T &x, T &y) {
        T tmp = x;
        x = y;
        y = tmp;
    }

} 

#endif