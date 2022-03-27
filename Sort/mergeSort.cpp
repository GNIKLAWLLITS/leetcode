/*
 * @Description: Implements merge sort.
 * @Author: fujunzhe
 * @Date: 2022-03-27 10:03:37
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Merge two ordered lists(nums[low..mid], nums[mid+1..high]).
 * 
 * @param nums 
 * @param low 
 * @param mid 
 * @param high 
 */
void merge(vector<int>& nums, int low, int mid, int high) {
    int len1 = mid-low+1;
    int len2 = high-mid;
    vector<int> left(len1+1);
    vector<int> right(len2+1);
    for (int i=0;i<len1;i++) {
        left[i] = nums[i+low];
    }
    for (int j=0;j<len2;j++) {
        right[j] = nums[j+mid+1];
    }
    // 设置哨兵
    left[len1] = INT_MAX;
    right[len2] = INT_MAX;

    // 合并 
    int i = 0;
    int j = 0;
    for (int k=low;k<=high;k++) {
        if (left[i] <= right[j]) {
            nums[k] = left[i++];
        } else {
            nums[k] = right[j++];
        }
    }

}


void mergeSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int mid = (high-low)/2+low;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
}

// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {4,7,2,9};
    mergeSort(nums, 0, nums.size()-1);
    for (auto num : nums) {
        cout << num << endl;
    }
    return 0;
}


