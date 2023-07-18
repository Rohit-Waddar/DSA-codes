#include<stdio.h>
#include<time.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;
void createnode()
{
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter Data ");
        scanf("%d", &newnode->data);

        newnode->next=0;

        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp = newnode;
        }
}
void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    scanf("%d", &newnode->data);
    newnode->next=0;

    temp = head;
    while(temp->next!=0)
    {
        temp = temp->next;
    }
    temp->next=newnode;
}
int main()
{
    clock_t t;
    int b[10],n=0,n2,n1;
    FILE *fp;
    t=clock();
    fp=fopen("input.txt","w");
    srand(time(0));
    createnode()
   // while(!feof(fp))
   for(n=0;n<5;n++)
{
    int num = (rand() %(n2 - n1 + 1)) + n1;
    //b[n]=num;
    insertAtEnd()=num;
    fprintf(fp,"%d\n",b[n]);

}
fclose(fp);
selection(b,n);
fp=fopen("output.txt","a");
fprintf(fp,"SELECTION SORT:\n");
for(int i=0;i<n;i++)
{
    fprintf(fp,"%d\t",b[i]);
}
fprintf(fp,"\n");
fclose(fp);
t=clock()-t;
double time=((double)t)/CLOCKS_PER_SEC;
printf("This took %f seconds to execute \n",time);
fp=fopen("logs.txt","a");
fprintf(fp,"SELECTION SORT : %f\t",time);
fprintf(fp,"\n");
fclose(fp);
}

void selection(int b[10000],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(b[j]<b[min])
                min=j;
        }
        swap(&b[i],&b[min]);
    }
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
