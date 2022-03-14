# 容器

map.count（x） 即使当map[x]=0时也会

# 函数

## pow（n，x）n的x次方

## reverse（s）s反转 复杂度位O(N) N为s的长度

### sizeof（a）返回变量的大小 

## isalpha ：判断一个字符是否为字母，如果是则返回true，否则返回false；

## isdigit : 判断一个字符是否表示数字，如果是则返回true，否则返回false；

## isalnum : 判断一个字符是否表示数字或者字母，如果是则返回true，否则返回false;

## islower : 判断一个字符是否为小写字母，如果是则返回true，否则返回false;

## isupper : 判断一个字符是否为大写字母，如果是则返回true，否则返回false；

## tolower : 若字符为字母则转化为小写字母；

## toupper : 若字符为字母则转化为大写字母；

# 位运算

## 逻辑运算符

逻辑运算符与10可以判断一些情况，

比如任何数与1相&就会知道这个数是不是奇偶或者这个数二进制最后一位

可以用ss>>s判断字符串长度，（看字符串是不是都用完了）





# 字符串：

## 关于acsii码

26个字母

a-z 97-122
A-Z 65-90
(s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= '0'&&s[i] <= '9'))//是数字或者字母



## 关于字符c++的几个内置函数：

islower(char c) ‘是否为小写字母
isupper(char c) 是否为大写字母
isdigit(char c) 是否为数字
isalpha(char c) 是否为字母
isalnum(char c) 是否为字母或者数字
toupper(char c) 字母小转大
tolower(char c) 字母大转小

## string一些使用技巧

### s.substr(i,n)

获取s从位置i开始n个长度的子串

###  s.size() 

数据类型为 unsigned long, right 的数据类型为 int 

# 链表

## 自定义双链表

 struct Node{
        int key,value;
        Node* left ,*right;
        Node(int _key,int _value): key(_key),value(_value),left(NULL),right(NULL){}
    }*L,*R;//双链表的最左和最右节点，不存贮值。

## 链表哨兵（虚拟头节点）防止删除头节点无法操作

dummty->next=head；

# 算法思想

## 1.单调栈

单调栈分单调增栈和单调减栈，当出现一个不是单调规则的，出栈然后求面积。

![1646375752356](C:\Users\YANG\AppData\Roaming\Typora\typora-user-images\1646375752356.png)

## 2.链表

### 1.环 

利用快慢指针

### 2.利用路径长度

### 3.反转用递归

leetcode反转链表

### 4.关于链表的数值

可以用栈

## 3.字符串

多利用哈希

## 
