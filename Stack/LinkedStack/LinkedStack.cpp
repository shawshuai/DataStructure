#include "pch.h"
#include <iostream>

typedef struct linknode
{
	int data;
	struct linknode *next;
}LinkStNode;

void InitStack(LinkStNode *&s);
void DestroyStack(LinkStNode *&s);
bool StackEmpty(LinkStNode *s);
void Push(LinkStNode *&s, int e);
bool Pop(LinkStNode *&s, int &e);
bool GetTop(LinkStNode *s, int &e);

int main(void)
{
	int stackLength;
	int inElem;
	int outElem = 0;
	int topElem;
	LinkStNode *stack;

	InitStack(stack);
	printf("请输入要创建的链栈的元素个数：");
	scanf_s("%d", &stackLength);
	printf("请输入元素（每行一个）：\n");
	for (int i = 0; i < stackLength; i++)
	{
		scanf_s("%d", &inElem);
		Push(stack, inElem);
	}
	printf("该栈是空栈吗？%d\n", StackEmpty(stack));
	GetTop(stack, topElem);
	printf("该栈的栈顶元素是：%d\n", topElem);
	printf("出栈：\n");
	for (int i = 0; i < stackLength; i++)
	{
		Pop(stack, outElem);
		printf("%3d", outElem);
	}
	DestroyStack(stack);
	printf("\n该链栈已销毁，程序运行结束，按任意键退出");
	return 0;
}

//初始化栈
void InitStack(LinkStNode *&s)
{
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//销毁栈
void DestroyStack(LinkStNode *&s)
{
	LinkStNode *pre = s, *p = s->next;
	while (p != NULL)
	{
		free(p);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
//判断栈是否为空
bool StackEmpty(LinkStNode *s)
{
	return(s->next == NULL);
}
//进栈
void Push(LinkStNode *&s, int e)
{
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//出栈
bool Pop(LinkStNode *&s, int &e)
{
	LinkStNode *p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
//取栈顶元素
bool GetTop(LinkStNode *s, int &e)
{
	if (s->next == NULL)
	{
		return false;
	}
	e = s->next->data;
	return true;
}