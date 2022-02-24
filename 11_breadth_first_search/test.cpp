
#include <iostream>
#include <list>

using namespace std;


int main() {

list<int> *li_pointer;

li_pointer = new list<int>[5];

for(auto elem : li_pointer) {
    cout << elem << " ";
}
cout << endl;




    return 0;
}
