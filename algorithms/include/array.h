/*****************************************
 * Author: xiaoran
 * Time: 2018-07-03
 * Algorithm implementations
 * 2Darray implementations
 *
 ****************************************/
#ifndef ALGO_ARRAY_H_
#define ALGO_ARRAY_H_

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

namespace alg {
    /**
     * 2D Array definition
     */ 
    template <typename T=int>
    class Array2D {
        private:
            uint32_t NR; // number of rows
            uint32_t NC; // number of columns
            T * m_data;  // data

        public:
            /**
             * construct an array of size[nrow, ncol]
             */ 
            Array2D(uint32_t nrow, uint32_t ncol) {
                NR = nrow;
                NC = ncol;
                m_data = new T[nrow*ncol];
            }
            ~Array2D() {
                delete [] m_data;
            }
        private:
            Array2D(const Array2D&);
            Array2D& operator=(const Array2D&);
        
        public:
            inline const uint32_t row() const {return NR; }
            inline const uint32_t col() const {return NC; }
            // inline T& operator() (int row, int col) {return this->m_data[row*NC + col]; }
            // const inline T& operator() (int row, int col) {return this->m_data[row*NC + col]; }

            // get row data
            inline T* operator[] (int row) {
                assert(row < NR);
                return &(m_data[row*NC]); 
            }
            inline T* operator[] (int row) const {
                assert(row < NR);
                return &(m_data[row*NC]); 
            }

            void set_value(const T& value){
                for(uint32_t i=0;i<NC*NR;i++){
                    m_data[i] = value;
                }
            }
    };
} // alg end

#endif 