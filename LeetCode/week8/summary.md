# 本周学习总结
## 本周学习内容
1.力扣学习内容：
本周继续延续每天五道leetcode算法题，主要涉及二分查找、深度优先遍历，这两部分在整个算法题中的涉及范围很广，二分法有很多种情况：左右闭合、左开右闭等，只要把每种二分的情况都分析清楚，那么今后遇到二分法类型的题目分析起来就会很方便了。
2.算法分析学习内容：
本周主要学习了红黑树、二叉搜查树，分析两种数据结构的不同，为什么要学习这两种数据结构，红黑树并不是数据结构里面叙述的那种简单的数据结构，其实在实际问题中，红黑树的涉及其实特别重要。
## 本周学习一些经验

模板1：while(left<=right)
循环体内有3个分支
在循环体中返回目标索引

class Solution {
    public int peakIndexInMountainArray(int[] nums) {
        int left=0;
        int right=nums.length-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid]>nums[mid+1]){
                right=mid-1;
            }
            else {本周
                left=mid+1;
            }
        }
        // 这里return什么都可以，因为对于此题来说，在循环体内一定会返回
        return -1;

    }
}
模板2：while(left<right)
循环体内有2个分支
在循环体外返回目标索引，在循环体内缩减搜索区间

class Solution {
    public int peakIndexInMountainArray(int[] nums) {
        int left=0;
        int right=nums.length-1;
        while(left<right){
            int mid=left+(right-left)/2;
            // 缩减区间为[mid+1,right]
            if(nums[mid]<nums[mid+1]){
                left=mid+1;
            }
            // 缩减区间为[left,mid]
            else {
                right=mid;
            }
        }
        // left=right时退出循环，返回left或right是一样的
        return left;

    }
}

count_if语句的使用
