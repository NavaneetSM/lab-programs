#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node NODE;

/* Allocate memory for a new node */
NODE *getnode()
{
    NODE *first;

    first = (NODE *)malloc(sizeof(NODE));

    if(first == NULL)
    {
        printf("Memory is not allocated\n");
        exit(0);
    }

    return first;
}

/* Insert at beginning */
NODE *insert_first(NODE *first, int item)
{
    NODE *curr;

    curr = getnode();

    curr->info = item;
    curr->link = first;

    first = curr;

    printf("Node inserted at beginning\n");

    return first;
}

/* Insert at end */
NODE *insert_rare(NODE *first, int item)
{
    NODE *curr, *temp;

    curr = getnode();

    curr->info = item;
    curr->link = NULL;

    if(first == NULL)
    {
        printf("Node inserted at end\n");
        return curr;
    }

    temp = first;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = curr;

    printf("Node inserted at end\n");

    return first;
}

/* Insert at a specific position */
NODE *insert_pos(NODE *first, int item, int pos)
{
    NODE *curr, *temp;
    int i;

    if(pos < 1)
    {
        printf("Invalid position\n");
        return first;
    }

    if(pos == 1)
    {
        return insert_first(first, item);
    }

    temp = first;

    for(i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->link;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return first;
    }

    curr = getnode();

    curr->info = item;
    curr->link = temp->link;

    temp->link = curr;

    printf("Node inserted at position %d\n", pos);

    return first;
}

/* Free memory of a node */
void freenode(NODE *temp)
{
    free(temp);
}

/* Delete from beginning */
NODE *delete_first(NODE *first)
{
    NODE *temp;

    if(first == NULL)
    {
        printf("List is empty\n");
        return first;
    }

    temp = first;
    first = first->link;

    printf("Deleted element is: %d\n", temp->info);

    freenode(temp);

    return first;
}

/* Delete from end */
NODE *delete_rare(NODE *first)
{
    NODE *temp, *prev;

    if(first == NULL)
    {
        printf("List is empty\n");
        return first;
    }

    temp = first;
    prev = NULL;

    while(temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    printf("Deleted element is: %d\n", temp->info);

    if(prev == NULL)
    {
        first = NULL;
    }
    else
    {
        prev->link = NULL;
    }

    freenode(temp);

    return first;
}

/* Delete from a specific position */
NODE *delete_pos(NODE *first, int pos)
{
    NODE *curr, *temp;
    int i;

    if(first == NULL)
    {
        printf("List is empty\n");
        return first;
    }

    if(pos < 1)
    {
        printf("Invalid position\n");
        return first;
    }

    if(pos == 1)
    {
        return delete_first(first);
    }

    temp = first;

    for(i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->link;
    }

    if(temp == NULL || temp->link == NULL)
    {
        printf("Invalid position\n");
        return first;
    }

    curr = temp->link;
    temp->link = curr->link;

    printf("Deleted item is: %d\n", curr->info);

    freenode(curr);

    return first;
}

/* Display linked list */
void display(NODE *first)
{
    NODE *temp;

    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = first;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

/* Main function */
int main()
{
    NODE *first = NULL;
    int choice, item, pos;

    while(1)
    {
        printf("\n----- LINKED LIST MENU -----");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at position");
        printf("\n3. Insert at end");
        printf("\n4. Display");
        printf("\n5. Delete at front");
        printf("\n6. Delete at end");
        printf("\n7. Delete at position");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item);

                first = insert_first(first, item);
                break;

            case 2:
                printf("Enter the element: ");
                scanf("%d", &item);

                printf("Enter the position: ");
                scanf("%d", &pos);

                first = insert_pos(first, item, pos);
                break;

            case 3:
                printf("Enter the element: ");
                scanf("%d", &item);

                first = insert_rare(first, item);
                break;

            case 4:
                display(first);
                break;

            case 5:
                first = delete_first(first);
                break;

            case 6:
                first = delete_rare(first);
                break;

            case 7:
                printf("Enter the position: ");
                scanf("%d", &pos);

                first = delete_pos(first, pos);
                break;

            case 8:
                printf("Exiting program...\n");

                while(first != NULL)
                {
                    NODE *temp = first;
                    first = first->link;
                    free(temp);
                }

                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}





