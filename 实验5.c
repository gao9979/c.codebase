#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct LinkStack
{
    DataType data;// ˝æ›”Ú
    struct LinkStack*next;//÷∏’Î”Ú
}LinkStack;
//1.≥ı ºªØ
void InitStack(LinkStack**s)
{
    *s=NULL;
}
//2.≈–∂œ’ªø’
int StackEmpty(LinkStack*s)
{
    return s==NULL;
}
//3.»Î’ª
int Push(LinkStack**s,DataType e)
{
    LinkStack*p=(LinkStack*)malloc(sizeof(LinkStack));
    if(p==NULL)
    return 0;
    p->data=e;
    p->next=*s;
    *s=p;
    return 1;
}
//4.≥ˆ’ª
int Pop(LinkStack**s,DataType*e)
{
    if(StackEmpty(*s))
      return 0;
    LinkStack*p=*s;
    *e=p->data;
    *s=p->next;
    free(p);
    return 1;
}
//5.ªÒ»°’ª∂•‘™Àÿ
int GetTop(LinkStack*s,DataType*e)
{
    if(StackEmpty(s))
    return 0;
    *e=s->data;
    return 1;
}
int BracketCheck(char str[])
{
    LinkStack*st;
    InitStack(&st);
    int flag=1;
    int i=0;
    DataType t,topT;
    while(str[i]!='\0'&&flag==1)
    {
        t=str[i];
        if(t=='('||t=='['||t=='{')
        {
            Push(&st,t);
        }
        else if(t==')'||t==']'||t=='}')
        {
            if(GetTop(st,&topT))
            {
                if((t==')'&&topT=='('||t==']'&&topT=='['||t=='}'&&topT=='{'))
                {
                    Pop(&st,&topT);
                }
                else
                {flag=0;}
            }
            else
            {
                flag=0;
            }
        }
        i++;
    }
    if(flag==1&&StackEmpty(st))
      return 1;
    else
      return 0;
}
int main(void)
{
    char buf[100];
    printf("«Î ‰»Î¿®∫≈¥Æ:");
    scanf("%s",buf);
    if(BracketCheck(buf))
      printf("¿®∫≈∆•≈‰”––ß\n");
    else
      printf("¿®∫≈∆•≈‰Œﬁ–ß\n");
    return 0;
}