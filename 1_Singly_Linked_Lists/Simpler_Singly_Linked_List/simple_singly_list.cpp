// This file implements a basic singly linked list 

#include "interface.h"

using namespace std;

int main(){
    // create a new linked list
    LinkedList ll;

    // Inert a few node, alternating at head and tail
    for(int i = 0; i < 5; i++) {
        // Insert at tail on even numbers
        ll.add_node(i * i);
    }

    for(int i = 0; i < 5; i++) {
        // Insert at tail on even numbers
        ll.delete_node();
    }
    return 0;
}
