#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10

typedef struct Queue
{
    int data[size];
    int front;
    int rear;
}k;

void Enqueue(struct Queue *q,int);
int Dequeue(struct Queue *q);
void display(struct Queue *q);

int main()
{
    k sk;
    int item;
    k *q;
    q=&sk;
    q->front=0;
    q->rear=-1;
    int op,x,j,y,n,h;
    printf("Enter the number\n");
    scanf("%d",&n);
    printf("Enter the range of random numbers\n");
    scanf("%d %d",&j,&y);
    FILE  *fp1=fopen("rNoQueue3.txt","w");

    for(int i=0;i<n;i++)
    {
        item=rand()%(y-j);
        fprintf(fp1,"%d ",item);
    }
    fclose(fp1);
    FILE *fp2=fopen("rNoQueue3.txt","r");
    while(1)
    {
        printf("Enter the option\n");
        printf("1:Enqueue\n 2: Dequeue\n 3:display\n 4: to update Queue File");
        scanf("%d",&op);
        operdis(op);
        switch(op)
        {
            case 1:fscanf(fp2,"%d",&x);
                Enqueue(q,x);
                Enqueued(x);
                break;
             case 2:h= Dequeue(q);
                Dequeued(h);
                break;
             case 3:display(q);
             break;
             case 4: update(q);
             break;
        }
    }
    fclose(fp2);
}

void operdis(int op)
{
  FILE *fp5=fopen("priorityLogFile.txt","a");
    char str1[]="Enqueue()";
    char str2[]="Dequeue()";
    if(op==1)
    {
        fprintf(fp5,"%s\n",str1);
    }
    else if(op==2)
    {
        fprintf(fp5,"%s\n",str2);
    }
    fclose(fp5);
}

void Enqueued(int k)
{
    FILE *fp2=fopen("PriorityEnqueued.txt","a");
    fprintf(fp2,"%d ",k);
    fclose(fp2);
}
void Dequeued(int item)
{
      FILE *fp4=fopen("PriorityDequeue.txt","a");
      fprintf(fp4,"%d ",item);
     fclose(fp4);
}

void Enqueue(struct Queue *q,int x)
{
    int i;
    if(q->rear==size-1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        i=q->rear;
        q->rear++;
        while(q->data[i]>=x && i>=0)
        {
           q->data[i+1]=q->data[i];
           i--;
        }
        q->data[i+1]=x;
    }
}
int Dequeue(struct Queue *q)
{
    int x;
    if(q->front>q->rear)
    {
        printf("Queue underflow\n");
        exit(1);
    }
    else
    {
        x=q->data[q->front];
        q->front++;
        return x;
    }
}
void display(struct Queue *q)
{
    if(q->front> q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->data[i]);
        }
    }
}
void queueFile(int x)
{
    FILE *fp=fopen("PriorityQueuefile.txt","a");
    fprintf(fp,"%d ",x);
    fclose(fp);
}

void update(k *q)
{
    int i;
    for(int i=q->front;i<=q->rear;i++)
        {
            queueFile(q->data[i]);
        }
}

