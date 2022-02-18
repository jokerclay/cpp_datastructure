// This file contains the interface for singly linked list node and list objects

#include <iostream>
#include <cstddef>
#include <assert.h>


// simple node of the list contains data and pointer to the next node
struct Node {
    int data;
    Node *next;

    // constructor
    Node(int d) {
        data = d;
        next = NULL;
    }
};


class LinkedList {
    private:
        // pointer to list head
        Node *head;

    public:
        // constructor initialzing NULL pointers
        LinkedList() {
            head = NULL;
        }

        // Append new node to the end of the list  
        void add_node(int d);


        // Remove node at the end of the list  
        void delete_node();

        // Print out the list 
        void print_list();
};


