# 位运算

### 剑指 001 整数除法

本题需要注意的点：边界问题 负数转正数出问题，正数转负数不会有问题。

当负数超出边界，我们给这个负数减去一个除数就解决了

leetcode不支持c++负数的左移。

![1649384174740](C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1649384174740.png)

```c++
class Solution {

public:

  int divide(int a, int b) {

​     if ((a == INT_MIN && b == -1) || (a == INT_MAX && b == 1)) {

​      return INT_MAX;

​    }

​    if (a == INT_MIN && b == 1) {

​      return INT_MIN;

​    }

​    if (a == INT_MIN && b == INT_MIN) {

​      return 1;

​    }

​    if (b == INT_MIN) {

​      return 0;

​    }

​    int sign = (a^b) >= 0 ? 1 : -1; // 取得最终符号

​    int res = 0;

​    if (a == INT_MIN) { // 被除数为INT_MIN时

​      a += abs(b); // 先加上一个被除数的绝对值，防止后续取绝对值的时候溢出 

     ++ res; // 贡献+1

​    }

​    a = abs(a), b = abs(b); // 经过前面的边界处理，这里都取绝对值一定不会溢出！

​    if (a < b) { // 被除数比除数小，后面不用再算了

​      return sign == 1 ? res : -res; // 提前返回，记得带符号

​    }

​    // 重点来了，依次枚举因子

​    for (int i=30; i>=0; --i) { // 都是正数，左移31就变负了，不用考虑 

​      if (b > (INT_MAX >> i)) { // 判断当前除数是否能左移这么多位

​        continue; // 不能就下一轮

​      }

​      int curDiv = b << i; // 除数左移i位，得到b的(2^i)倍作为新的因子

​      if (a >= curDiv ) { // 判断当前被除数是否不小于这个因子

​        a -= curDiv; // 更新被除数

​        if (res > INT_MAX - (1 << i)) { // 判断答案加上这次的贡献后是否溢出

​          return INT_MIN; // 溢出则直接返回最小值

​        }

​        res += 1 << i; // 当前因子对答案的贡献为（1<<i）

​      }

​    }

​    return sign == 1 ? res : -res;

  }

}
```



### 剑指 002 二进制加法

本题思想：逐位计算，注意两个字符串结束不一定代表真的结束，**要注意最后有没有进位**！

![1649486137795](C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1649486137795.png)

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        string fault;
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0||j>=0||carry!=0){
            int tmpa=i>=0?a[i]-'0':0;
            int tmpb=j>=0?b[j]-'0':0;
            int sum=tmpa+tmpb+carry;
            int tmp=sum>=2?sum-2:sum;
            carry=sum>=2?1:0;
            i--;
            j--;
            fault+=tmp+'0';
        }
        reverse(fault.begin(),fault.end());
        return fault;
    }
};
```

### 剑指 003 二进制中1的数

分析：

​		我们看二进制0111111 0111110 偶数和奇数，奇数是一定比它前面的数多一个1，因为用动态规划，偶数的1的个数和偶数向右移1为的1是相等的。

i为奇数：dp[i]=dp[i-1]+1

i为偶数：dp[i]=dp[i/2]

<img src="C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1649487989428.png" alt="1649487989428" style="zoom: 67%;" />

### 剑指 004 只出现一次的数字

如果不用额外空间，我们可以因为只有一个出现一次，其它都是m次，所以我们通知每个二进制上出现的次数，如果%m次剩下的就是那个唯一的数在该二进制上是否出现

![1649488542953](C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1649488542953.png)

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>count(32,0);
        for(int num:nums){
            for(int i=0;i<32;i++){
                // 这里&1是因为判断移位后最后那个是不是1，其实就是判断奇偶
                count[i]+=(num>>(31-i)&1);
            }
        }
        int fault=0;
        int m=3;
        for(int i=0;i<32;i++){
            fault=(fault<<1)+count[i]%m;
        }
        return fault;
    }
};
```

### 剑指 005 单词长度最大乘积

用32位int表示26的字母

![1649490147520](C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1649490147520.png)

```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>hash(words.size(),0);
        for(int i=0;i<words.size();i++){
            for(char c:words[i]){
                hash[i]|=(1<<(c-'a'));
            }
        }
        int fault=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((hash[i]&hash[j])==0){
                    fault=max(fault,int(words[i].size()*words[j].size()));
                }
            }
        }
        return fault;
    }
};
```



# 数组

## 滑动窗口

不要忘了滑动窗口。

## 前缀和

### 前缀和+哈希表

### 剑指 011 0和1数相等的子数组

思路：永远的思路远比代码难，想一想从前遍历，我们把0设为减1，把1设为加1，初始化sum=-1，这时候01个数相等。当两个sum相等说明他们的0和1的个数相差是相等的，他们增加了相等的0和1，所以这两个之间有相等的0，1个数。

![1649581884404](C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1649581884404.png)

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        int sum=0;
        int len=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==0)?-1:1;
            if(m.count(sum)){
                len=max(len,i-m[sum]);
            }else{
                m[sum]=i;
            }
        }
        return len;
    }
};
```



# 动态规划

## 背包问题

背包问题就是有个容量为j的背包，有i个物品，0-i-1，f（i，j）表示前i个物品能不能装满j容量的背包。

有两种情况，前i-1个物品就能装满，那么i就不装了，还有一只前i-1个物品只能装满j-i物品大小的容量，这两种情况都是可行的。

### 01背包

### 剑指 101 分割等和子集

思路：分割程两部分

1.这两部分的和是相等的，所以所有的数加起来必须是偶数，不然不能均分

2.每次我们操作都是基于前面的数组成一个值为n的组合，然后n必须小于等于和的一半，不然没有意义。所以我们定义一个状态方程

f(i,j)表示前i个数是否能够装满j容量的背包。f(i,j)=f(i-1,j)||f(i-1,j-nums[i])注意（我们只考虑j>=nums[i],背包容量为负就是扯淡） 就这这个数装不装入背包，只有这两种情况。然后最后我们查看是不是有容量为j的背包装满

3.最后一步，是判断起始位置，f(0,j)和(i,0)背包不装东西肯定为1，容量为0，装不下东西，为0

一维数组可以实现，但是要从后往前，因为我们从前往后的状态方程是基于前面的状态，如果前面状态我们修改了，状态方程会出问题！！！！

![1649426162879](C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1649426162879.png)

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if((sum&1)!=0){
            return false;
        }
        int target=sum/2; 
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=dp[j]||dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};
```

### 完全背包

### 剑指 103 最少的硬币数量

完全背包不同于01背包，01背包每个物品只有装或者不装，完全背包是可以不装或者装>=1个物品。

所以我们遍历的时候从值开始遍历，不同值是否使用硬币就很明显了。

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1);
        for(int i=1;i<=amount;i++){
            dp[i]=amount+1;
            // 这里是为了如果这个值没有硬币组合就置为这个数，最后返回判断时返回-1；
            for(auto& coin:coins){
                if(i>=coin){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};
```

