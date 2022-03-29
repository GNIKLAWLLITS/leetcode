/*
 * @Description: Implements heapsort.
 * @Author: fujunzhe
 * @Date: 2022-03-29 16:07:52
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void maxHeapify(vector<int>& heap, int len, int i) {
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    // if left child exists
    if (left<=len && heap[left]>heap[i]) {
        largest = left;
    }
    // if right child exists
    if (right<=len && heap[right]>heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        // exchange
        swap(heap[i], heap[largest]);
        // check if swap breaks the structure of next layer
        maxHeapify(heap, len, largest);
    }
}

void buildMaxHeap(vector<int>& heap) {
    int len = heap.size()-1;
    for (int i=len/2;i>0;i--) {
        maxHeapify(heap, len, i);
    }
}

void heapsort(vector<int>& heap) {
    int len = heap.size()-1;
    // build heap
    buildMaxHeap(heap);
    for (int i=len;i>=2;i--) {
        // exchange
        swap(heap[i], heap[1]);
        // remove last element
        len--;
        maxHeapify(heap, len, 1);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> heap = {0,1,2,3,4,5,6,7};
    // maxHeapify(heap, heap.size()-1, 1);
    buildMaxHeap(heap);
    // heapsort(heap);
    for (auto num : heap) {
        cout << num << endl;
    }
    return 0;
}
