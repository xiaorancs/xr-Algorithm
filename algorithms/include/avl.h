/*****************************************
 * Author: xiaoran
 * Time: 2018-07-03
 * Algorithm implementations
 * AVL Tree, 是一个自平衡的二叉搜索树，保证任意的节点的左右子树的高度只差的绝对值小于等于1.
 * 因此AVL树的时间复杂度一定是o(logn)
 * 对于AVL树的插入来看，有四种操作来维护avl树的性质。
 * Let the newly inserted node be w
 * 1). 在平衡的BST中插入W,找到W的位置进行插入
 * 2). 从W的位置向上进行回溯，知道发现第一个不满足平衡要求的点Z，y是W和Z的路径上的Z的孩子节点，
 *     X是W到Z的路径上Z的孙子节点。
 * 3). 为了使节点Z的子树保持平衡，这儿有四种可能的情况:
 *   a) y is left child of z and x is left child of y (Left Left Case)
 *   b) y is left child of z and x is right child of y (Left Right Case)
 *   c) y is right child of z and x is right child of y (Right Right Case)
 *   d) y is right child of z and x is left chidl of y (Right Left Case)
 * 
 * a) Left Left Case
 * T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
 * b) Left Right Case
 *   z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
 *
 * c) Right Right Case
  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4

 * d) Right Left Case
   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
 *
 ****************************************/

#ifndef ALGO_AVL_H__
#define ALGO_AVL_H__

#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
#include <string>

namespace alg {
template <typename T>
class AVL {
    public:
        

};

}















