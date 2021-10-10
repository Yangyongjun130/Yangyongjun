//二叉查找树的例程
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

typedef int ElementType;


typedef struct SearchTreeNode //avl结点声明
{
	ElementType Element;
	struct SearchTreeNode* lchild;
	struct SearchTreeNode* rchild;
}BSTNODE, * BSTree;
//Findmin
 BSTree Findmin(BSTree T)
{
	if (T != NULL)
	{
		while (T->lchild != NULL)
			T = T->lchild;
		return T;
	}
}
 //创建新节点
 BSTNODE* createnode(ElementType X)
 {
	 BSTNODE *node = (BSTNODE*)malloc(sizeof(BSTNODE));
	 if (!node)
	 {
		 printf("申请空间失败");
	 }
	 node->Element = X;
	 node->lchild = NULL;
	 node->rchild = NULL;
	 return node;
 }
BSTree insert(BSTree *T, ElementType X)
{
	if(*T==NULL)
	{
		*T = (BSTree)malloc(sizeof(BSTNODE));
		if (!*T)
		{
			return NULL;
		}

			(*T)->Element = X;
			(*T)->lchild = NULL;
			(*T)->rchild = NULL;
	
	}
	else
		if (X < (*T)->Element)
		{
			(*T)->lchild = insert(&(*T)->lchild, X);
		}
		else
		{
			if (X >(*T)->Element)
			{
				(*T)->rchild = insert(&(*T)->rchild, X);
			}
		}
	return *T;
}
BSTree Delete(BSTree T, ElementType X)
{
	BSTree M;
	M = (BSTree)malloc(sizeof(BSTree));
	if (T == NULL)
	{
		printf("出现错误");
	}
	else
		if (X < T->Element)
		{
			T->lchild = Delete(T->lchild, X);
		}
		else
			if (X > T->Element)
			{
				T->rchild = Delete(T->lchild, X);
			}
			else
				if (T->lchild && T->rchild)
				{
					M = Findmin(T->rchild);
					T->Element = M->Element;
					T->rchild = Delete(T->rchild, T->Element);
				}
				else
				{
					M = T;
					if (T->lchild == NULL)
					{
						T = T->rchild;
					}
					else
						if (T->rchild == NULL)
					{
						T = T->lchild;
						free(M);
					}
				}
	return T;
}
void preorder(BSTree T)
{
	if (T == NULL)
	{
		return;
	}
	if (T != NULL)
	{
		printf("%d\n", T->Element);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

int main()
{
	BSTree T=NULL;
	ElementType i = 0;
	for (ElementType i=15;i>=1;i--)
	{
		int arr[20] = { 1,5,6,8,21,54,23,21,3,10,11,12,13,48,4,9};
		insert(&T, arr[i]);
	}
	preorder(T);
	Delete(T, 4);
	preorder(T);
}
