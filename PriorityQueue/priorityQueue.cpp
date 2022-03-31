/*
 * @Description: Implements priority queue with heap.
 * @Author: fujunzhe
 * @Date: 2022-03-31 19:14:28
 */

#include "priorityQueue.h"
#include <iostream>
#include <algorithm>

// constructor
PriorityQueue::PriorityQueue() {
    this->queue.nums = {0};
    this->queue.capacity = 0;
}
PriorityQueue::PriorityQueue(vector<int> nums) {
    this->queue.nums.assign(nums.begin(), nums.end());
    this->queue.capacity = nums.size();
    this->queue.nums.insert(this->queue.nums.begin(), 0);
}

// insert


// maximum
int PriorityQueue::maximum() {
    return this->queue.nums[1];
}

// extract-maximum
int PriorityQueue::extractMaximum() {
    if (this->queue.capacity < 0) {
        cout << "heap underflow" << endl;
        return -1;
    }
    int max = maximum();
    // 第一位出列后，将末尾的元素移动到堆顶
    this->queue.nums[1] = this->queue.nums[this->queue.capacity];
    this->queue.capacity--;
    maxHeapify(this->queue, 1);
    return max;
}

// is-empty
bool PriorityQueue::isEmpty() {
    return this->queue.capacity==0;
}
    
// list
void PriorityQueue::printList() {
    if (isEmpty()) {
        cout << "The queue is empty!" << endl;
    } else {
        for (int i=1;i<=this->queue.capacity;i++) {
            cout << this->queue.nums[i] << endl;
        }
    } 
}

// maintain heap
void maxHeapify(Queue& queue, int i) {
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    // if left child exists
    if (left<=queue.capacity && queue.nums[left]>queue.nums[i]) {
        largest = left;
    }
    // if right child exists
    if (right<=queue.capacity && queue.nums[right]>queue.nums[largest]) {
        largest = right;
    }
    if (largest != i) {
        // exchange
        swap(queue.nums[i], queue.nums[largest]);
        // check if swap breaks the structure of next layer
        maxHeapify(queue, largest);
    }
}

// build heap
void buildMaxHeap(Queue& queue) {
    for (int i=queue.capacity/2;i>0;i--) {
        maxHeapify(queue, i);
    }
}

// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3};
    PriorityQueue pq = PriorityQueue(nums);
    pq.printList();
    buildMaxHeap(pq.queue);
    pq.printList();
    return 0;
}
