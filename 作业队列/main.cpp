#include<stdio.h>
#include<stdlib.h>
//判断栈是否满，满存在队列里；
//车出去移动到另一个栈里面，队列不移动
//停回去时候d队列需要出队列，移动到栈里面
//元素出栈也要记录；

typedef int ElemType;
typedef struct QNode  //结点结构
{
    Infor data;
    struct QNode *next;
}QNode;
typedef struct
{
    QNode *Front,*Rear;
}LinkQueue;
LinkQueue *CreatQueue(LinkQueue *q)
{

    q->Front=q->Rear=(QNode*)malloc(sizeof(QNode));
    q->Front->next=NULL;
    return q;
}
//判断栈满不满,不满的话缺少几个
void InQueue(LinkQueue *q,Infor e)//元素要入队列了
{
    QNode *p=(QNode*)malloc(sizeof(QNode));
    if(!p)
    {
        printf("失败");
    }else
    {
        p->data = e; //入队的元素是剩下的元素
        p->next =NULL;
        q->Rear->next=p;
        q->Rear=p;
    }
}
void OutQueue(LinkQueue *q)//栈里有车出来的话，元素出队，去补足栈里的元素
{
    QNode *h;
    ElemType w;
    if(q->Front == q->Rear)
      {
          printf("便道已经没有可以进入停车场的车辆了");
      }else
       {
           h=q->Front->next; //元素保存，需要传给栈
           w=h->data;
           Push(S,h->data);
           q->Front->next=h->next;//元素删除
       }
    free(h);
}
