/*
 * @Description: Find minimum.
 * @Author: fujunzhe
 * @Date: 2022-04-10 11:00:42
 */

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> nums) {
    int min = nums[0];
    for (int i=1;i<nums.size();i++) {
        min = nums[i]<min ? nums[i] : min;
    }
    return min;
}

// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    cout << findMin(nums) << endl;
    return 0;
}
