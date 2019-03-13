//整形链表的建立和遍历操作    一旦需要变化就需要临时指针，遍历是必然需要的，创建如果动态，创建也需要临时指针
#include <stdio.h>
#include <stdlib.h>


typedef struct Node				//声明链表节点数据域和指针域 
{
	int data;
	struct Node * pNext;
}*pNODE, NODE;					//声明链表节点名 和 指针名 

pNODE create_list(int n);		//声明创建链表函数  返回为头结点的地址 
void traverse_list(pNODE p);	//声明遍历链表函数 	对头结点指向的链表进行遍历 

int main()
{
	int n;
	printf("请输入链表长度：");	//等待用户输入链表长度 
	scanf("%d", &n);
	
	pNODE p = create_list(n);	//根据长度建链表 
	
	traverse_list(p);			// 遍历建好的链表 
	
	return 0;					//程序结束返回 
}

pNODE create_list(int n)
{
	pNODE pHead = (pNODE)malloc(sizeof(NODE));	//头节点指针 
	if(pHead == NULL)
		exit(-1);
	pNODE p = pHead;			//临时指针，变化方便处理 
	p->pNext = NULL;			//头结点指针域置空，防止访问非法内存 
	int i, val;
	for(i=0;i<n;i++)
	{
		pNODE pNew = (pNODE)malloc(sizeof(NODE));	//新节点建立 
		if(pNew == NULL)							//新节点失败则终止 
			exit(-1);
		p->pNext = pNew;							//新节点挂接链尾 
		printf("请输入第%d个元素", i+1);			
		scanf("%d",&val);							//输入元素值 
		pNew->data = val;							//元素值存入新节点的数据域 
		pNew->pNext = NULL;					//新节点指针域置空，避免操作非法内存 
		p = pNew;							//临时指针指向新节点					
	}
	return pHead;							//返回头结点地址 
}

void traverse_list(pNODE p)
{	pNODE m = p;							//临时指针m指向头结点 

	if(NULL == m->pNext)					//头结点指针域为空，则输出空表 
		printf("空表\n");
	else									//头结点指针域不为空，开始取值 
	{	do
		{
		m = m->pNext;						//临时指针指向链表下一个节点 
		printf("%d ", m->data);				//取出新节点的数据域内存放元素 
		}while(NULL != m->pNext);			//未到链末，返回继续 
	}
	printf("\n");							//输出美观，可无 
}
