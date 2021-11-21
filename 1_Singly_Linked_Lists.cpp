// Singly Linked Lists

#include <iostream>
#include <cstddef>
#include <assert.h>

// Simple node of list
// Contains data, and a pointer to the next node
struct Node{

    int data;
    Node *next;

    // Constructor
    Node(int d){
        data = d;
        next = NULL;
    }

};

class LinkedList{
    private:
        // Pointer to list head
        Node *head;

    public:
        // Constructor initialzing NULL pointers
        LinkedList(){
            head = NULL;
        }

        // Add a node with data 'd' at head poistion
        void insert_head(int d);

        // Add a node with data 'd' at poistion in the list 'p'
        void insert_position(int d,int p);
        
        // Add a node with data 'd' at tail poistion
        void insert_tail(int d);

        // delete a node at head poistion
        void delete_head();

        // delete a node  at poistion in the list 'p'
        void delete_position(int p);
        
        // delete a node at tail poistion
        void delete_tail();

        // print out the list
        void print_list();

}


