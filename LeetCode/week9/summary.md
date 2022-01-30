# 本周学习总结
## 本周主要学习情况
本周没有继续过多的进行leetcode的刷题，总的进行了一个复习，总结了一些做题的技巧和思路；
1.主要出题范围
通过初步的进行学习，刷题训练，出题涉及知识频率较高的主要是：二分法、递归、回溯、二叉树深度与广度遍历、动态规划、排序、滑动窗口等，其实通过这一段时间的学习，这些题是有一些套路在里面的，需要不断地总结；
2.对待一个题目的态度
如果只是为了解决出这道题目，那么暴力法可以解决大多数的问题，我们需要找出最有效的方法，做出一道题后，通过查看题解与评论，可以找到很多关于这道题目的其它解法，这些解法并不是要求我们熟记，而是要找出为什么这道题从这种解题角度入手，通过大量题目的训练，我们可以找出一些门道，在遇到其他的题目时，我们总能够找出相似的地方，这有助于我们思考出最有效的解题方案；
## sstream使用
我们可以使用stringstream类对象来避开此问题。在程序中如果想要使用stringstream，必须要包含头文件#include<sstream>
1.转化
 将一个整形变量转化为字符串，存储到string类对象中
	stringstream s;
	s << a;
	s >> sa;
	// 将stringstream底层管理string对象设置成"", 
	// 否则多次转换时，会将结果全部累积在底层string对象中
	s.str("");
2.拼接
stringstream sstream;
	// 将多个字符串放入 sstream 中
	sstream << "first" << " " << "string,";
	sstream << " second string";
	cout << "strResult is: " << sstream.str() << endl;
3.分割
std::string data = "1_2_3_4_5_6";
        std::stringstream ss(data);
        std::string item;
        queue<string> q;
        cout << data << endl;
        while (std::getline(ss, item, '_')) 
            cout << item << ' ';  
