/*
    keys : values

keys ==> || hash_function || ===> values

*/

#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

using namespace std;


class HashTable {
    private:
        // Number of buckets to store element
        int buckets;

        // Pointer to say buckets
        // <list> is a double list
        list<int> *table;

    public:
        // simple constructor
        HashTable(int d) {
            // allocate space for the number of buckets asked for 
            buckets = d;
            table = new list<int>[buckets];
        }

        // insert into hash table
        void insert(int d);

        // print out the hash table 
        void print();
};

void HashTable::insert(int d) {
    // simple hash function just modulo number of buckets 
    int bucket = d % buckets;
    
    // insert into hash table bucket    
    table[bucket].push_back(d);
}

void HashTable::print() {
    for (int i = 0; i < buckets; i++ ) {
        cout << "| Buckets " << i  << " | ";
        for (auto j : table[i]) {
            cout << "-> | " << j << " | ";
        }
        cout << endl;
    }
}



int main() {

    // create a hash table  with 8 buckets
    HashTable ht(8);

    // set random number seed   
    srand(time(0));



    cout << "Random number : " << endl;
    for (int i = 0; i < 20; i++) {
        cout << rand() % 100 << ", " ;
    }

    cout << endl;
    cout << endl;

    // insert 20 random integers under 100
    for (int i = 0; i < 20; i++) {
        ht.insert(rand() %100);
    }


    // print the state of the hash table
    ht.print();


    return 0;
}

