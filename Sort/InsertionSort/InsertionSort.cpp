/*
 * @Description: Implement insertion sort.
 * @Author: fujunzhe
 * @Date: 2022-03-26 20:04:55
 */
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &nums) {
    for (int j=1;j<nums.size();j++) {
        int key = nums[j];
        int i = j-1;
        while (i>=0 && nums[i]>key) {
            nums[i+1] = nums[i];
            i--;
        }
        nums[i+1] = key;
    }
}

// test
int main() {
    vector<int> nums = {5,4,3,2,1};
    insertionSort(nums);
    for (auto num : nums) {
        cout << num << endl;
    }
    return 0;
}