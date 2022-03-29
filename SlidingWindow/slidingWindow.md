<!--
 * @Description: 
 * @Author: fujunzhe
 * @Date: 2022-03-29 13:23:01
-->
# 滑动窗口
滑动窗口的作用是可以将一部分问题中的嵌套循环转变为一个单循环，因此可以减少时间复杂度。

## 滑动窗口的基本思想
1. 使用 left 和 right 指针来指定窗口大小，默认值都为 0。
2. 先让 right 向右移动直到窗口大小符合要求。
3. 然后将 left 向右移动不断缩小窗口，直到窗口不再满足要求。
4. 重复第 2-3 步，直到 right 指针到达数组的尽头。

难点在于判断窗口的要求。

## 例题分析
以 leetcode 第2024题为例：一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：

- 每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。

请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。

```
输入：answerKey = "TFFT", k = 1
输出：3
解释：我们可以将最前面的 'T' 换成 'F' ，得到 answerKey = "FFFT" 。
或者，我们可以将第二个 'T' 换成 'F' ，得到 answerKey = "TFFF" 。
两种情况下，都有三个连续的 'F' 。
```
问题实际是在问“在可以改变k个字符的情况下，最大的连续‘T’或‘F’数组的长度是多少”。按照上述分析，对于滑动窗口的要求的直接理解应该是窗口内全部的字符经过 k 次转换都应该是指定字符,翻译一下就是窗口内非指定字符的个数不能超过 k，但我们又希望窗口尽可能地大，这样才能使得连续序列最长。因此对于窗口大小的要求就是窗口内的非指定字符数应维持在 k 个。接下来就可以按照步骤实现滑动窗口解法了：

```cpp
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
```
然后我们分别判断哪一种转换策略可以得到最长连续序列即可：
```cpp
int maxConsecutiveAnswers(string answerKey, int k) {
    return max(slidingWindow(answerKey, k, 'T'), slidingWindow(answerKey, k, 'F'));
}
```
