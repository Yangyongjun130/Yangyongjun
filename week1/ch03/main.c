#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;//数据域
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
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//创建节点 
struct Node* createNode(int data)//相对于链表需要申请一个数据域；
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct Node*Intersection(struct Node*List1, struct Node* List2,struct Node*s)
{
	
	struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
	newNode1 = List1->next;
	while (newNode1)
	{

		newNode2 = List2->next;
		while (newNode2)
		{
			if (newNode1->data == newNode2->data)
			{
				struct Node* inter = (struct Node*)malloc(sizeof(struct Node));
				
				inter->data = newNode2->data;
				inter->next = s->next;
				s->next = inter;
			}
			newNode2 = newNode2->next;
		}
		newNode1 = newNode1->next;
	}

	return s;
}
void insertNodeByHead(struct Node* headNode, int Element)// 需要声明插入哪一个链表头结点，插入的数据是什么
{
	//首先创建一个插入的节点
	struct Node* newNode = creatNode(Element);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void printList(struct Node* headNode)//打印方法
{
	struct Node* pmove = headNode->next;
	while (pmove != NULL)
	{
		printf(" % d", pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
}
//求并集
struct Node* Union(struct Node* List1, struct Node* List2, struct Node* m)
{
	struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
	newNode1 = List1->next;
	newNode2 = List2->next;
	while (newNode1)
	{
		struct Node* inter = (struct Node*)malloc(sizeof(struct Node));
		inter->data = newNode1->data;
		inter->next = m->next;
		m->next = inter;
		newNode1 = newNode1->next;
	}
	while (newNode2)
	{
		newNode1 = m->next;
		while (newNode1)
		{
			if (newNode1->data != newNode2->data)
			{
				struct Node* inter = (struct Node*)malloc(sizeof(struct Node));
				inter->data = newNode2->data;
				inter->next = m->next;
				m->next = inter;
				newNode1 = newNode1->next;
				
			}
			else
			{
				break;
			}
			newNode2 = newNode2->next;
		}
		
		return m;
	}
};

int main()
{
	struct Node* List1 = createList();
	insertNodeByHead(List1, 1);
	insertNodeByHead(List1, 2);
	insertNodeByHead(List1, 3);
	struct Node* List2 = createList();
	insertNodeByHead(List2, 1);
	insertNodeByHead(List2, 2); 
	insertNodeByHead(List2, 3);
	insertNodeByHead(List2, 4); 
	insertNodeByHead(List2, 5);
	struct Node* s = createList();
	Intersection(List1, List2,s);
	printList(s);
	struct Node* m = createList();
	Union(List1, List2, m);
	printList(m);
}
