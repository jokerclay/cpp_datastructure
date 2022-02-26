#include <iostream>
#include <cstddef>
#include <assert.h>

// 数据结构的结构定义
// Simple node of list
// Contains data, and a pointer to the next node
// 链表节点, 包含节点值，节点的指针，用来指向下一个节点
struct Node{

    int data;       // 数据域
    Node *next;     // 指针域

    // Constructor
    // 构造函数，初始化 节点默认值为 d , 指针 next 默认值为 NULL
    Node(int d){
        data = d;
        next = NULL;
    }
};

/**
 *
 * 类 LinkedList
 *
 * */

class LinkedList{
    private:
        // Pointer to list head
        // 私有值: 头部指针
        Node *head;

    public:
        // Constructor initialzing NULL pointers
        // 将 LinkedList 的头部指针初始换 为 NULL
        LinkedList(){
            head = NULL;
        }

        // 成员函数
        // Add a node with data 'd' at head poistion
        // 在头部添加 节点(节点值 为 d ) 方法
        void insert_head(int d);

        // Add a node with data 'd' at poistion in the list 'p'
        // 在链表的 p  位置 插入 值 d
        void insert_position(int d,int p);
        
        // Add a node with data 'd' at tail poistion
        // 在尾部添加 节点(节点值 为 d ) 方法
        void insert_tail(int d);




        // delete a node at head poistion
        // 删除头部节点，无需参数
        void delete_head();

        // delete a node  at poistion in the list 'p'
        // 删除 位置 p 的节点
        void delete_position(int p);
        
        // delete a node at tail poistion
        // 删除尾部节点,无需参数
        void delete_tail();

        // print out the list
        // 打印出链表
        void print_list();

};

