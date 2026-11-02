#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int q[MAX];
int front=-1,rear=-1;
int item;

void insert(int item)
{
    if((rear+1)%MAX==front)
    {
        printf("Queue is overflow\n");
    }
    else{
        printf("Enter the element to be inserted:");
        scanf("%d",&item);
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%MAX;
        }
        q[rear]=item;
    }
}

void delete()
{
    if(front==-1)
        printf("Queue is underflow");
    else{
        printf("Deleted item is:%d",q[front]);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%MAX;
        }
    }
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else{
        for(i=front;i<=rear;i=(i+1)%MAX){
            printf("%d ",q[i]);

        }
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert(item);
                    break;

            case 2: delete();
                    break;

            case 3: display();
                    break;

            case 4: return 0;

            default: printf("Invalid Choice\n");
                     break;
        }
    }
}
