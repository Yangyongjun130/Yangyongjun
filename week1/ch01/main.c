#include <stdio.h>
#include <stdlib.h>//malloc函数
struct Node
{
	int Element;//数据域
	struct Node* next;//指针域 
};
struct Node* createList()//创建一个链表
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;//hradNode的数据域可以定义也可以不定义；
	return headNode;
}
struct Node* creatNode(int data)//相对于链表需要申请一个数据域；
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Element = data;
	newNode->next = NULL;
	return newNode;
}
//查找方法
struct Node*FindNode(struct Node*headNode,int posElement)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("出现错误\n");
	while (posNode->Element != posElement)
	{
		posNodeFront = posNode;
		posNode = posNode->next;
		if (posNode == NULL)
		{
			printf("出现错误\n");
		}

	}
	return posNode;
}
//打印方法
void printList(struct Node* headNode)
{
	struct Node* pmove = headNode->next;
	while (pmove != NULL)
	{
		printf(" % d", pmove->Element);
		pmove = pmove->next;
	}
	printf("\n");
}

//头插法 
void insertNodeByHead(struct Node* headNode, int Element)// 需要声明插入哪一个链表头结点，插入的数据是什么
{
	//首先创建一个插入的节点
	struct Node* newNode = creatNode(Element);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
//任意位置插入
void insertNodeEver(int posElement, struct Node* headNode,int goalElement)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Element = posElement;
	newNode->next = NULL;	//申请一个新的结点
	if(newNode==NULL)
	{
		printf("出现错误");
	}
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("出现错误\n");
	while (posNode->Element != goalElement)
	{
		posNodeFront = posNode;
		posNode = posNode->next;
		if (posNode == NULL)
		{
			printf("出现错误\n");
		}

	}
	
	
	newNode-> next= posNode->next;
	posNode->next = newNode;

}
//删除法 指定位置的删除
void deleteNodeByHead(struct Node* headNode, int posElement)
{

	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("无法删除\n");
	while (posNode->Element != posElement)
	{
		posNodeFront = posNode;
		posNode = posNode->next;
		if (posNode == NULL)
		{
			printf("未找到相关的信息，无法删除\n");
		}

	}//找到指定位置
	posNodeFront->next = posNode->next;
	free(posNode); ///删除临时的结点
}
int IsEmpty( struct Node* headNode)//判断是不是空表
{
	return headNode->next == NULL;
}
int IsLast(int posElement, struct Node* headNode)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("出现错误\n");
	while (posNode->Element != posElement)
	{
		posNodeFront = posNode;
		posNode = posNode->next;
		if (posNode == NULL)
		{
			printf("出现错误\n");
		}

	}
	return posNode->next == NULL;
}
int main()
{
	struct Node* List = createList();
	insertNodeByHead(List, 1);
	insertNodeByHead(List, 2);
	insertNodeByHead(List, 3);
	printList(List);
	deleteNodeByHead(List, 2);
	printList(List);
	insertNodeEver(5, List, 3);
	printList(List);
	if (IsEmpty(List))//判断是不是空表
	{
		printf("该表是一个空表\n");
	}
	else
	{
		printf("该表不是一个空表\n");
	}
	if(IsLast(3,List))
	{
		printf("该位置是链表的结尾\n");
	}
	else
	{
		printf("该位置是链表的结尾\n");
	}
	if (FindNode(List, 5))
	{
		printf("已经查找到您要找的位置");
	}
	return 0;	
}
