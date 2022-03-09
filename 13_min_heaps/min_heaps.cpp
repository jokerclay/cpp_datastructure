/*
min heap:
最小堆： 父节点 小于等于 左子树和右子树(父节点最小)
 as a tree's 2 property
    * shape property: all the level should be fill out (树的每一层必须填满才才会移到下一层)
    * order property: child node should less than parent node 

    * each level store 2's power s node
    
        level 1         *               2 power 0   存储 2 的 0 次方个元素

        level 2     *       *           2 power 1   存储 2 的 1 次方个元素

        level 3  *    *    *    *       2 power 2   存储 2 的 2 次方个元素

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
class minHeap{
private:
    //create size of the heap
    // 堆的大小
    int size;

    // max size of the heap
    // 堆的容量
    int capacity; 

    // store elements as  a vector
    // vector 作为容器
    vector<int> heap;
    
    // returns the parent index 
    // 获得父元素的值
    int parent(int i) {return (i - 1)/2;}

    // returns the left child
    // 左子树
    int left(int i){return 2 * i + 1;}

    // returns the right child
    // 右子树
    int right(int i) {return 2 * i + 2;}

public:
    // constructor
    // 开辟最小堆
    minHeap(int capacity);

    // insert a key into the heap
    // 插入值
    void insert(int k);

    // Extracts the minimum element 
    // 提取最小元素
    int extractMin();

    // recursively heapify a sub-tree
    // 递归的处理 子树
    void heapify(int i);

    // print the heap 
    // 打印堆
    void printHeap();

};

// constructor that sets the heap size and capacity 
minHeap::minHeap(int capacity) {
    size = 0;
    this->capacity = capacity; 
    heap.resize(capacity);
}

// insert key into the minHeap  
void minHeap::insert(int key) {
    // make sure there is still have space in the heap
    // 检查堆是否满了
    if(size == capacity) {
        cout << "min heap is full" << endl;
        return ;
    }
    // Increase the amount of elements in the heap 
    size++;

    // insert the new key at the end; 
    int i = size -1;
    heap[i] = key;

    // fix the min heap property 
    // move the  element up until  i >= parent node or root 
    // 将大的父节点和小的节点交换，达到小的节点上浮的目的
    while(i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

// recursive function to maintain structure 
// 递归的比较 节点 节点的左子树 节点的右子树 维持节点最小
void minHeap::heapify(int i) {
    // set initial conditions
    int l = left(i);
    int r = right(i);
    int smallest = i;

    // find the smallest element int the tree  
    if((l < size ) && (heap[l] < heap[smallest])) {
        smallest = l;
    }if((r < size) && (heap[r] < heap[smallest])) {
        smallest = r;
    }

    // if the smallest of l or r, continue heapify   
    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

// remove the smallest element and fixes the order
int minHeap::extractMin() {
    // check if the heap is empty
    if(size == 0) {
        cout << "empty heap " << endl;
        return -1;
        // check if there only one element
    }else if(size == 1){
        size--;
        return heap[0];
        // normal extraction
    } else{
        // store the root  
        int root = heap[0];

        // maintain  the heap shape and then the order 
        // 维持堆的序列，移除根节点，将最后一个节点放到根节点上
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        // return the min element
        return root;
    }
}


// print the heap in a pretty format  
void minHeap::printHeap() {
    int power = 0;
    int value = 1;
    for(int i = 0; i < size; i++) {
        if(i == value) {
            cout << endl;
            power += 1;
            value += (1 << power);
        }
        cout << heap[i] << "  ";
    }
    cout << endl;
}



int main() {
    // number of element in our heap
    int N = 15;

    // declare a heap with  space for 10 elements
    minHeap heap(N);

    // insert N random numbers 
    for(int i = 0; i < N; i++) {
        cout << "inserting element " << i + 1 << endl;
        heap.insert(rand() %100);
        heap.printHeap();
        cout << endl;    
    }

    cout << endl;    
    int min = heap.extractMin();
    cout << endl;    
    heap.printHeap();

    return 0;
}











