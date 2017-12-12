/**
 * Author : xiaoran 
 * Time: 2017-11-04 14:40
 * Title：基于单链表的快速排序
 * Language： C++
 * Detail:
 * 这里的快速排序是基于指针的变换，而不是对数据进行修改
 * step 1: 
 *  Partition(),使用最后一个指针作为pivot，
 * step 2：
 *  每次的划分的过程中，遍历整个链表，对于大于这个指针的元素current，将其移动到pivot之火。
 *  else 节点的位置不动，继续向后移动
 * step 3：
 *  1. pivot = Partition()
 *  2. 根据pivot得到左右两个部分，left和right
 *  3. 对left和right进行快速排序
 * 主要事项：
 *  划分时修改了链表的结构，需要重新连接链表，leftHead->pivot->rightHead
 */

#include<stdio.h>
#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};

/**
 * 头插法建立链表
 */
void push(struct Node ** head_ref, int new_data){
    //分配新的节点
    struct Node * new_node = new Node;

    new_node->data = new_data;
    // 指向链表的头节点
    new_node->next = *head_ref;

    //更新头节点
    *head_ref = new_node;
}

void printList(struct Node *node){
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

/**
 * 返回list的最后一个节点
 */
struct Node * getTail(struct Node *node){
    while(node !=NULL && node->next != NULL){
        node = node->next;
    }
    return node;
}


/**
 * 一次划分函数
 */
struct Node *partiton(struct Node *head,struct Node *end,struct Node **newHead,struct Node **newEnd)
{
    struct Node *pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
    // 在划分期间，list的头和尾可能发生改变

    while(cur != pivot){
        if(cur->data < pivot->data){
            if((*newHead) == NULL){
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else{
            if(prev){
                // 将当前节点cur移动到tail（pivot）之后
                prev->next = cur->next;
            }
            struct Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if((*newHead) == NULL){
        (*newHead) = pivot;
    }
    (*newEnd) = tail;

    return pivot;

}

/**
 * 快速排序
 * 
 */
struct Node * quickSortRecur(struct Node * head, struct Node *end){
    if(!head || head == end){
        return head;
    }

    Node *newHead = NULL, *newEnd = NULL;

    struct Node *pivot = partiton(head,end,&newHead,&newEnd);

    if(newHead != pivot){
        struct Node * tmp = newHead;
        while(tmp->next != pivot){
            tmp = tmp->next;
        }
        tmp->next = NULL;

        newHead = quickSortRecur(newHead,tmp);
        
        tmp = getTail(newHead);

        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next,newEnd);

    return newHead;
}

void quickSort(struct Node ** headRef){
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));

    return;
}


int main()
{
    struct Node *a = NULL;
    push(&a,5);
    push(&a,20);
    push(&a,4);
    push(&a,3);
    push(&a,30);
    
    cout<<"Linked list before sorting \n";
    printList(a);
    quickSort(&a);

    cout<<"Linked list after sorting \n";
    printList(a);
    
    return 0;
}