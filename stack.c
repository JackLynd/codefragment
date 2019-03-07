#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

typedef struct Node
{
	int data;
	struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK);			//初始化
void push(PSTACK, int); 	//压栈
void traverse(PSTACK);		//遍历
int pop(PSTACK, int *);		//出栈

int main(void)
{
	STACK S;		//创建变量S，搭建栈顶栈尾 
	int val;
	
	init(&S); 		//插入空栈 
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	traverse(&S); 	//遍历输出
 	
	if(pop(&S, &val))
	printf("出栈成功,删除元素为%d\n栈内剩余元素为\n", val);
	else
	printf("出栈失败\n"); 
	
	traverse(&S); 
	return 0;	
}

void init(PSTACK p)
{
	p->pTop = (PNODE)malloc(sizeof(NODE));
	p->pBottom = p->pTop;
	p->pTop->pNext = NULL;		//避免访问未知内存 
} 

void push(PSTACK p, int val)
{
	PNODE m = (PNODE)malloc(sizeof(NODE)); //新节点 
	m->data = val;							//数据域赋值 
	m->pNext = p->pTop;						//指针域挂接当前栈顶 
	p->pTop = m;							//栈顶指针移动至新栈顶 
 
	
	
}

void traverse(PSTACK p)
{	
	PNODE u=p->pTop;
	while(u != p->pBottom)
	 {
	 	printf("%d ", u->data);
	  	u = u->pNext;
	 } 
	 printf("\ndone\n");
	 
}

int pop(PSTACK p, int * pval)
{
	PNODE r = (PNODE)malloc(sizeof(NODE));
	r = p->pTop; 
	if(r == p->pBottom)
	return 0;
	else
	{
		*pval = r->data;
		p->pTop = p->pTop->pNext;
		free(r);
		return 1;
	}
	
}