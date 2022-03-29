/*
 * @Description: leetcode No.2024
 * @Author: fujunzhe
 * @Date: 2022-03-29 11:48:59
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int slidingWindow(string answerKey, int k, char ch) {
    // 保存最大的窗口长度
    int ans = 0;
    // 保存当前窗口内非指定字符的数量
    int sum = 0; 

    for (int left=0, right=0; right<answerKey.size(); right++) {
        // 如果是非指定字符，则sum+1
        if (answerKey[right] != ch) {
            sum++; 
        }

        // 如果窗口尺寸过大，则向右移动left收缩窗口
        while (sum > k) { 
            if (answerKey[left] != ch) {
                sum--; 
            }
            left++;
        }

        // 每次移动后都需要判断最大窗口尺寸是否更新 
        ans = max(ans, right-left+1);
    }

    return ans;
}

int maxConsecutiveAnswers(string answerKey, int k) {
    return max(slidingWindow(answerKey, k, 'T'), slidingWindow(answerKey, k, 'F'));
}

