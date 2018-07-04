/*****************************************
 * Author: xiaoran
 * Time: 2018-07-04
 *
 * bit-set data structure
 *
 ****************************************/

#ifndef ALGO_BIT_SET_H_
#define ALGO_BIT_SET_H_

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <string>

namespace alg {

    /*
     * definition of bitset class
     */
    class BitSet {
        private:
            uint32_t m_size; // size in bits
            uint32_t m_bytes; // size in bytes
            unsigned char * m_bits; // the bits
        public:
            BitSet(uint32_t num_bits){
                m_bytes = (num_bits + 7) / 8;
                m_size = m_bytes * 8;
                m_bits = new unsigned char[m_bytes]; // number of bit 
                memset(m_bits, 0, m_bytes);
            }

            ~BitSet(){
                delete [] m_bits;
            }
        private:
            BitSet(const BitSet&);
            BitSet& operator=(const BitSet&);
        public:
            /*
             * set 1 to position p[bit]
             * bitset[bit] = 1;
             * 1 size = 8 bytes
             */
            inline void set(uint32_t bit){
                assert(bit < m_size);
                if(bit >= m_size) return;
                uint32_t n = bit / 8;
                uint32_t off = bit % 8;

                m_bits[n] |= 128U>>off;

            }
            /*
             * set 0 to position [bit]
             */
            inline void unset(uint32_t bit){
                assert(bit < m_size);
                if(bit >= m_size) return;
                uint32_t n = bit / 8;
                uint32_t off = bit % 8;

                m_bits[n] &= ~(128U>>off);
            }
            /**
             * test(bit) 1 if set, else false
             */
            inline bool test(uint32_t bit){
                assert(bit < m_size);
                uint32_t n = bit / 8;
                uint32_t off = bit % 8;

                if(m_bits[n] & (128U>>off)) return true;
                return false;
            }

            /*
             * get [bit]
             */
            inline char operator [] (uint32_t bit) {
                assert(bit < m_size);
                uint32_t n = bit / 8;
                uint32_t off = bit % 8;
                if(m_bits[n] & (128U>>off)) {
                    return '1';
                }
                else return '0';
            }

            inline char operator [] (uint32_t bit) const {
                assert(bit < m_size);
                uint32_t n = bit / 8;
                uint32_t off = bit % 8;
                if(m_bits[n] & (128U>>off)) {
                    return '1';
                }
                else return '0';
            }

            /*
             * get (bit) --> char
             */ 
            inline char get(uint32_t bit) {
                assert(bit < m_size);
                uint32_t n = bit / 8;
                uint32_t off = bit % 8;
                if(m_bits[n] & (128U>>off)) {
                    return '1';
                }
                else return '0';
            }
            
            /*
             * any one position is 1, return true, else return false
             */
            inline bool any(){
                for(int i=0;i<m_size;i++){
                    uint32_t n = i / 8;
                    uint32_t off = i % 8;
                    if(m_bits[n] & (128U>>off)) return true;
                }         
                return false;
            }

            /*
             * none position is 1, return true, else return false
             */
            inline bool none(){
                for(int i=0;i<m_size;i++){
                    uint32_t n = i / 8;
                    uint32_t off = i % 8;
                    if(m_bits[n] & (128U>>off)) return false;
                }         
                return true;
            }

            /*
             * size of bitset
             */
            inline uint32_t size() {
                return m_size;
            }

            /*
             * count (1)
             */
            inline uint32_t count() {
                int sum = 0;
                for(int i=0;i<m_size;i++){
                    uint32_t n = i / 8;
                    uint32_t off = i % 8;
                    if(m_bits[n] & (128U>>off)) sum += 1;
                }
                return sum;
            }

            /**
             * to_string: return string of BitSet
             */
            inline std::string to_string(){
                std::string s = "";
                for(int i=0;i<m_size;i++){
                    s += get(i);    
                }
                return s;
            } 

    };

}

#endif