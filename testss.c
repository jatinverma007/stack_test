#include <stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};

typedef struct node Node;

Node *head=NULL;
Node *tail;
void insert(int);
int fetch(int);
void display();
int search(int);
int main(int argc, char *argv[])
{
    int a,b,ch;
    int choice,num;
    int value;
    int index;
    while(1)
    {
        printf("What do you want to do?\n\n");
        printf("1. Insert \n2. Fetch \n3.display \n4.search \n5.Exit \n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the value you want to insert!\n");
            scanf("%d", &value);
            insert(value);
            printf("\nInserted the value %d into linkedList\n", value);
            break;
        case 2:
            printf("\nValue at what index you want to fetch\n");
            scanf("%d", &index);
            value = fetch(index);
            printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nenter a integer you want to search");
            scanf("%d",&a);
            b=search(a);
            if(b)
            {
                printf("\nelement found");

            }
            else
            {
                printf("\nelement is not found");
            }
            break;

        case 5:
            printf("\nExiting...\n");
            return 0;
        default:
            break;
        }
    }
}
void insert(int value)
{


    if(head == NULL)
    {
        //this means list is empty
        head = (Node *)malloc(sizeof(Node));
        (*head).value=value;
        tail=head;
    }
    else
    {
        (*tail).next = (Node *)malloc(sizeof(Node));
        (*(*tail).next).value=value;
        //now newNode is the last node and tail should always store pointer to last node.
        tail = (*tail).next;
        (*tail).next=NULL;
    }
}
void display()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("elements are%d\n",ptr->value);
        ptr=ptr->next;
    }

    printf("\n\n");
}
int fetch(int index)
{
    int i;
    if(head == NULL)
    {
        return -1;
    }

    Node *pointer = head;
    for (i = 0; i < index; i++)
    {
        if(pointer->next == NULL)
        {
            return -1;
        }
        pointer = pointer->next;
    }

    return pointer->value;

}
int search(int value)
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->value==value)
        {
            return 1;
        }

        ptr=ptr->next;
    }
    return 0;
}

