<!--
 * @Description: 
 * @Author: fujunzhe
 * @Date: 2022-03-26 21:40:24
-->
# 二分查找

借用二分法的思想，每次对待查序列进行对半分。最坏时间复杂度为 $Olog(n)$。但要注意的是二分查找是有使用条件的，仅在数列<font color=red>有序</font>且每个元素都<font color=red>唯一</font>的情况下才可用。

另外，在具体实现时要注意防止计算 middle 时产生溢出：
```cpp
int middle = (high-low)/2+low;
```
