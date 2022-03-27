/*
 * @Description: Solve maximum sub-array problem based on divide and conquer method.
 * @Author: fujunzhe
 * @Date: 2022-03-27 18:50:20
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * @brief Find one of the maximum sum of crossing sub-array.
 * 
 * @param nums 
 * @param low 
 * @param mid 
 * @param high 
 * @return int
 */
int findMaxCrossingSubArray(vector<int> nums, int low, int mid, int high) {
    // check left part
    int left_sum = INT_MIN; // maximum sum of left part
    int sum = 0; // sum(nums[i..mid])
    int max_left = mid; // left index of maximum sub-array
    for (int i=mid;i>=low;i--) {
        sum += nums[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    // check right part
    int right_sum = INT_MIN; // maximum usn of right part
    sum = 0; // sum(nums[mid+1..i])
    int max_right = mid+1; // right index of maximum sub-array
    for (int i=mid+1;i<=high;i++) {
        sum += nums[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    return left_sum+right_sum;
}

/**
 * @brief Find one of the maximum sum of sub-array.
 * 
 * @param nums 
 * @param low 
 * @param high 
 * @return int 
 */
int findMaxSubArray(vector<int> nums, int low, int high) {

    if (low == high) {
        return nums[low];
    }

    int mid = (high-low)/2+low;
    int left_max = findMaxSubArray(nums, low, mid);
    int right_max = findMaxSubArray(nums, mid+1, high);
    int cross_max = findMaxCrossingSubArray(nums, low, mid, high);

    if (left_max>=right_max && left_max>=cross_max) {
        return left_max;
    } else if (right_max>=left_max && right_max>=cross_max) {
        return right_max;
    } else {
        return cross_max;
    }
}

// test
int main(int argc, char const *argv[]) {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = findMaxSubArray(nums, 0, nums.size()-1);
    cout << res << endl;
    return 0;
}
