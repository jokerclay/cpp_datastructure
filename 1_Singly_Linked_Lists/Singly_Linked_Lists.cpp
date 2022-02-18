// This program implements a basic single linked list in c++

#include "interface.h"

using namespace std;

int main(){
    // create  a new linked list
    LinkedList ll;

    // Insert a few nodes, alternating at head and tail 
    for (int i = 0; i < 5 ; i++){
        if(i % 2 ){
            // insert at head on odd number 
            ll.insert_head(i);
        }else{
            // insert at tail on even number
            ll.insert_tail(i);
        }
    }



    // insert at the beginning of the list
    ll.insert_position(5,2);

    // Delete the element we just put in
    ll.delete_position(2);

    // Delete the head
    ll.delete_head();

    // Delete the tail
    ll.delete_tail();

    return 0;
}
