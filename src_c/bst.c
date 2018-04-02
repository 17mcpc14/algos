#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct tree_node {
    int data;
    struct tree_node * left;
    struct tree_node * right;
};

typedef struct tree_node node;

void print(node ** tree)
{
    if (*tree)
    {
        printf(" ( ");
        if( (*tree)->left)
        {
           
 	    print(& ((*tree)->left));
            printf(" <- ");
        }

	printf(" %d ",(*tree)->data);
    
        if( (*tree)->right)
        {
            printf(" -> ");
            print(& ((*tree)->right));
        }

        printf(" ) ");

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

void put(node ** tree, int datum)
{
    if( !(*tree) )
    {
	node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        temp->data = datum; 
        temp->left = temp->right = NULL;
        (*tree) = temp;
        return;
    }

    if( (*tree)->data == datum)
    {
  	return;
    }
    else if( (*tree)->data > datum)
    {
        put( &((*tree)->left), datum);
    }
    else{
        put( &((*tree)->right), datum);
    }
}

int search(node ** tree, int datum)
{
    int val = -1;

    if(!(*tree) )
    {
        return 0;
    }

    if( (*tree)->data == datum)
    {
	return 1;
    }
    else if( (*tree)->data > datum)
    {
	return search( &((*tree)->left), datum);
    }
    else
    {
	return search( &((*tree)->right), datum);
    }
}

void test()
{

    node *root;
    root = NULL;

    put(&root, 1); put(&root, 2); put(&root, 3); put(&root, 3);

    printf("\nSearch 1:%d", search(&root, 1));
    printf("\nSearch 2:%d", search(&root, 2));
    printf("\nSearch 3:%d", search(&root, 3));
    printf("\nSearch 4:%d", search(&root, 4));
    printf("\nSearch 0:%d", search(&root, 0));
    printf("\nSearch -1:%d", search(&root, -1));

    printf("\nPrint tree:");
    print(&root);
    printf("\nCleared the tree!\n");
}

void main(int argc, char *argv[])
{
    node *root;
    root = NULL;

    int input, i, n, temp;
 
    while(input != 4)
    { 
        printf("\nPlease input: \n(0) for quick test \n(1) to insert elements into tree\n(2) to print tree \n(3) Search an element \n(4) to exit \n\nPlease enter your choice :");
	
        scanf("%d", &input);

	if(input <0 || input >4)
        {
           printf("\nInvalid input option!\n");	 
    	}
        else if(input == 0)
        {
           test();
        }
        else if(input == 1)
        {
 	      printf("\nEnter number of elements insert : ");
              scanf("%d", &n);
              printf("\nEnter %d elements: ", n);
  	      for ( i = 0 ; i < n ; i++ )
              {
       		  scanf("%d", &temp);
       	 	  put(&root, temp);
    	      }
        }
        else if(input == 2)
        {
           printf("\nBinary Search Tree : "); 
           print(&root);
           printf("\n\n");
        }
        else if (input == 3)
        {
	   printf("\nPlease input a number to search in BST :");
           scanf("%d", &n);
           n = search(&root, n);
           printf("\nSearch result : %d\n", n);
        }

    }

    /*Deleting all nodes of tree*/
    del_tree(&root);
}
