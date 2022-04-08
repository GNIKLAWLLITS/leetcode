/*
 * @Description: Implements quick sort.
 * @Author: fujunzhe
 * @Date: 2022-04-08 19:24:25
 */

/**
 * 分治法解决快排问题：
 * 1. 分解：将数组A[p..r]划分为两个子数组A[p..q-1]和A[q+1..r]，
 * 使得A[p..q-1]中的每个元素都小于A[q]，而A[q+1..r]中的每个元素都大于A[q]。
 * 2. 解决：递归调用快速排序，对子数组进行快排。
 * 3. 合并：由于快排是原地排序，因此不需要合并步骤。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief （单向移动）分解函数，将数组划分为A[p..q-1]和A[q+1..r]，
 * 使得A[p..q-1]中的每个元素都小于A[q]，而A[q+1..r]中的每个元素都大于A[q]。
 * 
 * @param nums 
 * @param p 
 * @param r 
 */
int partition(vector<int>& nums, int p, int r) {
    int value = nums[r]; // 将最后一个元素作为主元
    int i = p-1; // 设置i的初始值，i会始终指向有序序列中最后一个比主元小的数
    for (int j=p;j<r;j++) { // 注意此处j!=r，因为r是主元
        if (nums[j] <= value) {
            swap(nums[++i], nums[j]); 
        }
    }
    swap(nums[++i], nums[r]); // 最后将主元放到正确的位置，即nums[i+1]
    return i;
}

void quickSort(vector<int>& nums, int p, int r) {
    if (p < r) {
        int q = partition(nums, p, r);
        quickSort(nums, p, q-1);
        quickSort(nums, q+1, r);
    }
}

// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {9,8,7,6,5,4,3,2,1};
    quickSort(nums, 0, nums.size()-1);
    for (auto num : nums) {
        cout << num << endl;
    }
    return 0;
}
