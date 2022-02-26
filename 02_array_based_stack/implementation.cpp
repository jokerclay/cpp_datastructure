#include "interface.h"

using namespace std;


// ----------------------------
// Add a new item to the stack
// ----------------------------
void Stack::push(int d) {
    // Check if the stack is full, if full, exit with failure
    // Otherwise push new item
    if(is_full()) {
        cout << "Error, Stack overflow!" << endl;
        exit(EXIT_FAILURE);
    }else{
        // increase top of stack then store value at new position 
        array[++top_of_stack] = d;
    }
    cout << "======== Push on Stack ========" << endl;
    print_stack();
}

// ------------------------------
// Remove an item from the stack
// ------------------------------
void Stack::pop() {
    // Check if the stack is empty, if empty, exit with failure
    // Otherwise pop off the top of the stack
    if(is_empty()) {
        cout << "Error, Stack underflow!" << endl;
        exit(EXIT_FAILURE);
    }else{
        // increase top of stack then store value at new position 
        array[top_of_stack--] = 0;
    }
    cout << "======== Pop off top of Stack ========" << endl;
    print_stack();
}

// -----------------------------
// look at the top of the stack
// -----------------------------
int Stack::peek() {
    // Check if the stack is empty, if empty, exit with failure
    // Otherwise return top of the stack
    if(is_empty()) {
        cout << "Error, Stack empty !" << endl;
        exit(EXIT_FAILURE);
    }else{
        return array[top_of_stack];
    }
}

// ------------------
// clear the stack
// ------------------
void Stack::clear() {
    cout << "======== Dumping Stack content ========" << endl;
    while(!is_empty()) {
        pop();
    }
}


// -------------------------
// Print the stack contents
// -------------------------
void Stack::print_stack() {
    cout << "Stack Content" << endl;
    cout << "|               |" << endl;
    cout << "|---------------|" << endl;
    for(int i = top_of_stack; i>= 0; i--) {
        cout << "|\t" << array[i] << "\t|" << endl;
        cout << "|---------------|" << endl;
    }
    cout << endl;
}


// -------------------------
// check if stack is full
// -------------------------
bool Stack::is_full() {
    // last stack element should be at max size -1
    return top_of_stack == size - 1;
}

// -------------------------
// check if stack is empty
// -------------------------
bool Stack::is_empty() {
    // empty stack is at inedx -1
    return top_of_stack == -1;
}























