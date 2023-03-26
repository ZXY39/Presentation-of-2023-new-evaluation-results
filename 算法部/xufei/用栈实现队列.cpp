#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
#define ElemType int
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SeqStack;
void InitStack(SeqStack *s){
    s->top=-1;
}
bool StackEmpty(SeqStack &s){
    if(s.top==-1)
        return true;
    return false;
}
bool Push(SeqStack &s,ElemType e){
    if(s.top==MAXSIZE-1)
        return false;
    s.data[++(s.top)]=e;
    return true;
}
bool Pop(SeqStack &s,ElemType &e){
    if(s.top==-1)
        return false;
    e=s.data[(s.top)--];
    return true;
}
bool GetTop(SeqStack &s,ElemType &e){
    if(s.top==-1)
        return false;
    e=s.data[s.top];
    return true;
}
void check(bool flag){
    if(flag)
        printf("�����ɹ�!\n");
    else
        printf("����ʧ�ܣ�\n");
}
void display(SeqStack &s){
    int index=s.top;
    while(index>-1){
        printf("%d ",s.data[index--]);
    }
    printf("\n");
    if(index==s.top)
        printf("����Ԫ��Ϊ�գ�");
}
int main(){
    int n;
    //ջ�ĳ�ʼ��
    SeqStack s,s2;
    printf("˳��ջ�Ļ�������\n");
    printf("ջ1�ĳ�ʼ��\n");
    InitStack(&s);
    printf("ջ1�ĳ�ʼ��\n");
    InitStack(&s2);
    printf("ģ�����\n");
    while(1){
        int op;
        int e;
        bool flag;
        printf("��ѡ�����\n1.������\n2.������\n3.�п�\n4.��ȡ����ͷ��Ԫ��\n5.��ӡ����������Ԫ��\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("�����Ԫ�أ�");
            scanf("%d",&e);
            flag=Push(s,e);
            check(flag);
            if(!StackEmpty(s)&&!StackEmpty(s2)){
                //���ջ2Ԫ�ػ�û����ʱ����ջ1������Ԫ��ʱ��
                //Ϊ�˱�֤���е������ԣ�������ǰ������Ԫ�س�ջ2
                printf("���ջ2����Ԫ�أ�\n");
                while(!StackEmpty(s2)){
                    flag=Pop(s2,e);
                    if(flag)
                        printf("����ͷ��Ԫ�س����У�������Ԫ��Ϊ��%d\n",e);
                }
            }
            break;
        case 2:
            while(!StackEmpty(s)){
                Pop(s,e);
                Push(s2,e);
            }
            flag=Pop(s2,e);
            check(flag);
            if(flag)
                printf("����ͷ��Ԫ�س����У�������Ԫ��Ϊ��%d\n",e);
            break;
        case 3:
            flag=StackEmpty(s2);
            if(StackEmpty(s)&&StackEmpty(s2))
                printf("����Ϊ�գ�\n");
            else
                printf("���зǿգ�\n");
            break;
        case 4:
            while(!StackEmpty(s)){
                Pop(s,e);
                Push(s2,e);
            }
            flag=GetTop(s2,e);
            check(flag);
            if(flag)
                printf("����ͷ��Ԫ��Ϊ��%d\n",e);
            break;
        case 5:
            while(!StackEmpty(s)){
                Pop(s,e);
                Push(s2,e);
            }
            display(s2);
        default:
            break;
        }
    }

    return 0;
}


