#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;//数据域
	struct Node* next;//指针域
};
struct stack {
	struct Node* stackTop;//栈顶	
	int size;//栈中元素个数
};
//创建栈
struct stack* createStack() 
{
	struct stack* myStack = (struct stack*)malloc(sizeof(struct stack));
	myStack->stackTop = NULL;
	myStack->size = 0;
	return myStack;
	
}
//创建节点 （入栈）
struct Node* createNode(int data)//相对于链表需要申请一个数据域；
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//入栈
void push(struct stack*myStack,int data)
{
	struct Node* newNode = createNode(data);
	//入栈操作相当于进行头插法
	newNode->next = myStack->stackTop;
	myStack->stackTop = newNode;
	myStack->size++;

}
//获取栈顶元素
int top(struct stack* myStack)
{
	if (myStack->size == 0)
	{
		printf("空");
	}
	return myStack->stackTop->data;

}
//出栈
void pop(struct stack*myStack)
{
	struct Node* nextNode =myStack->stackTop->next;
	free(myStack->stackTop);
	myStack->stackTop = nextNode;
	myStack->size--;
}
int empty(struct stack* myStack)
{
	if (myStack->size == 0)
	{
		return 0;
	}
	return 1;

}
int main()
{
	struct stack* myStack = createStack();
	push(myStack, 1);
	push(myStack, 2);
	push(myStack, 3);
	while (empty(myStack))
	{
		printf("%d\n", top(myStack));
		pop(myStack);
	}
	return 0;
}
