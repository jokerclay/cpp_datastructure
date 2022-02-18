// This file implements the methods of 'LinkedList' class

#include "interface.h"
using namespace  std;

/**
 *
 * Add the node at head 
 * 头部添加节点
 *
 * */
void LinkedList::insert_head(int d){
    // create a new node with data value 'd'
    // 创建一个 节点（节点值为 d ）
    Node *new_head = new Node(d);

    // Insert at the front of the list
    // 将 新节点插入到头部
    // 可以这样想：list 中 没有 node , node.next = null
    // 再将 new_head 更新为 head
    new_head->next = head;
    head = new_head;

    cout << "Head insert with data: " << d << endl;

    print_list();
}

/**
 *
 * Add node at position 'p' in list
 * position 'p' must exit in the list
 * 在 位置 p 处添加节点， p 必须存在 链表中
 *
 * */
void LinkedList::insert_position(int d,int p){

    // create a new node with data value 'd'
    // 创建一个 节点（节点值为 d ）
    Node *new_node = new Node(d);

    // set head = new_head if list is empty and p == 0
    // otherwise perform normal insertion

    if(head == NULL){
        // check if heaed insertion
        // Otherwise it is an invalid operation
        if(p == 0 ){
            new_node = head;
        }else{
            assert(head == NULL && p == 0);
        }
    }else{
        // walk the list to get the entry point for new node
        Node *temp = head;
        Node *prev = NULL;
        for(int i = 0 ; i < p; i++ ){
            // check if insertion is  past potential new tail 
            assert(temp != NULL);
            // update pervious node and current node 
            prev = temp;
            temp = temp->next;
        }
        // check if this is actually head insertion
        // otherwise perform normal insertion
        if(prev == NULL){
            head = new_node;
            head->next = new_node;
        }else{
            new_node->next = prev->next;
            prev->next = new_node;
        }
    }
    cout << "Postion  "<< p << " insert with data: " << d << endl;
    print_list();

}

/**
 *
 * Add new node at tail
 * 在 尾部添加 node 
 *
 * */
void LinkedList::insert_tail(int d){
    // create a new ndoe with the value 'd'
    Node *new_tail = new Node(d);


    // Handle case of empty list
    // otherwise perform normal insertion
    if(head == NULL){
        head = new_tail;
    }else{
        // create temp for walking the list 
        Node *temp = head;
        // walk the list until the next node is NULL
        while (temp->next != NULL){
            temp = temp->next;
        }
        // Assign previous tail's 'next' to be our new ndoe
        temp->next = new_tail;
    }
    cout << "Tail insert with data:  " <<d << endl;
    print_list();
}



/**
 *
 * Delete node at the head of the list
 * 删除头部节点
 *
 * */
void LinkedList::delete_head(){
    // check if list is empty 
    assert(head != NULL);

    // set head-> next as new head and free odd one
    Node *temp = head;
    head = temp->next;
    delete temp;

    cout << "Head delete "  << endl;
    print_list();
}

/**
 *
 * Delete node at position 'p'
 * assume 'p' is a vaild location
 * 删除 p 处的节点, 假设 p 是 有效地址
 *
 * */

void LinkedList::delete_position(int p){
    // check if the list is empty
    assert(head != NULL);

    // walk the list to the position of deletion
    Node *temp = head;
    Node *prev = NULL;
    for (int i = 0; i < p; i++) {
        // check if the deletion point is the end of the list
        assert(temp != NULL);
        prev = temp;
        temp = temp->next;
    }
    // Handle head deletion
    // otherwise normal deletion
    if (prev == NULL) {
        head = temp->next;
    }else {
        prev->next = temp->next;
    }
    delete temp;

    cout << "Postion  delete at " << p << endl;
    print_list();
}


/**
 *
 * Delete node at tail position 
 * 删除尾部节点
 *
 * */

void LinkedList::delete_tail() {
    // check if the list is empty
    assert(head != NULL);

    // walk the list and save the previous and current Node
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // handle case where there is only 1 list item 
    // otherwise normal tail delete
    if (prev == NULL) {
        head = NULL;
    }else{
        prev->next = temp->next;
    }
    delete temp;

    cout << "Tail delete" << endl;
    print_list();

}

/**
 *
 *  Print out the list
 *  打印节点
 *
 * */

void LinkedList::print_list() {
    for (int i = 0; i < 72; i++) {
        cout << "-";
    }
    cout << endl;
    Node *temp = head;
    cout << "List \t";
    while(temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;

    for (int i = 0; i < 72; i++) {
        cout << "-";
    }
    cout << endl;
    cout << endl;
    cout << endl;

}

