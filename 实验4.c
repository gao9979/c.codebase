#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Stack
{
    int top;  //栈顶指针，指向栈顶元素的下标
    int maxsize;//顺序栈的最大空间
    DataType*elements;//存放顺序栈的栈元素
}SqStack;
void InitStack(SqStack*s,int size)
{
    s->maxsize=size;
    s->elements=(DataType*)malloc(sizeof(DataType)*size);
    s->top=-1;//标记空栈
}
int StackEmpty(SqStack*s)
//若栈为空则返回1，否则返回0
{
    if(s->top==-1)
    return 1;
    else return 0;
}
int StackFull(SqStack*s)
//若栈满则返回1，否则返回0
{
    if(s->top==s->maxsize-1)
    return 1;
    else return 0;
}
//入栈
int Push(SqStack*s,DataType e)
{
    if(StackFull(s))
    {
        printf("栈满\n");
        return 0;
    }
    s->top++;
    s->elements[s->top]=e;
    return 1;
}
//出栈
int Pop(SqStack*s,DataType*e)
{
    if(StackEmpty(s))
    {
        printf("栈空\n");
        return 0;
    }
        *e=s->elements[s->top];
        s->top--;
        return 1;
}
//获取栈顶元素
int GetTop(SqStack*s,DataType*e)
{
    if(StackEmpty(s))
    {
        printf("栈空\n");
        return 0;
    }
    *e=s->elements[s->top];
    return 1;
}
//十进制转换
void DecToBase(int number,int base)
{
    SqStack st;
    InitStack(&st,20);
    int r;
    if(number<0)
    {
        printf("-");
        number=-number;
    }
    if(number==0)
    {
        Push(&st,0);
    }
    while(number!=0)
    {
        r=number%base;
        Push(&st,r);
        number=number/base;
    }
    int t;
    while(!StackEmpty(&st))//只要栈不为空就持续输出
    {
        Pop(&st,&t);
        printf("%d",t);
    }
}
int main()
{
    SqStack s;
    DataType temp;
    InitStack(&s,10);
    Push(&s,10);
    Push(&s,15);
    Push(&s,20);
    GetTop(&s,&temp);
    printf("栈顶元素:%d\n",temp);
    Pop(&s,&temp);
    printf("出栈元素:%d\n",temp);
    GetTop(&s,&temp);
    printf("出栈后的栈顶元素:%d\n",temp);
    printf("十进制17转二进制:");
    DecToBase(17,2);
    printf("\n");
    return 0;
}