# 本周学习心得
## 本周主要学习内容
本周主要还是进行了力扣刷题练习，开始尝试刷一些中等题和困难题，与简单题的不同和难度其实不在于实现的方法，而是在于实现起来的时间效率和空间效率，怎样才能找出使用的算法能够让这两个指标能够最低，而不是要求能够实现算法就可以，这也是我们通过刷题来锻炼自己的能力。
本周刷题遇到了一些很困难的思路，前期掌握这些思路比较困难，比如马拉车算法，
## 本周学习收获
abs()函数是用于整型数据

fabs()函数是用于浮点型数据

两者用来得到一个负值数
int转double
（double）a

如何把时间复杂度降低到 O(\log(m+n))O(log(m+n)) 呢？如果对时间复杂度的要求有 \loglog，通常都需要用到二分查找，这道题也可以通过二分查找实现

vector< vector<int> > v(m, vector<int>(n) );定义了一个vector容器，元素类型为vector<int>，初始化为包含m个vector<int>对象，每个对象都是一个新创立的vector<int>对象的拷贝，而这个新创立的vector<int>对象被初始化为包含n个0。

这是一个判断int型是否溢出的判断语句，注意这两行代码的思想*********
 if(m > INT_MAX / 10 || (m == INT_MAX / 10 && n > (INT_MAX % 10))) return 0;
 if(m < INT_MIN / 10 || (m == INT_MIN / 10 && n < (INT_MIN % 10))) return 0;

判断是否时数字
isdigit() 是字符串的一个方法，用来判断这个字符串是否是纯数字的字符串


auto用法
auto：在块作用域、命名作用域、循环初始化语句等等 中声明变量时，关键词auto用作类型指定符。

const:修饰符
​ 想要拷贝元素：for(auto x:range)
​ 想要修改元素 : for(auto &&x:range)
​ 想要只读元素：for(const auto& x:range)

auto
​ auto即 for(auto x:range) 这样会拷贝一份range元素，而不会改变range中元素；
但是！（重点) 使用for(auto x:vector)时得到一个proxy class,操作时会改变vector本身元素。应用：for(bool x:vector)

auto&
​当需要修改range中元素，用for(auto& x:range)
当vector返回临时对象，使用auto&会编译错误，临时对象不能绑在non-const l-value reference （左值引用）需使用auto&&,初始化右值时也可捕获

const auto&
​ 当只想读取range中元素时，使用const auto&,如：for(const auto&x:range),它不会进行拷贝，也不会修改range

const auto
​ 当需要拷贝元素，但不可修改拷贝出来的值时，使用 for(const auto x:range)，避免拷贝开销

auto for用法 注意两个；
for(auto x=p;x->next&&x->next->next;)


存在一个vector<int>lists，需要转为queue的方法
queue<ListNode*>q(deque<ListNode*>(lists.begin(),lists.end()))；
