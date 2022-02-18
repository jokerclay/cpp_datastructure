// This file implements the methods of 'LinkedList'  class

#include "interface.h"

using namespace std;

// Append new node to the end of the list  
void LinkedList::add_node(int d) {

    // create new node with value 'd' 
    Node *new_node = new Node(d);

    // create temp for walking the list
    Node *temp = head;

    // Handle case of empty list otherwish perform normal insertion
    if (temp == NULL) {
        head = new_node;
    } else{
        // walk the list until the next node is NULL
        while(temp->next != NULL) {
            temp = temp->next;
        }
        // Assign previous tail's 'next' to our  new node  
        temp->next = new_node;
    }
    cout << "Added node with data: " << d <<endl;
    print_list();
}

// Delete node at the tail of the list
void LinkedList::delete_node() {
    // check if the list is empty
    assert(head != NULL);

    // walk the list and save the previous and current node 
    Node *temp = head;
    Node *prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Handle case where is only 1 list item otherwish normal delete    
    if(prev == NULL) {
        head = NULL;  
    }else{
        prev->next = temp->next;
    }
    delete temp;

    cout << "Delete node " <<  endl;
    print_list();
}

// Print out the  list
void LinkedList::print_list() {
    for (int i = 0; i < 72; i++) {
        cout << "-";
    }
    cout << endl;

    Node *temp = head;
    cout << "List\t";
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






















