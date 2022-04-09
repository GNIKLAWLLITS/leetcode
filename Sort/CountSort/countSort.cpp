/*
 * @Description: Implements count sort.
 * @Author: fujunzhe
 * @Date: 2022-04-09 17:23:17
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 计数排序：
 * 计数排序是一种非比较排序，其原理是用一个范围从0到k
 * 可以覆盖原数组的全体元素的新数组来统计每个元素的个数。
 */
vector<int> countSort(vector<int> nums, int k) {

    // 1. 初始化新数组temp，其包含k个0
    vector<int> temp(k, 0);

    // 2. 遍历原数组，如果nums[j]=i，则temp[i]+1
    for (int j=0;j<nums.size();j++) {
        temp[nums[j]]++;
    }

    // 3. 整理新数组，使得temp[i]代表i的个数
    for (int i=1;i<=k;i++) {
        temp[i] += temp[i-1];
    }

    // 4. 输出排好序的数组
    vector<int> ans(nums.size(), 0);
    for (int j=nums.size()-1;j>=0;j--) {
        ans[temp[nums[j]]-1] = nums[j];
        temp[nums[j]]--; // 使相同元素可在不同位置输出
    }

    return ans;
}


// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {9, 7, 6, 4, 2, 1, 0};
    vector<int> ans = countSort(nums, 9);
    for (auto num : ans) {
        cout << num << endl;
    }
    return 0;
}
