#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct queue_node {
    int data;
    struct queue_node * next;
};

typedef struct queue_node node;

void print_inorder(node ** queue)
{
    if (*queue)
    {
        printf("%d",(*queue)->data);

        if( (*queue)->next)
        {
            printf("->");
            print_inorder(& ((*queue)->next));
        }
    }
}

void print_reverse(node ** queue)
{
    if (*queue)
    {
        if((*queue)->next)
        {
            print_reverse(&((*queue)->next));
            printf("<-");

        }
        printf("%d",(*queue)->data);

    }
}

void del_queue(node ** queue)
{
    if ((*queue))
    {
        del_queue(&((*queue)->next));
        free((*queue));
    }
}

void put(node ** queue, int datum)
{
    if(!(*queue))
    {
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        temp->next = NULL;
        *queue = temp;
        (*queue)->data = datum;
        return;
    }

    put(&((*queue)->next), datum);
    return;

}

int get(node ** queue)
{
    int val = -1;

    if(*queue)
    {
        val = (*queue)->data;

        node *temp = &queue;
        *queue = ((*queue)->next);
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

    printf("Current limitations: Queue returns -1 if empty!");


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
    del_queue(&root);
}