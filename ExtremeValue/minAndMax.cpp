/*
 * @Description: Find minimum and maximum simultaneously.
 * @Author: fujunzhe
 * @Date: 2022-04-10 11:08:19
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * 同时找出最小和最大值：
 * 基于最小值算法，我们很容易想到一种同时判断最小值和最大值的算法：
 * 只需要分别独立地找出最小和最大值即可，但是这样每个元素都要经历两次判断。
 * 优化的方法就是成对地进行判断，先在输入的一对元素中进行一次判断，将较大
 * 者和当前最大值比较，较小者和当前最小值比较。每一对元素只需要经历三次判断。
 */
vector<int> findMinAndMax(vector<int> nums) {
    // 初始化时需要注意：如果数组元素个数为奇数，则最小和最大值都设置为nums[0]
    // 否则就对数组的前两位元素进行一次比较，分别设置为最小和最大值。
    // 这样做可以保证后面的元素都是成对出现。
    int min = 0;
    int max = 0;
    int i = 1;
    if (nums.size()&1) {
        min = max = nums[0];
    } else {
        min = nums[0]<nums[1] ? nums[0] : nums[1];
        max = nums[0]<nums[1] ? nums[1] : nums[0];
        i++;
    }

    for (i;i<nums.size();i+=2) {
        if (nums[i] < nums[i+1]) {
            min = nums[i] < min ? nums[i] : min;
            max = nums[i+1] > max ? nums[i+1] : max;
        } else {
            min = nums[i+1] < min ? nums[i+1] : min;
            max = nums[i] > max ? nums[i] : max;
        }
    }

    return {min, max};
}

// test
int main(int argc, char const *argv[])
{
    vector<int> nums = {8,4,2,6,0,1,5,12};
    vector<int> res = findMinAndMax(nums);
    cout << "min: " << res[0] << endl;
    cout << "max: " << res[1] << endl;
    return 0;
}
