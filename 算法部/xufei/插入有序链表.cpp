#include "stdio.h"
#include "malloc.h"   /*������̬�����ڴ溯��*/
#define TRUE 1
#define FALSE 0

typedef int elemtype;
typedef struct node   /*���������Ͷ���*/
 {elemtype data;      /*���������*/
  struct node *next;  /*����ָ����*/
 }linklist;

 linklist *creatlist() 
 {			            
  int x;
  linklist *head,*r,*p;
  p=(linklist*)malloc(sizeof(linklist));
  head=p;
  p->next=NULL;
  r=p;
  scanf("%d",&x);
  while(x!=-1)
   {
    p=(linklist*)malloc(sizeof(linklist));
    p->data=x;
    p->next=NULL;
    r->next=p;
    r=r->next;
    scanf("%d",&x);
   }
  return (head);
  }

 /*�벹���·��ĺ�����������ʵ��������еĲ�������*/
   void order_insert(linklist *head,elemtype x)
   {
   linklist *p,*q,*s;
   q=head;
   p=head->next;
   while(p!=NULL)
   if(p->data<x)
   {q=p;
   p=p->next;}
   else break;
   
   s=(linklist*)malloc(sizeof(linklist));
   s->data=x;
  q->next=s;
  s->next=p;
   }

  void print(linklist *head)  /*��ӡ������head�и�������ֵ*/
  {linklist *p;
  p=head->next;
  while(p!=NULL)
  {printf("%d ",p->data);
   p=p->next;
  }
  printf("\n");
  }

 int main() /*������*/
 {linklist *head;  /*����ָ�������ָ��head*/
  int x;
  printf("please input the linklist and end by -1:\n");
  head=creatlist();
  print(head);
  printf("now start insert,please input the insert value:\n");
  scanf("%d",&x);
  
  order_insert(head,x);
  print(head);
  return 0;
  }

