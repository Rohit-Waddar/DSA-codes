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
    FILE *fp5=fopen("Queue.txt","w");
    if(Q->front==0 && Q->rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
        {
         for(i=Q->front;i<=Q->rear;i++)
        {
            printf("%d ",Q->items[i]);
            fprintf(fp5,"%d",Q->items[i]);
        }
        }

}
int main()
{
    struct queue Q;
    int x,n,ch;
    createqueue(&Q);
    FILE * fp1,fp2,fp3,fp4;
    fp1=fopen("input.txt","w");
    printf("Enter the value of n1 and  n2 \n");
    scanf("%d %d",&n1,&n2);
    printf("Enter the value of t ");
    scanf("%d",&t);
     for(i=0;i<t;i++)
    {
    num = (rand() % (n1 - n2 +1))+ n1;
    printf("%d\n ",num);
    fprintf(fp1,"%d ",num);
    }
     fclose(fp1);
        fp1=fopen("input.txt","r");
    fp2=fopen("enqueue.txt","w");
    fp3 = fopen("dequeue.txt","w");
    fp4= fopen("oplog.txt","w");
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
             case 1:  if(isfull(&Q))
                     {
                         printf("Queue over flow\n");
                     }
                     else
                     {
                         printf("Enter element:");
                         fscanf("%d",&x);
                       insert(&Q,x);
                     break;
                     }

             case 2:n=dlt(&Q);
                   printf("%d\n",n);
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
