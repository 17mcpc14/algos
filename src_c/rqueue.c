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

void delete_queue(node ** queue)
{
    if ((*queue))
    {
        delete_queue(&((*queue)->next));
        free((*queue));
    }
}

int empty(node ** queue)
{
    if(*queue)
    {
       return 0; 
    }

    return -1;
}

int dequeue_reverse(node ** queue)
{
    if (empty(&(*queue)))
    {
       printf("\nQueue is empty !");
       return -1;
    }
        
    if(empty(&((*queue)->next)))
    {
       int val = (*queue)->data;
        (*queue) = NULL;
        return val;
    }
    else{
	return dequeue_reverse(&((*queue)->next));
    }
}

void enqueue(node ** queue, int datum)
{
    if(empty(&(*queue)))
    {
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        temp->next = NULL;
        *queue = temp;
        (*queue)->data = datum;
        return;
    }

    enqueue(&((*queue)->next), datum);
    return;

}

void test()
{

    node *root;
    root = NULL;
            
    enqueue(&root, 10);
    enqueue(&root, 20);
    enqueue(&root, 30);
    enqueue(&root, 40);
    enqueue(&root, 50);
    enqueue(&root, 60);
    enqueue(&root, 70);
    enqueue(&root, 80);
    enqueue(&root, 90);
    enqueue(&root, 100);

    printf("\nPrinting in order:");
    print_inorder(&root);

    printf("\nPrinting in reverse order:");
    print_reverse(&root);

    root = NULL;
    enqueue(&root, 1);
    enqueue(&root, 2);
    enqueue(&root, 3);
    enqueue(&root, 4);
    enqueue(&root, 5);

    printf("\nPrinting in order:");
    print_inorder(&root);

    printf("\nPrinting in reverse order:");
    print_reverse(&root);

    /* Deleting all nodes of tree */
    delete_queue(&root);
}

void main(int argc, char *argv[])
{

    test();

    node *root;
    root = NULL;

    int input =0;
    while(input !=5)
    {
       printf("\nPlease provide your input! \n(1) ENQUEUE \n(2) DEQUEUE \n(3) PRINT IN ORDER \n(4) PRINT REVERSE \n(5) EXIT\n");
     
       scanf("%d", &input);
       if(input == 1)
       {
 	 printf("\nPlease input data:");
         int data =0;
         scanf("%d", &data);
 	 enqueue(&root, data);
       }
       else if(input == 2)
       {
	 printf("\nDequeue :%d",dequeue_reverse(&root));
       }
       else if(input == 3)
       {
	 printf("\nPrint in order:"); 
         print_inorder(&root);
       }
       else if(input == 4)
       {
	 
	 printf("\nPrint in reverse order:"); 
         print_reverse(&root); 
       }
       else if(input !=5)
       {
         printf("\nUnknown input!\n");
       }
    }

}


