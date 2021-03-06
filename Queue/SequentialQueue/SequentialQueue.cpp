#include "pch.h"
#include <iostream>
constexpr auto MaxSize = 100;

typedef struct
{
	int data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue *&q);
void DestroyQueue(SqQueue *&q);
bool QueueEmpty(SqQueue *q);
bool enQueue(SqQueue *&q, int e);
bool deQueue(SqQueue *&q, int &e);

int main(void)
{
	int numOfQueue;
	int inElem;
	int outElem;
	SqQueue *queue;

	InitQueue(queue);
	printf("该队列为空吗？%d\n", QueueEmpty(queue));
	printf("请输入要进入队列的元素的个数：");
	scanf_s("%d", &numOfQueue);
	printf("请输入要进入队列的元素（每行一个）\n");
	for (int i = 0; i < numOfQueue; i++)
	{
		scanf_s("%d", &inElem);
		enQueue(queue, inElem);
	}
	printf("该队列为空吗？%d\n", QueueEmpty(queue));
	printf("出队列：\n");
	for (int i = 0; i < numOfQueue; i++)
	{
		deQueue(queue, outElem);
		printf("%3d",outElem);
	}
	DestroyQueue(queue);
	printf("\n该队列已销毁，程序运行结束，按任意键退出。");
}
//初始化队列
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
//销毁队列
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
//判断队列是否为空
bool QueueEmpty(SqQueue *q)
{
	return(q->front == q->rear);
}
//进队列
bool enQueue(SqQueue *&q, int e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
//出队列
bool deQueue(SqQueue *&q, int &e)
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}