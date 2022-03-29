/*
 * @Description: 
 * @Author: fujunzhe
 * @Date: 2022-03-29 16:07:52
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void maxHeapify(vector<int>& heap, int i) {
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    // if left child exists
    if (left<heap.size() && heap[left]>heap[i]) {
        largest = left;
    }
    // if right child exists
    if (right<heap.size() && heap[right]>heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        // exchange
        swap(heap[i], heap[largest]);
        // check if swap breaks the structure of next layer
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(vector<int>& heap) {
    for (int i=heap.size()-1/2;i>0;i--) {
        maxHeapify(heap, i);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> heap = {0,1,2,3,4,5};
    // maxHeapify(heap, 1);
    buildMaxHeap(heap);
    for (auto num : heap) {
        cout << num << endl;
    }
    return 0;
}
