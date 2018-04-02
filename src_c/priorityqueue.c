#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct tree_node {
    int data;
    int priority;
    struct tree_node * left;
    struct tree_node * right;
};

typedef struct tree_node node;

void print(node ** tree)
{
    if (*tree)
    {
	    if( (*tree)->right)
        {
            print(& ((*tree)->right));
        }

        printf("( data:%d , priority:% d)",(*tree)->data, (*tree)->priority);

        if( (*tree)->left)
        {
            print(& ((*tree)->left));
        }
    }
}

void del_tree(node ** tree)
{
    if ((*tree))
    {
        del_tree(&((*tree)->right));
        del_tree(&((*tree)->left));
        free((*tree));
    }
}

void put(node ** tree, int datum, int priority)
{
    if( !(*tree) )
    {
	node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        temp->data = datum; temp->priority = priority;
        temp->left = temp->right = NULL;
        (*tree) = temp;
        return;
    }
    if( (*tree)->priority >= priority)
    {
       if( !( (*tree)->left) )
       {
	   node *temp = NULL;
           temp = (node *)malloc(sizeof(node));
           temp->data = datum; temp->priority = priority;
           temp->left = temp->right = NULL;
           (*tree)->left = temp;
           return;
       }
       else
       {
           put( &((*tree)->left), datum, priority);
       }
    }
    else{
       if( !( (*tree)->right) )
       {
	   node *temp = NULL;
           temp = (node *)malloc(sizeof(node));
           temp->data = datum; temp->priority = priority;
           temp->left = temp->right = NULL;
           (*tree)->right = temp;
           return;
       }
       else
       {
           put( &((*tree)->right), datum, priority);
       }
    }
}

int get(node ** tree)
{
    int val = -1;

    if(*tree)
    {
	    if( (*tree)->right)
        {
            return get( &((*tree)->right));
        }
        else
        {

            val = (*tree)->data;
            node *temp = &tree;
            *tree = ((*tree)->left);
            //free(&temp);
        }
    }

    return val;
}

void main(int argc, char *argv[])
{
    node *root;
    root = NULL;

    put(&root, 1, 1);
    put(&root, 2, 2);
    put(&root, 3, 3);

    printf("Current limitations: tree returns -1 if empty!");

    printf("\nBefore get:");
    print(&root);

    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));
    printf("\nGet Next:%d", get(&root));


    printf("\nAfter get:");
    print(&root);

     /*Deleting all nodes of tree*/
    del_tree(&root);
}