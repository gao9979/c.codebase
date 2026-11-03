#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];//存放数据的数组
    int length;            //当前顺序表长度
} SqList;

//1.初始化
void InitList(SqList *L){
    L->length = 0;
}

//2.创建顺序表
void CreateList(SqList *L, int n){
    if(n > MaxSize){
        printf("超出最大容量！\n");
        return;
    }
    L->length = n;
    printf("请输入%d个数字：", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &L->data[i]);
    }
}

//3.判空
bool IsEmpty(SqList L){
    return L.length == 0;
}
int GetLength(SqList L){
    return L.length;
}

//5.输出顺序表
void PrintList(SqList L){
    if(IsEmpty(L)){
        printf("顺序表为空\n");
        return;
    }
    for(int i = 0; i < L.length; i++){
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

//6.获取pos位置元素（位序从1开始）
bool GetElem(SqList L, int position, ElemType *e){
    if(position < 1 || position > L.length)
        return false;
    *e = L.data[position - 1];
    return true;
}

//1 顺序查找
int Search_Seq(SqList L, ElemType value){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == value){
            return i + 1;
        }
    }
    return 0;
}

//2 二分查找
int Search_Bin(SqList L, ElemType value){
    int low = 0, high = L.length - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(L.data[mid] == value)
            return mid + 1;
        else if(L.data[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

//8.插入
bool ListInsert(SqList *L, int position, ElemType x){
    if(position < 1 || position > L->length + 1 || L->length >= MaxSize)
        return false;
    for(int j = L->length; j >= position; j--){
        L->data[j] = L->data[j - 1];
    }
    L->data[position - 1] = x;
    L->length++;
    return true;
}

//9.按位置删除
bool ListDelete_pos(SqList *L, int position, ElemType *e){
    if(position < 1 || position > L->length)
        return false;
    *e = L->data[position - 1];
    for(int j = position; j < L->length; j++){
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

//10.删除所有等于value的元素
void ListDelete_val(SqList *L, ElemType value){
    int k = 0;
    for(int i = 0; i < L->length; i++){
        if(L->data[i] != value){
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
}

//主函数
int main(){
    SqList L;
    InitList(&L);
    int op, pos, res, n;
    ElemType val, x, e;
    while(true){
        printf("\n====顺序表操作菜单====\n");
        printf("1 创建顺序表\n");
        printf("2 判断顺序表是否为空\n");
        printf("3 获取顺序表长度\n");
        printf("4 打印顺序表\n");
        printf("5 获取指定位置元素\n");
        printf("6 顺序查找\n");
        printf("7 二分查找（需要有序）\n");
        printf("8 在指定位置插入元素\n");
        printf("9 删除指定位置元素\n");
        printf("10 删除全部等于某个值的元素\n");
        printf("0 退出程序\n");
        printf("请输入操作编号：");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("请输入元素个数：");
                scanf("%d", &n);
                CreateList(&L, n);
                break;
            case 2:
                if(IsEmpty(L)) printf("顺序表是空的\n");
                else printf("顺序表不为空\n");
                break;
            case 3:
                printf("顺序表长度 = %d\n", GetLength(L));
                break;
            case 4:
                printf("顺序表内容：");
                PrintList(L);
                break;
            case 5:
                printf("输入要获取的位置：");
                scanf("%d", &pos);
                if(GetElem(L, pos, &e)) printf("该位置元素：%d\n", e);
                else printf("位置非法！\n");
                break;
            case 6:
                printf("查找value: ");
                scanf("%d", &val);
                res = Search_Seq(L, val);
                if(res) printf("顺序查找，位序:%d\n", res);
                else printf("未找到\n");
                break;
            case 7:
                printf("二分查找value: ");
                scanf("%d", &val);
                res = Search_Bin(L, val);
                if(res) printf("二分查找，位序:%d\n", res);
                else printf("未找到（注意二分查找要求数组有序）\n");
                break;
            case 8:
                printf("插入位置、插入值：");
                scanf("%d %d", &pos, &x);
                if(ListInsert(&L, pos, x)) printf("插入成功\n");
                else printf("插入失败\n");
                break;
            case 9:
                printf("删除位置：");
                scanf("%d", &pos);
                if(ListDelete_pos(&L, pos, &e)) printf("删除元素=%d\n", e);
                else printf("删除失败\n");
                break;
            case 10:
                printf("删除所有等于：");
                scanf("%d", &val);
                ListDelete_val(&L, val);
                printf("已删除全部值为%d的元素\n", val);
                break;
            case 0:
                printf("程序退出\n");
                return 0;
            default:
                printf("输入错误！请重新输入\n");
        }
    }
    return 0;
}
