#include<stdio.h>
#include<stdlib.h>
struct Infor
{
    char a;
    int number;
    int time;
};
typedef struct SNode *PtrToSNode;
struct SNode
{
    Infor *data;
    int MaxSize ;
    int Top;
};
typedef PtrToSNode Stack;
struct QNode
{
    Infor data;
    struct QNode *next;
};
typedef struct QNode *Position;
struct LinkQueue
{
    QNode *Front,*Rear;
};
typedef struct LinkQueue *Queue;
Queue CreatQueue( )
{
    
    Queue q=(Queue)malloc(sizeof(struct LinkQueue));
    q->Front=q->Rear=(QNode*)malloc(sizeof(QNode));
    q->Front->next=NULL;
    return q;
}
Stack Creatstack(int MaxSize)
{
    Stack s=(Stack)malloc(sizeof(struct SNode));
    s->data=(Infor *)malloc(MaxSize*sizeof(Infor));
    s->Top=-1;
    s->MaxSize=MaxSize;
    return s;
}
bool IsFull(Stack S){
    return(S->Top == S->MaxSize-1);
}
void Push(Stack S,Infor x)
{
    if(IsFull(S)){
        printf("≥µŒª“—¬˙\n");
        return;
    }
    S->data[++(S->Top)]=x;
    printf("≥µ¡æ»Î’æ≥…π¶\n");
    return;
}
bool IsEmpty(Stack s)
{
    return (s->Top ==-1);
}
Infor GetTop(Stack S)
{
    Infor c;
    c=S->data[S->Top];
    return c;
}

void Pop(Stack S,Stack T,Infor g)
{
    Infor h;
    int price;
    if(IsEmpty(S))
    {
        price=5*(g.time-S->data[1].time);
        printf("ª∂”≠ƒ˙¿¥Õ£≥µ£¨±æ¥ŒÕ£≥µ∑—”√:%d\n",price);
        printf("Õ£≥µ≥°Œ¥”–≥µ¡æÕ£∑≈\n");
        return ;
    } else
    {
        for(int i=S->Top;i>-1;i--)
        {
            if(S->data[i].number==g.number)// «¿Îø™µƒ≥µ
            {
                price=5*(g.time-S->data[i].time);
                printf("%d",S->data[i].time);
                printf("ª∂”≠ƒ˙¿¥Õ£≥µ£¨±æ¥ŒÕ£≥µ∑—”√:%d\n",price);
                S->data[(S->Top)--];
            }else//≤ª «¿Îø™µƒ≥µ
            {
                h=GetTop(S);
                Push(T,h);
                S->data[(S->Top)--];
            }
        }
    }
    
}
void Output(Stack T,Stack S)//µ⁄∂˛∏ˆ’ª∞—‘™Àÿ∑≈ªÿ»•
{
    if(IsEmpty(T))
    {
        return;
    }
    else
    {
        for(int i=T->Top;i>-1;i--)
        {
            Push(S,T->data[i]);
            T->data[(T->Top)--];
        }
    }
}
Queue InQueue(Queue q,Infor e)//‘™Àÿ“™»Î∂”¡–¡À
{
    QNode *p=(QNode*)malloc(sizeof(QNode));
    if(!p)
    {
        printf(" ß∞‹");
    }else
    {
        p->data = e; //»Î∂”µƒ‘™Àÿ « £œ¬µƒ‘™Àÿ
        p->next =NULL;
        q->Rear->next=p;
        q->Rear=p;
        printf("≥…π¶»Î∂”¡–\n");
    }
    return q;
}
void OutQueue(Queue q,Stack S)//’ª¿Ô”–≥µ≥ˆ¿¥µƒª∞£¨‘™Àÿ≥ˆ∂”£¨»•≤π◊„’ª¿Ôµƒ‘™Àÿ
{
    
    QNode *h;
    Infor w;
    if(q->Front == q->Rear)
    {
        printf("±„µ¿“—æ≠√ª”–ø…“‘Ω¯»ÎÕ£≥µ≥°µƒ≥µ¡æ¡À");
    }else
    {
        h=q->Front->next; //‘™Àÿ±£¥Ê£¨–Ë“™¥´∏¯’ª
        w=h->data;
        printf("‘™Àÿ≥ˆ∂”\n");
        Push(S,h->data);
        q->Front->next=h->next;//‘™Àÿ…æ≥˝
        
    }
    free(h);
}
int main()
{
    Infor x,d;
    Stack S,T;
    Queue q=CreatQueue();
    int n,i=0,b;
    printf("Õ£≥µ≥°Õ£∑≈◊‹≥µ¡æ£∫ ");
    scanf("%d",&n);
    S = Creatstack(n);
    T = Creatstack(n);
    printf("≥µ¡æ–≈œ¢ ‰»Î£∫\n");
    x.a='c';
    while(x.a!='p')
    {
        if(i<n)
        { getchar();
            scanf("%c",&x.a);
            scanf("%d",&x.number);
            scanf("%d",&x.time);
            Push(S,x);
            i++;
        }
        if(i>=n)
        {
            getchar();
            scanf("%c",&x.a);
            if(x.a=='p')
            {
                break;
            }
            scanf("%d",&x.number);
            scanf("%d",&x.time);
            InQueue(q,x);
            i++;
        }
    }
    printf("¿Îø™µƒ≥µ¡æ ˝ƒø");
    scanf("%d",&b);
    printf("¿Îø™µƒ≥µ¡æ–≈œ¢\n");
    for(int i=0;i<b;i++)
    {
        getchar();
        scanf("%c",&d.a);
        scanf("%d %d",&d.number,&d.time);
        Pop(S,T,d);
    }
    Output(T,S);
    for(int j=0;j<b;j++)
    {
        OutQueue(q,S);
    }
    return 0;
}

