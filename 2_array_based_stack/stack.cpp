#include <iostream>
#include "interface.h"

using namespace std;

int main() {
    // create a new stack
    Stack s;

    // Add some elements to the stack
    for(int i = 0; i < 5; i++) {
        s.push(i);
    }

    // remove some elements from the stack
    for(int i = 0; i < 2; i++) {
        s.pop();
    }

    cout << s.peek() << endl;
    
    s.clear();

    return 0;
}
