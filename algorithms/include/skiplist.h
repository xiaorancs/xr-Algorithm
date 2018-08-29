/*****************************************
 * Author: xiaoran
 * Time: 2018-07-04
 *
 * skiplist data structure
 * Reference:
 *  https://www.geeksforgeeks.org/skip-list-set-2-insertion/
 *  https://en.wikipedia.org/wiki/Skip_list
 *  
 ****************************************/

#ifndef ALGO_SKIPLIST_H_
#define ALGO_SKIPLIST_H_
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <exception>

namespace alg {
    template<typename KeyT, typename ValueT,int SL_MAX_LEVEL=6>
    class SkipList {
    private:
        struct SkipNode {
            KeyT key;
            ValueT value;
            SkipNode ** forward; // pointers to different levels
        };
        struct SkipNode * x_header; 
        int x_level; // the max level of skip list
        // struct const int SL_MAX_LEVEL = 6;

    public:
        SkipList() {
            x_header = create_node(SL_MAX_LEVEL, 0, 0);
            x_level = 0;
        }
        ~SkipList() {
            
        }
    private:
        SkipList(const SkipList &);
        SkipList& operator=(const SkipList &);
    
    public:
        /**
         * insert key->value pair into the list
         * 
         */
        void insert(KeyT key, ValueT value) {
            struct SkipNode * p = x_header;
            struct SkipNode * update[SL_MAX_LEVEL + 1]; // different Node with different levels
            memset(update, 0, SL_MAX_LEVEL + 1);

            // travels down the list until we found a proper node
            for(int i = x_level; i >= 0; i--) {
                while(p->forward[i] != NULL && p->forward[i]->key < key) {
                    p = p->forward[i];
                }
                update[i] = p;
            }
            p = p->forward[0];
             /* if current is NULL that means we have reached
                to end of the level or current's key is not equal
                to key to insert that means we have to insert
                node between update[0] and current node */
            if(p == NULL || p->key != key) {
                // Generate a random level for node
                int level = random_level();

                if(level > x_level) {
                    for(int i = x_level + 1; i <= level; i++) {
                        update[i] = x_header;
                    }
                    x_level = level;
                }
                p = create_node(level, key, value);
                
                // for each node travling down, relink into the skiplist
                // insert node by rearranging pointers
                for(int i = 0; i <= level; i++) {
                    p->forward[i] = update[i]->forward[i];
                    update[i]->forward[i] = p;
                }
            }
        }

        /**
         * delete a node by it's key
         * 
         */ 
        void delete_key(KeyT key) {
            struct SkipNode* x = x_header;
            struct SkipNode* update[SL_MAX_LEVEL + 1];
            memset(update, 0, SL_MAX_LEVEL + 1);

            // find the node, and record it's level update info
            for(int i = x_level; i >= 0; i--) {
                while(x->forward[i] != NULL && x->forward[i]->key < key) {
                    x = x->forward[i];
                }
                update[i] = x;
            }
            x = x->forward[0];
            // delete every level's key
            if(x != NULL && x->key == key) {
                for(int i = 0;i <= x_level; i++) {
                    if(update[i]->forward[i] != x) break;
                    update[i]->forward[i] = x->forward[i];
                }
                free(x);

                while(x_level > 0 && x_header->forward[x_level] == NULL) {
                    x_level --;
                }
            }
        }

        void print() {
            for(int i = x_level-1; i >= 0; i--) {
                SkipNode* x = x_header->forward[i];
                printf("{");
                while(x != NULL) {
                    printf("%d->%d", x->key, x->value);
                    x = x->forward[i];
                    if(x != NULL) {
                        printf(", ");
                    }
                }
                printf("}\n");
            }
        }

    private:
        /**
         * generate a value in [0.0, 1.0]
         */
        inline float rand_norm() {return (float) rand() / INT_MAX; }
        /**
         * get the random level
         */ 
        int random_level(double threshold = 0.5) {
            int level = 0;
            while(rand_norm() < threshold && level < SL_MAX_LEVEL) level ++;

            return level;
        }

        /**
         * create a node with specified level & key  
         */
        SkipNode * create_node(int level, KeyT key, ValueT value) {
            SkipNode * temp = new SkipNode;
            temp->forward = new struct SkipNode* [level + 1];
            temp->key = key;
            temp->value = value;

            return temp;
        }

    };
}

#endif