/*
 * @Description: Find Kth largest value.
 * @Author: fujunzhe
 * @Date: 2022-04-10 11:47:02
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 选择第k大的元素：
 * 想从n个元素的数组中找到第k大的元素，一个简单的想法是先对数组排序，位于第k位的元素就是答案。
 * 但是时间复杂度最优的比较排序算法也需要O(nlgn)的时间。我们可以在此基础上进行改进，得到一种
 * 线性时间复杂度的选择算法。
 * 
 * 选择算法以快速排序为模型，将数组进行递归划分，但区别是不再同时处理两边，而是每次只处理一边的子数组。
 */
int partition(vector<int>& nums, int p, int r) {
    int value = nums[r];
    int i = p-1;
    for (int j=p;j<r;j++) {
        if (nums[j]<=value) {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[++i], nums[r]);
    return i;
}


int findKthLargest(vector<int>& nums, int p, int r, int k) {
    if (p == r) {
        return nums[p];
    }

    int q = partition(nums, p, r);  // q是当前主元的下标
    if (k == q-p+1) { // q-p+1是当前主元的顺序统计量，也就是当前主元是数组中第q-p+1大的元素
        return nums[q];
    } else if (k < q-p+1) {
        return findKthLargest(nums, p, q-1, k);
    } else {
        return findKthLargest(nums, q+1, r, k-(q-p+1));
    }
}

// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5,6,7};
    cout << findKthLargest(nums, 0, nums.size()-1, 4) << endl;
    return 0;
}
