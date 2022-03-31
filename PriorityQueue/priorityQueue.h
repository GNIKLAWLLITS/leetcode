/*
 * @Description: Priority queue header file.
 * @Author: fujunzhe
 * @Date: 2022-03-31 19:31:33
 */
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
using namespace std;

/**
 * 普通队列是一种先进先出的数据结构，其实是默认以时间为优先级，时间越早优先级越高。
 * 优先队列则是可以自定义一种属性为优先级的队列。优先队列可用堆实现。
 */
typedef struct {
    vector<int> nums;
    int capacity;   // 实际容量
} Queue;

class PriorityQueue {
    public:
        Queue queue;

        // constructor
        PriorityQueue();
        PriorityQueue(vector<int> nums);

        // insert
        void insert(int e);

        // maximum
        int maximum();

        // extract-maximum
        int extractMaximum();

        // increase-key
        void increaseKey(int i, int k);

        // is-empty
        bool isEmpty();

        // list
        void printList(); 
};

// maintain heap
void maxHeapify(Queue& queue, int i);

// build heap
void buildMaxHeap(Queue& queue);

#endif