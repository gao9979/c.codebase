#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
struct Node
{
    DataType data;//数据域
    struct Node*next;    //指针域
};
typedef struct Node Node;//先定义Node,把struct Node叫做Node后续不用再struct
typedef struct Node*LinkList;
//1.初始化，创建头结点
Node*InitList()
{
    Node *head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    return head;
}
//2.头插法
void CreatHead_LinkList(LinkList P,int n)
{
    Node *s;
    int i;
    for(i=0;i<n;i++)
    {
        s=(Node*)malloc(sizeof(Node));
        printf("请输入第%d个元素的值:",i+1);
        scanf("%d",&s->data);
        s->next = P->next;  //新结点指向原来第一个数据结点
        P->next = s;        //头结点指向新结点
    }
}
//3.尾插法
void CreateTail_LinkList(LinkList P,int n)
{
    Node*s,*r=P;
    int i;
    for(i=0;i<n;i++)
    {
        s=(Node*)malloc(sizeof(Node));
        printf("请输入第%d个元素的值:",i+1);
        scanf("%d",&s->data);
        s->next=NULL;
        r->next=s;
        r=s;
    }
}
//4.判断链表是否为空
int IsEmpty(LinkList P)
{
    if(P->next==NULL)
     return 1;
    else 
     return 0;
}
//5.计算链表长度
int ListLength(LinkList P)
{
    int len=0;
    Node *t=P->next;
    while(t!=NULL)
    {
        len++;
        t=t->next;
    }
    return len;
}
//6.输出链表
void PrintList(LinkList P)
{
    Node*t=P->next;
    if(t==NULL)
    {
        printf("链表为空\n");
        return;
    }
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
//主函数
int main()
{
    int n;
    //头插法
    printf("头插法建立链表:");
    printf("请输入元素个数:");
    scanf("%d",&n);
    LinkList P1=InitList();
    CreatHead_LinkList(P1,n);
    printf("头插法链表:");
    PrintList(P1);
    printf("链表是否为空:%d",IsEmpty(P1));
    printf("链表长度=%d",ListLength(P1));
    //尾插法
    printf("尾插法建立链表:");
    printf("请输入元素个数:");
    scanf("%d",&n);
    LinkList P2=InitList();
    CreateTail_LinkList(P2,n);
    printf("尾插法链表:");
    PrintList(P2);
    printf("链表是否为空:%d",IsEmpty(P2));
    printf("链表长度:%d",ListLength(P2));
    return 0;
}