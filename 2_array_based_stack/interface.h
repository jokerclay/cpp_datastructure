// This file specifies the interface for a stack class

#include <iostream>
#include <cstdlib>

class Stack {
    private:
        int *array;
        int top_of_stack;
        int size;
    public:
        // Give a default size in case of user forgets
        Stack(int s = 10) {
            // update the stack size
            size = s;
            // Allocate the stack
            array = new int[size];
            // set the top of stack to invild value
            top_of_stack = -1;
        }

        // Add a new item to the stack
        void push(int);
        // Remove an item from the stack
        void pop();
        // look at the top of the stack
        int peek();
        // clear the stack
        void clear();
        // print the stack contents
        void print_stack();
    private:
        // check if the stack is full (avoid underflow)
        bool is_full();
        // check if the stack is empty (avoid underflow)
        bool is_empty();
};

