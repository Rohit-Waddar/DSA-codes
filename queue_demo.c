#include<stdio.h>
#include<stdlib.h>
# define SIZE 30
struct queue
{
    int front,rear;
    int items[SIZE];
};
void createqueue(struct queue*Q)
{
    Q->front=0;
    Q->rear=-1;
}
int isEmpty(struct queue* Q)
{
    if(Q->front>Q->rear)
        return 1;
    return 0;
}
int isFull(struct queue* Q)
{
    if(Q->rear==(SIZE-1))
        return 1;
    return 0;
}
void insert(struct queue*Q,int x)
{
    if(isFull(&Q))
        printf("Queue overflow\n");
    else
    {
        Q->rear++;
        Q->items[Q->rear]=x;
    }
}
int dlt(struct queue*Q)
{
        int x;
        if(Q->front==-1 || Q->front>Q->rear)
    {
        printf("Queue underflow\n");
        exit(1);
    }

     x=Q->items[Q->front];
     Q->front++;
     return x;
}
void front(struct queue*Q)
{
     int x;
        x=Q->items[Q->front];//return x;
        printf("%d",x);
}
void display(struct queue*Q)
{
    int i;
    for(i=Q->front;i<=Q->rear;i++)
        {
            printf("%d ",Q->items[i]);
        }
}
int main()
{
    FILE *fp1,*fp2,*fp3,*fp4;
    struct queue Q;
    int x,n,ch;
    createqueue(&Q);
    fp1=fopen("enqueue.txt","a");
    fp2=fopen("dequeue.txt","a");
    fp3=fopen("oplog.txt","a");


    while(1)
    {
         printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("5.front\n");
        scanf("%d",&ch);
        switch(ch)
        {
             case 1: printf("Enter element:");
                     scanf("%d",&x);
                     insert(&Q,x);
                     fprintf(fp1,"%d\n",x);
                     fprintf(fp3,"ENQUEUE\n");
                     break;
             case 2:n=dlt(&Q);
                   printf("%d\n",n);
                   fprintf(fp2,"%d\n",n);
                   fprintf(fp3,"DEQUEUE");
                   break;
            case 3:display(&Q);
                   break;
            case 4:exit(0);
                   break;
            case 5:front(&Q);
                   break;
        }
    }

}
