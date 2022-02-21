#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

using namespace std;

struct node{
    // pointers to left and right nodes 
    node *left;
    node *right;

    // data 
    int data;

    // constructor
    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
    public:
        // root node of the tree
        node *root;

        // a simple constructor to set the root to NULL
        BinarySearchTree(){
            root = nullptr;
        }

        // a simple method for inserting a node
        node *insert_node(node* n, int d);

        // a simple method for searching a node with data 'd'
        node *search(int d);
};

// Recursively traverse the tree untill the node is nullptr 

//  -----------------
//  insert point
//  -----------------
node *BinarySearchTree::insert_node(node *n, int d) {
    // if there is no binary search tree, create a tree and the node you are
    // inserting as the root of the tree 
    if(n == nullptr) {
        cout << " X " << endl;
        return new node(d);

    // case that we traverse the left path
    }else if(d < n->data) {
        cout << "L";
        n->left = insert_node(n->left, d);

    // case that we traverse the right path
    }else if(d > n->data) {
        cout << "R";
        n->right = insert_node(n->right,d);

    // case that we duplicate entries(illegl)
    }else{
        assert(false);
    }


    return n;
}


//  -----------------
//  search data
//  -----------------
node *BinarySearchTree::search(int d) {
    // temp node to use for traversal (init to root)
    node *temp = root;

    // keep traversing the tree untill the node is founded (or not)
    while(temp != nullptr) {
        // if it is, return the node we are looking for    
        if(d == temp->data) {
            cout << " X " << endl;
            return temp;
        }else if(d < temp->data) {
            cout << "L";
            temp = temp->left;
        }else{
            cout << "R";
            temp = temp->right;
        }
    }
    // when we didn't find the node
    return nullptr;
}

int main() {
    // create a new binary search tree
    BinarySearchTree bst;

    // set the seed
    srand(time(0));
    int data;

    // insert 10 random value
    vector<int> data_vec;
    for(int i = 0; i < 10; i++) {
        // random number between 0 ~ 999
        data = rand() % 1000;

        // save the number so we can search it later
        data_vec.push_back(data);
        cout << "inserting node with data " << data << endl;
        bst.root = bst.insert_node(bst.root, data);
    }
    cout << endl;

    // search for each of the inserted node 
    for(int i : data_vec) {
        cout << "searching for node with data " << i << endl;
        bst.search(i);
    }

    return 0;
}

