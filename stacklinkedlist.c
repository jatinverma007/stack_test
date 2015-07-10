#include<stdio.h>
struct stack
{
int value;
struct stack *next;
};
struct stack *TOP = NULL, *ptr;
void push()
{
    ptr = new stack;
    printf("\nenter value");
    scanf("%d",ptr->value);
    if(TOP == NULL)
    {
        TOP = ptr;
        TOP->next = NULL;
    }
    else
    {
        ptr->next = TOP;
        TOP = ptr;
    }

}
void pop()
{

    if(TOP == NULL)
    {
        printf("\nstack empty");
    }
    else
        {
            ptr = TOP;
            printf("\nelement deleted\n",TOP->value);
           TOP->next = TOP;
           free(ptr);
        }
}
void display()
{
    ptr=TOP;
    while(ptr!=NULL)
        printf("\nelements are \n",TOP->value);
        ptr=ptr->next;

}

main()
{
   push();
}
