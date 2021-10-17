//优先队列的实现以及相关操作
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType ;
typedef struct HeapStruct* PriorityQueue;

struct HeapStruct {
	int Capacity;
	int size;
	ElementType* Elements;
};
PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if (MaxElements < 0)
	{
		printf("Priority quewe size is too small");
	}
	H =(PriorityQueue) malloc(sizeof(struct HeapStruct));
	if (H == NULL)
	{
		printf("Out of space");
	}
	H->Elements =(ElementType *)malloc(sizeof(ElementType)*(MaxElements + 1));
	if (H->Elements == NULL)
	{
		printf("Out of space");
	}
	H->Capacity = MaxElements;
	H->size = 0;
	H->Elements[0] = NULL;
	return H;
}
int IsFull(PriorityQueue H)
{
		if (H == NULL)
			return 0;
		if (H->size == H->Capacity)
			return 1;
		else
			return 0;
}
void Insert(ElementType X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		printf("Priority queue if full");
		return;
	}
	for (i = ++H->size; H->Elements[i / 2] > X; i /= 2)
	{
		H->Elements[i] = H->Elements[i / 2];
	}
	H->Elements[i] = X;
}
ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsFull(H))
	{
		printf("Priority queue is full");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->size--];
	for (i = 1; i * 2 <= H->size; i = Child)
	{
		Child = i * 2;
		if (Child != H->size && H->Elements[Child + 1] < H->Elements[Child])
		{
			Child++;
		}
		if (LastElement > H->Elements[Child])
		{
			H->Elements[i] = H->Elements[Child];
		}
		else
		{
			break;
		}
	}
	H->Elements[i] = LastElement;
	return MinElement;
}
void
percolateDown(int* arr, int len, int i)
{
	int n = len - 1;
	int tmp;
	if (i * 2 == n && arr[i] > arr[n]) // 只有左儿子的节点，并且左儿子比本节点的值要小，交换
	{
		tmp = arr[i];
		arr[i] = arr[n];
		arr[n] = tmp;
	}
	else // 有两个儿子的节点
	{
		if (arr[i * 2] > arr[i * 2 + 1]) // 右儿子较小
		{
			if (arr[i] > arr[i * 2 + 1]) // 如果本节点比右儿子大，交换
			{
				tmp = arr[i];
				arr[i] = arr[i * 2 + 1];
				arr[i * 2 + 1] = tmp;
			}
		}
		else // 左儿子较小
		{
			if (arr[i] > arr[i * 2]) // 如果本节点比左儿子大，交换
			{
				tmp = arr[i];
				arr[i] = arr[i * 2];
				arr[i * 2] = tmp;
			}
		}
	}
}
PriorityQueue Percolate(int* arr, int n)
{
	if (arr == NULL)
	{
		printf("Error: Array is NULL");
		return NULL;
	}

	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (H == NULL)
	{
		printf("H is empty");
	}
	ElementType* elements =(ElementType *) malloc(sizeof(ElementType) * (n + 1));
	if (elements == NULL)
	{
		printf("elements is empty");
	}
	int i;
	for (i = 1; i <= n; i++)
	{
		elements[i] = arr[i - 1];
	}

	for (i = n / 2; i > 0; i--)
	{
		percolateDown(elements, n + 1, i);
	}
	H->Elements = elements;
	H->size = n;
	H->Capacity = n * 2;

	return H;
}

PriorityQueue insert(int* arr, int n)
{
	PriorityQueue H;

	if (arr == NULL)
	{
		printf("Array is NULL, fail to build heap");
		return NULL;
	}

	H = Initialize(n * 2);
	for (int i = 0; i < n; i++)
		Insert(arr[i],H);
	return H;
}
void
printMinPriorityQueue(PriorityQueue H)
{
	if (H == NULL)
	{
		printf("H is empty");
		return;
	}

	if (H->Elements == NULL)
	{
		printf("Fail to print: Elements of priority queue is NULL");
		return;
	}

	if (IsFull(H))
	{
		printf("Empty Prioirty H\n");
		return;
	}

	printf("Priority H\n");
	for (int i = 1; i <=H->size; i++)
		printf("Element[%d] = %d\n", i,H->Elements[i]);
	printf("\n");
}
int main()
{
	int a[5] = { 5 , 4 , 3 , 2 , 1 };
	PriorityQueue pqueue_ins = insert(a, 5);
	PriorityQueue pqueue_per = Percolate(a, 5);
	printMinPriorityQueue(pqueue_ins);
	printMinPriorityQueue(pqueue_per);
	return 0;
}
