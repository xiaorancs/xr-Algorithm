/**
 *Author: xiaoran
 *Time: ...
 *Problem:
 *	二叉树的一些操作.
 *
 *
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
using namespace std;
struct node{
    int key;//关键字
    //string s;//卫星数据

    struct node *left;//左子树
    struct node *right;//右子树
    struct node *parent;//父亲节点
    node(int kk = 0){
        key = kk;
        left = right = parent = NULL;
    }
};
typedef node * Node;

class SearchTree{
private:
    Node root;//树根节点
public:
    void treeInit(){
        root = NULL;
    }
    Node getRoot(){
        return root;
    }

    void inorderTreeWalk(Node p);//中序遍历二叉查找树
    Node treeSearch(Node p,int key);//查找节点k
    Node iteratorTreeSearch(int key);
    Node treeMinimum(Node p);
    Node treeMaximum(Node p);
    Node treePredecessor(Node x);
    Node treeSuccessor(Node x);
    void treeInsert(int key);
    void treeDelete(Node z);

};
void SearchTree::inorderTreeWalk(Node p){//中序遍历二叉查找树
    if(p!=NULL){
        inorderTreeWalk(p->left);
        cout<<p->key<<endl;
        //getchar();
        inorderTreeWalk(p->right);
    }
}
//算法的正确性可以用数学归纳法证明，时间O(n)

Node SearchTree::treeSearch(Node p,int key){//查找节点k
    if(p == NULL || key == p->key) return p;
    if(key < p->key) return treeSearch(p->left,key);
    else return treeSearch(p->right,key);
}

//迭代版本
Node SearchTree::iteratorTreeSearch(int key){//查找节点k
    Node p = root;
    while(p != NULL && key != p->key){
        if(key < p->key) p = p->left;
        else p = p->right;
    }
    return p;
}

/**
 *最大值和zuixiaoz
 *最大值：right->right->...->max
 *最小值：left->left->...->min
 */

Node SearchTree::treeMinimum(Node p){
    while(p->left!=NULL){
        p = p->left;
    }
    return p;
}
Node SearchTree::treeMaximum(Node p){
    while(p->right!=NULL){
        p = p->right;
    }
    return p;
}

//得到前驱
Node SearchTree::treePredecessor(Node x){
    if(x == NULL) return NULL;

    Node y;
    if(x->left!=NULL){//左子树不为空，返回左子树的最大值
        return treeMaximum(x->left);
    }
    else{//但是x还有前驱，
        y = x->parent;
        while(y != NULL && x == y->left){//不满足条件，继续向上找
            x = y;
            y = y->parent;
        }
    }
    return y;
}

//得到后继
Node SearchTree::treeSuccessor(Node x){
    if(x == NULL) return NULL;

    Node y;
    if(x->right!=NULL){//右子树不为空，返回左子树的最小值
        return treeMinimum(x->right);
    }
    else{//但是x还有后继，
        y = x->parent;
        while(y != NULL && x == y->right){//不满足条件，继续向上找
            x = y;
            y = y->parent;
        }
    }
    return y;
}

//插入节点
void SearchTree::treeInsert(int key){//树T中插入Z
    Node z = new node(key);

    Node y = NULL;
    Node x = root;
    while(x != NULL){
        y = x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    //y是x的父节点，x是z的最佳位置
    z->parent = y;
    if(y == NULL){//T是个空树
        root = z;
    }
    else{
        if(z->key < y->key) y->left = z;
        else y->right = z;
    }
}

/**
 *删除节点，有三种情况
 *1、z没有子女节点，直接删除
 *2、z只有一个子节点，用子节点代替z，删除子节点
 *3、z有两个子女，先删除z的后继，用z后继的内容代替z
 */

void SearchTree::treeDelete(Node z){
    if(z == NULL) return ;
    Node y;
    if(z->left == NULL && z->right == NULL){//z是叶子节点，直接删除，并且修改其父节点的指针
        if(z->parent->left == z) z->parent->left = NULL;
        else z->parent->right = NULL;
        delete z;
        return;
    }
    else y = treeSuccessor(z);//用y的内容替代z的key，并且递归删除y
    z->key = y->key;

    treeDelete(y);
    //delete y;
}


int main()
{
    SearchTree st;
    st.treeInit();
    int a[] = {2,6,5,8,3,4,7,9};

    for(int i=0;i<8;i++){
        st.treeInsert(a[i]);
    }
    st.inorderTreeWalk(st.getRoot());

    Node p=st.iteratorTreeSearch(5);
    //cout<<p->key<<endl;

    p=st.treeSearch(st.getRoot(),5);
    //cout<<p->key<<endl;

    p=st.treeMaximum(st.getRoot());
    //cout<<p->key<<endl;

    p=st.treeMinimum(st.getRoot());
    //cout<<p->key<<endl;

    p=st.treePredecessor(st.getRoot()->right);
    p=st.treeSuccessor(st.getRoot()->right);
    if(p!=NULL) cout<<p->key<<endl;

    cout<<"------------"<<endl;
    st.treeDelete(st.getRoot()->right);

    st.inorderTreeWalk(st.getRoot());
	return 0;
}
