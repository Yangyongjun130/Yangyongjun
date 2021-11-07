//头文件
#ifndef _Tree_H
#define _Tree_H
 
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *TwoDTree;
 
void makeEmpty(TwoDTree t);
Position find(ElementType X1,ElementType X2, TwoDTree t);
 
TwoDTree insert(ElementType X1, ElementType X2, TwoDTree t);
void dir(TwoDTree t);
void printSelect(ElementType low1, ElementType high1, ElementType low2, ElementType high2,TwoDTree t);
#include"2-d_tree.h"
#include"fatal.h"
#include<iostream>
struct TreeNode {
	ElementType element1;
	ElementType element2;
	TwoDTree left;
	TwoDTree right;
};
 
void makeEmpty(TwoDTree t) {
	if (t) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		free(t);
	}
}
 
Position find(ElementType X1, ElementType X2, TwoDTree t) {
	int layer = 0;
	if (t == NULL) {
		return NULL;
	}
	while (t) {
		if (layer % 2 == 0) {
			if (X1 < t->element1)
				t = t->left;
			else if (X1 > t->element1)
				t = t->right;
			else {
				if (X2 == t->element2)
					return t;
				else
					return NULL;
			}
			layer++;
		}
		else {
			if (X2 < t->element2)
				t = t->left;
			else if (X2 > t->element2)
				t = t->right;
			else {
				if (X1 == t->element1)
					return t;
				else
					return NULL;
			}
			layer++;
		}
	}
	return NULL;
}
 
 
static Position newNode(ElementType X1, ElementType X2) {
	TwoDTree t = new TreeNode;
	if (t == NULL)
		Error("out of memory");
	t->element1 = X1;
	t->element2 = X2;
	t->left = NULL;
	t->right = NULL;
	return t;
}
 
TwoDTree insert(ElementType X1, ElementType X2, TwoDTree t) {
	int layer = 0;
	Position fater = NULL;
	Position son = t;
	if (t == NULL) {//包含树没有初始化
		t = newNode(X1, X2);
	}
	else {
		while (son) {
			if (layer % 2 == 0) {
				if (X1 < son->element1) {
					fater = son;
					son = son->left;
				}
				else if (X1 > t->element1) {
					fater = son;
					son = son->right;
				}
				else
					return t;
			}
			else {
 
				if (X2 < son->element2) {
					fater = son;
					son = son->left;
				}
				else if (X2 > son->element2) {
					fater = son;
					son = son->right;
				}
				else {
					return t;
				}
 
			}
			layer++;
		}
		son = newNode(X1, X2);
		if (fater) {
			if (layer % 2 == 0) {//爸爸比较的是奇数
				if (X2 < fater->element2)
					fater->left = son;
				else
					fater->right = son;
			}
			else {
				if (X1 < fater->element1)
					fater->left = son;
				else
					fater->right = son;
			}
		}
	}
 
 
	return t;//两种情况
}
 
void dir(TwoDTree t) {
	if (t) {
		dir(t->left);
		std::cout << t->element1 << " " << t->element2 << std::endl;
		dir(t->right);
	}
}
 
void printSelect(ElementType low1, ElementType high1, ElementType low2, ElementType high2, TwoDTree t) {
	if (t) {
		if (low1 <= t->element1&&low2 <= t->element2)
			printSelect(low1, high1, low2, high2,t->left);
		if(low1 <= t->element1&&t->element1<=high1&&low2 <= t->element2&&t->element2 <= high2)
			std::cout << t->element1 << " " << t->element2 << std::endl;
		if (t->element1 <= high1&&t->element2 <= high2)
			printSelect(low1, high1, low2, high2, t->right);
	}
}
#include"2-d_tree.h"
#include<iostream>
 
int main() {
	
	TwoDTree t = NULL;
 
	t = insert("Harry", "Truman", t);
	t = insert("Dwight", "Eisenhower", t);
	t = insert("John", "Kennedy", t);
	t = insert("Lyndon", "Johnson", t);
	t = insert("Richard", "Nixon", t);
	t = insert("Gerald", "Ford", t);
	t = insert("Jimmy", "Carter", t);
	t = insert("Ronald", "Reagan", t);
	t = insert("George", "Bush", t);
	t = insert("Bill", "Clinton", t);
	//dir(t);
	printSelect("A", "Z", "A", "Z", t);
	
	
}
