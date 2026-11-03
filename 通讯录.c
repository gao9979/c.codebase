#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node Node;
//这是一个通讯录小程序
//定义一个联系人结构体
typedef struct Contact
{
    char name[50]; //姓名
    char phonenumber[12]; //电话
    struct Birthday//生日
    {
    int year; 
    int month; 
    int day;
    }birthday;
    char sex[3]; //性别
    int age;//年龄
}Contact;
//定义链表的结构体
struct Node
{
   struct Contact data;//数据域
   struct Node*next;//指针域

};
/*函数功能：初始化一个空的通讯录
 *函数形参：
 *函数返回值：
  */
Node* InitAddressBook()
{
   Node*head=(Node*) malloc(sizeof(Node));//申请一个头节点
   if(head==NULL)
    printf("内存申请失败");
   else
    head->next=NULL;
   return head;
};
/*函数功能：输入联系人信息
 *函数形参：无
 *函数返回值：返回联系人信息，Contact类型
  */

Contact InputContact()
{
    Contact contact;//定义一个联系人结构体变量
    printf("输入姓名:");
    scanf("%s",contact.name);
    printf("输入电话:");
    scanf("%s",contact.phonenumber);
    printf("输入生日 年月日:");
    scanf("%d%d%d",&contact.birthday.year,&contact.birthday.month,&contact.birthday.day);
    printf("输入性别:");
    scanf("%s",contact.sex);
    //根据当前日期计算年纪
    contact.age=2026-contact.birthday.year;
    return contact;


};
/*函数功能：建立通讯录(头插法)
 *函数形参：通讯录的头指针Node*head,联系人信息Contact data
 *函数返回值：插入成功返回1，否则返回0，int类型
  */
int CreateAddressBookHead(Node*head, Contact data)
{
    Node*node=(Node*) malloc(sizeof(Node));
    if(node==NULL)
    {
        printf("内存分配失败\n");
        return 0;
    }
    node->data=data;//将联系人信息赋值给新节点的数据域
    node->next=head->next;//将新节点的指针域指向原来的第一个节点
    head->next=node;//将头节点的指针域指向新节点
    return 1;
}
/*函数功能：建立通讯录(尾插法)
 *函数形参：通讯录的头指针Node*head,联系人信息Contact data
 *函数返回值：插入成功返回1，否则返回0，int类型
  */
int CreateAddressBookTail(Node*head,Contact data)
{
    Node*tail=head;//定义一个尾指针，初始指向头节点
    Node*node=(Node*)malloc(sizeof(Node));
    if(node==NULL)
    {
        printf("内存分配失败:");
        return 0;
    }
    node->data=data;//将联系人信息赋值给新节点的数据域
    node->next=NULL;//将新节点的指针域置为空
    tail->next=node;//将尾节点的指针域指向新节点
    tail=node;
    return 1;
}


/*函数功能:输出单个联系人的信息
 *函数形参：联系人信息Contact data
 *函数返回值：无。void类型
  */
 void OutputContact(Contact data)
 {
    printf("姓名:%s\n",data.name);
    printf("电话:%s\n",data.phonenumber);
    printf("生日:%d-%d-%d\n",data.birthday.year,data.birthday.month,data.birthday.day);
    printf("性别:%s\n",data.sex);
    printf("年龄:%d\n",data.age);

 }
/*函数功能:输出整个通讯录联系人信息
 *函数形参：通讯录的头指针Node*head
 *函数返回值：无。void类型
  */
void OutputAddressBook(Node*head)
{
   
    Node*p=head->next;
    while(p!=NULL)//遍历整个链表
    {
        OutputContact(p->data);//输出当前节点的联系人信息
        p=p->next;
    }
}
int main()
{
     Node*head=InitAddressBook();
     int i;
     for(i=0;i<2;i++)
     {
        printf("第%d个联系人:\n",i+1);
        Contact contact=InputContact();
        CreateAddressBookHead(head,contact);
     }
    for(i=0;i<2;i++)
    {
        printf("尾插第%d个联系人:\n",i+1);
        Contact contact=InputContact();
        CreateAddressBookTail(head,contact);
    }
    for(i=0;i<2;i++)
    {
        Contact contact=InputContact();//输入联系人信息
        CreateAddressBookHead(head,contact);
    }
    OutputAddressBook(head);//输出整个通讯录
    return 0;
}