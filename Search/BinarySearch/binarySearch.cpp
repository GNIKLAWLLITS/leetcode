/*
 * @Description: Implements binary search.
 * @Author: fujunzhe
 * @Date: 2022-03-26 21:28:2
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * @param nums 
 * @param target
 * @return if find, return index; if not, return -1.
 */
int search(vector<int> nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    while (low <= high) {
        int middle = (high-low)/2+low;  // avoid overflow
        if (nums[middle] == target){ 
            return middle;
        } else if (nums[middle] > target) {
            high = middle-1;
        } else if (nums[middle] < target) {
            low = middle+1;
        }
    }
    return -1;
}

// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << search(nums, target);
    return 0;
}
