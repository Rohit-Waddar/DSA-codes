#include<stdio.h>
#include<stdlib.h>
#define max 6

typedef struct
{
    int top;
    int element[max];
}stack;

void initstack(stack *s)
{
   s->top=0;
}

int isFull(stack *s)
{
       return (s->top==max-1);
}

void push(stack *s, int e)
{

    s->element[s->top]=e;
     s->top++;
}

int isEmpty(stack *s)
{
           return  (s->top==0);
}

int pop(stack *s)
{

     s->top--;
     int e=s->element[s->top];

     return e;
}

int peek(stack *s)
{
     int e=s->element[s->top];
     return e;
}

void display(stack *s)
{
    FILE * fp4 = fopen("stack1.txt","w");
    if((s->top )==0)
    {
         printf("Stack is empty. \n");
    }
    else
    {
            printf("Stack elements are\n");
            for(int i=s->top;i>=0;i--)
            {
                printf("%d\n",s->element[i]);
                fprintf(fp4,"%d",s->element[i]);
            }
    }
}

int main()
{
    stack s;
    FILE *fp1, *fp2, *fp3, *fp5;
    int n1,t,n2,i,num;
    fp1=fopen("random_num.txt","w");
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
        fp1=fopen("random_num.txt","r");
    fp2=fopen("push.txt","w");
    fp3 = fopen("pop.txt","w");
    fp5= fopen("opern.txt","w");
    initstack(&s);
    int e,ch;
    while(1)
    {
        printf("\n1.push\n 2.pop\n 3.peek\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
              case 1: if(isFull(&s))
                      printf("stack is overflow\n");
                      else
                      {
                        printf("enter the element:");
                        fscanf(fp1,"%d",&e);
                       printf("%d",e);
                        fprintf(fp2,"%d\n",e);
                        push(&s,e);
                        fprintf(fp5,"PUSH\n");
                      }

                      break;
              case 2: if(isEmpty(&s))
                      printf("stack is underflow\n");
                      else
                      {
                         e=pop(&s);
                         fprintf(fp3,"%d\n",e);
                         fprintf(fp5,"POP\n");
                      }
                      break;

              case 3:  display(&s);
                      break;
              case 4: exit(0);
        }

   }
}
