#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct stack_node {
    int data;
    struct stack_node * next;
};

typedef struct stack_node node;

void print_inorder(node ** stack)
{
    if (*stack)
    {
        printf("%d",(*stack)->data);

        if( (*stack)->next)
        {
            printf("->");
            print_inorder(& ((*stack)->next));
        }
    }
}

void print_reverse(node ** stack)
{
    if (*stack)
    {
        if((*stack)->next)
        {
            print_reverse(&((*stack)->next));
            printf("<-");

        }
        printf("%d",(*stack)->data);

    }
}

void del_stack(node ** stack)
{
    if ((*stack))
    {
        del_stack(&((*stack)->next));
        free((*stack));
    }
}

void put(node ** stack, int datum)
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->data = datum;
    temp->next = NULL;

    if(*stack)
    {
        temp->next = (*stack);
    }

    (*stack) = temp;
}

int get(node ** stack)
{
    int val = -1;

    if(*stack)
    {
        val = (*stack)->data;

        node *temp = &stack;
        *stack = ((*stack)->next);
        free(&temp);
    }

    return val;
}

void main(int argc, char *argv[])
{
    node *root;
    root = NULL;

    put(&root, 1);
    put(&root, 2);
    put(&root, 3);

    printf("Current limitations: stack returns -1 if empty!");


    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));

    printf("\nIn Order:");
    print_inorder(&root);


    printf("\nReverse Order:");
    print_reverse(&root);

    /* Deleting all nodes of tree */
    del_stack(&root);
}