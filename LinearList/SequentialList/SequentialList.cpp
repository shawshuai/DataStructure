#include "pch.h"
#include <stdlib.h>
#include <iostream>
constexpr auto MaxSize = 100;;

//定义SqList结构体
typedef struct
{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList *&L);
void CreateList(SqList *&L, int a[], int n);
void DistroyList(SqList *&L);
bool ListEmpty(SqList *L);
int ListLength(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList *L, int i, int &e);
int LocateElem(SqList *L, int e);
bool ListInsert(SqList *&L, int i, int e);
bool ListDelete(SqList *&L, int i, int &e);

int main(void)
{
	SqList *list;  
	int SqlistLength; //变量，用户输入，要创建的顺序表的长度
	int sqlist[MaxSize];  //数组，用户输入，要创建的顺序表的每一个元素的值
	int searchNum;  //变量，用户输入，想要查找的元素的编号
	int e = 0;  //变量，程序输出，编号为searchNum的元素的值
	int insertLocation;  //变量，用户输入，想要插入新元素在顺序表中的位置
	int insertValue;  //变量，用户输入，想要插入的新元素的值
	int delLocation;  //变量，用户输入，想要删除元素在顺序表中的位置
	int delValue = 0;  //变量，，想要删除元素的值

	InitList(list);

    //接受用户输入要创建的顺序表的长度和每个元素的内容
		printf("请输入您要创建的顺序表的长度：\n");
		scanf_s("%d", &SqlistLength);
		printf("请输入您创建的顺序表的每个元素值，每行一个：\n");
		for (int i = 0; i < SqlistLength; i++)
		{
			scanf_s("%d", &sqlist[i]);
		}
		
	CreateList(list, sqlist, SqlistLength);
	//输出创建、初始化完成的顺序表
	printf("你创建的顺序表是：");
	DispList(list);
	printf("该顺序表是空表吗？%d\n", ListEmpty(list)); //判断该顺序表是否为空表并输出结果
	printf("该顺序表的长度是：%d\n",ListLength(list)); //计算该顺序表的长度并输出结果
	//接收用户输入，并查找对应编号的元素
	printf("请输入你要查找的元素的编号：");
		scanf_s("%d",&searchNum);
	GetElem(list, searchNum, e);
	printf("你要查询的编号为%d的元素在该顺序表中的值是：%d\n", searchNum, e);
	//接收用户输入，并将输入的元素插入到顺序表对应的位置上
	printf("请输入你想要插入元素的位置：");
	scanf_s("%d", &insertLocation);
	printf("请输入你想要插入的新元素的值：");
	scanf_s("%d", &insertValue);
	if (ListInsert(list, insertLocation, insertValue)) {
		//如果元素插入成功则输出消息并显示插入后的新顺序表
		printf("元素插入成功！新顺序表是：");
		DispList(list);
	}
	else {
		//如果元素插入失败则输出失败提示消息
		printf("元素插入失败！");
	}
	//接受用户输入，删除输入位置的元素
	printf("请输入你想要删除元素的位置：");
	scanf_s("%d", &delLocation);
	if (ListDelete(list, delLocation, delValue)) {
		//如果元素删除成功则输出消息并显示删除后的新顺序表
		printf("元素删除成功！新顺序表是：");
		DispList(list);
	}
	else
	{
		//如果元素删除失败则输出失败提示消息
		printf("元素删除失败！");
	}
	//销毁顺序表并提示
	DistroyList(list);
	printf("顺序表已销毁，程序运行结束！请按任意键退出。");
}

//建立顺序表函数 CreateList
void CreateList(SqList *&L, int a[], int n) {
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));
	while (i < n) {
		L->data[k] = a[i];
		k++;   i++;
	}
	L->length = k;
}

//初始化线性表
void InitList(SqList *&L) {
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

//销毁线性表
void DistroyList(SqList *&L) {
	free(L);
}

//判断线性表是否为空表
bool  ListEmpty(SqList *L) {
	return (L->length == 0);
}

//求线性表的长度
int ListLength(SqList *L) {
	return (L->length);
}

//输出线性表
void DispList(SqList *L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d", L->data[i]);
	}
	printf("\n");
}

//求线性表中的某个数据元素值
bool GetElem(SqList *L, int i, int &e) {
	if (i<1 || i>L->length)
	{
		return false;
	}
	e = L->data[i - 1];
	return true;
}

//按元素值查找
int LocateElem(SqList *L, int e) {
	int i = 0;
	while (i<L->length && L->data[i] != e)
		i++;
	if (i>=L->length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

//插入数据元素
bool ListInsert(SqList *&L, int i, int e) {
	int j;
	if (i<1||i>L->length+1)
	{
		return false;
	}
	i--;
	for (j = L->length; j > i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
		L->data[i] = e;
		L->length++;
		return true;
}

//删除数据元素
bool ListDelete(SqList *&L, int i, int &e) {
	int j;
	if (i < 1 || i > L->length)
		return false;
	i--;
	e = L->data[i];
	for ( j = i; j < L->length-1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}