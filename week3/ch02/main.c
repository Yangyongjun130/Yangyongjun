  #include<stdio.h>
#include<stdlib.h>
#define MaxSize 5000
typedef int ElementType;
typedef struct TreeNode* PriorityQueue;
PriorityQueue Merge(PriorityQueue LH1, PriorityQueue LH2);
PriorityQueue Merge1(PriorityQueue LH1, PriorityQueue LH2);
struct TreeNode
{
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};

 PriorityQueue Mergel(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left == NULL)
	{
		H1->Left = H2;
	}
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
		{
			PriorityQueue temp = H1->Left;
			H1->Left = H1->Right;
			H1->Right = temp;
			H1->Npl = H1->Right->Npl + 1;
		}
	}
	return H1;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
	{
		return H2;
	}
	if (H2 == NULL)
	{
		return H1;
	}
	if (H1->Element < H2->Element)
	{
		return Mergel(H1, H2);
	}
	else
	{
		return Mergel(H2, H1);
	}
}


void insert(PriorityQueue LH, ElementType x)
{
	TreeNode* p ;  
	p = (TreeNode*)malloc(sizeof(TreeNode));// 申请一个单节点用于储存x的值
	p->Element = x;
	p->Left = p->Right = nullptr;
	p->Npl = 0;
	LH = Merge(LH, p);              // 合并LH与p，这里把单节点看成一个树
}


int IsEmpty(PriorityQueue H)
{
	if (H == NULL)
		return 0;
	else
		return 1;
}
PriorityQueue Initialize()
{
	return NULL;
}
PriorityQueue DeleteMinl(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;
	ElementType tmp;
	if (IsEmpty(H))
	{
		printf("Priority queue is empty");
		return H;
	}
	LeftHeap = H->Left;
	RightHeap = H->Right;
	tmp = H->Element;
	free(H);
	return Merge(LeftHeap, RightHeap);
	printf("%d", tmp);
}

ElementType FindMin(PriorityQueue H)
{
	if (!IsEmpty(H))
		return H->Element;
	printf("Priority queue is empty");
	return 0;
}

#define MaxSize 5000

int main()
{
	PriorityQueue H;	
	const int arr[] = { 9,8,7,6,5,4,3,2,1 };

	H = Initialize();
	for (int i = 0; i<9; i++)
	{
		insert(H,arr[i]);
	}
	DeleteMinl(H);
	system("Pause");
	return 0;
}
