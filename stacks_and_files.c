#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct s
{
    int top;
    int elements[MAX];
}st;

void initstack( st* s);
void push(st* s ,int );
int isFull(st* s);
int isEmpty(st* s);
int pop(st* s);


int main()
{
    st s;
    int n1,n2,p,num,e,ch;
    printf("Enter n1 &n2");
    scanf("%d%d",&n1,&n2);
    printf("Enter p\n");
    scanf("%d",&p);
    fp1=fopen()
    for(int i;i<p;i++)
    {
        num=(rand() %(n2 - n1 + 1)) + n1;
        printf("%d",num);
        fprintf(fp1,"%d",num);
    }
    fclose(fp1);

    while(1)
    {
        printf("1-PUSH\n");
        printf("2-POP\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: if(isFull(&s)==1)
                      {
                            printf("Stack is over flow\n");
                      }

                   else
                   {
                     printf("Enter element:\n");
                     fscanf(fp1,"%d",&e);
                     printf("%d",e);
                     fprintf(fp2,"%d\n",e);
                     push(&s,e);
                   }
                   break;
            case 2: if(isEmpty(&s)==1)
                      {
                         printf("Stack underflow\n");
                      }

                        else
                        {
                            e=pop(&s);
                            fprintf(fp3,"%d\n",e);
                        }
                        break;

         case 3: exit(0);

        }
    }
}

void initstack( st* s)
{
    s->top=-1;

}

int isFull(st* s)
{
    if(s->top==MAX-1)
        return 1;
    else
        return 0;
}

void push (st* s, int e)
{
    s->top++;
    s->elements[s->top]=e;
}

int isEmpty(st* s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

int pop(st* s)
{
    int e=s->elements[s->top];
    s->top--;
    return e;
}
void display(stack *s)
{
    FILE * fp4 = fopen("stack1.txt","w");
    if((s->top )==-1)
    {
         printf("Stack is empty. \n");
    }
    else
    {
            printf("Stack elements are\n");
            for(int i=s->top;i>=0;i--)
            {
                printf("%d\n",s->element[s->top]);
                fprintf(fp4,"%d\n",s->element[s->top]);
            }
    }
}
