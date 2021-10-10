#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

typedef int ElementType;
typedef struct TreeNode* PtrToNode;

typedef struct AvlTreeNode //avl结点声明
{
	ElementType Element;
	struct AvlTreeNode* lchild;
	struct AvlTreeNode* rchild;
	int height;//比二叉树多一个深度
}AVLTNODE, * AvlTree;

void preorder( AvlTree T)
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

static int Height(AvlTree T)
{
	if (T==NULL)
	{
		return -1;
	}
	else
	{
		return T->height;
	}
}
int   Max(int a, int b)
{
	if (a == b)
	{
		return a;

	}
	if (a < b) {
		return b;
	}
	if (a > b) {
		return a;
	}
}
static AvlTree SingleRotateLeft(AvlTree k1)
{
	AvlTree k2;

	k2 = k1->lchild;
	k1->lchild = k2->rchild;
	k2->rchild = k1;

	k1->height = Max(Height(k1->rchild), Height(k1->lchild)) + 1;
	k2->height = Max(Height(k2->rchild), Height(k2->lchild)) + 1;
	return k2;
}

/*AVL树右单旋转*/
static AvlTree SingleRotateRight(AvlTree k1)
{
	AvlTree k2;

	k2 = k1->rchild;
	k1->rchild = k2->lchild;
	k2->lchild = k1;

	k1->height = Max(Height(k1->rchild), Height(k1->lchild)) + 1;
	k2->height = Max(Height(k2->rchild), Height(k2->lchild)) + 1;
	return k2;
}

/*AVL树左双旋转*/
static AvlTree DoubleRotateLeft(AvlTree k1)
{
	k1 = SingleRotateRight(k1->lchild);
	return SingleRotateLeft(k1);
}

/*AVL树右双旋转*/
static AvlTree DoubleRotateRight(AvlTree k1)
{
	k1 = SingleRotateLeft(k1->rchild);
	return SingleRotateRight(k1);
}

AvlTree insert(AvlTree* T, ElementType X)
{
	if (*T == NULL)
	{
		*T = (AvlTree)malloc(sizeof(AVLTNODE));//如果是空的，申请一个新的根节点；
		if (!*T)
		{
			return NULL;
		}

		(*T)->Element = X;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->height = 0;
	}
	else
		if (X < (*T)->Element)
		{
			(*T)->lchild =insert(&(*T)->lchild,X);
		}
	if (Height((*T)->lchild) - Height((*T)->rchild) == 2)			//如果左右两边子树的深度超过二，则avl特性被破坏
	{
		if (X < (*T)->lchild->Element)				//属于 上面四种情况中的第一个，只需要一次旋转
		{
			*T = SingleRotateLeft(*T);
		}
		else
		{
			*T = DoubleRotateLeft(*T);		//第二个情况 双旋转
		}
	}
	
	 if (X > (*T)->Element)			//反之 右面，操作和左面相反而已
	{

	(*T)->rchild =	insert(&(*T)->rchild, X);
	if (Height((*T)->rchild) - Height((*T)->lchild) == 2)
	{
		if (X > (*T)->rchild->Element)
		{
			*T = SingleRotateRight(*T);
		}
		else
		{
			*T = DoubleRotateRight(*T);
		}
	}
	}

	(*T)->height = Max(Height((*T)->rchild), Height((*T)->lchild)) + 1;		//深度加1
	return *T;
}

int main()
{
	AvlTree T = NULL;
	int i = 0;
	for (i = 10; i >= 1; i--)
	{
		insert(&T, i);
	}
	preorder(T);
	return 0;
}
