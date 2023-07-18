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
    q->front=-1;
    q->rear=-1;
    int op,x,h;
    FILE  *fp1=fopen("rNoQueue2.txt","w");

    for(int i=0;i<10;i++)
    {
        item=rand()%100;
        fprintf(fp1,"%d ",item);
    }
    fclose(fp1);
    int k;
    FILE *fp2=fopen("rNoQueue2.txt","r");
    while(1)
    {
        printf("Enter the option\n");
        printf("1:Enqueue\n 2: Dequeue\n 3:display\n");
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
        }
    }
}
void operdis(int op)
{
  FILE *fp5=fopen("operationQueue1.txt","a");
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
    FILE *fp2=fopen("Enqueued2.txt","a");
    fprintf(fp2,"%d ",k);
    fclose(fp2);
}
void Dequeued(int item)
{
      FILE *fp4=fopen("Dequeue2.txt","a");
      fprintf(fp4,"%d ",item);
     fclose(fp4);
}


void Enqueue(struct Queue *q,int x)
{
    if(((q->rear+1)%size)==q->front)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if(q->front==-1)
            {
                q->front=0;
            }
            q->rear=(q->rear+1)%size;
            q->data[q->rear]=x;

    }
}

int Dequeue(struct Queue *q)
{
    int x;
    if(q->front==-1 && q->rear==-1)
    {
        printf("Queue underflow\n");
        exit(1);
    }
    else if(q->front==0 && q->rear==0)
    {
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        x=q->data[q->front];
        q->front=(q->front+1)%size;

    }
    return x;
}
void display(struct Queue *q)
{   int i;
    if(q->front==-1 && q->rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        i=q->front;
        while(i<=q->rear)
        {
            printf("%d ",q->data[i]);
            i=(i+1)%size;
        }

    }
}
