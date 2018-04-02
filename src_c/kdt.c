#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct tree_node {
    int * data;
    int dim;
    struct tree_node * left;
    struct tree_node * right;
};

typedef struct tree_node node;


void print_node(int* data, int dim)
{
  int i;
  for(i=0; i<dim; i++)
  {
     printf(" %d ", data[i]);
  } 
 
}

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

	print_node((*tree)->data, (*tree)->dim);
    
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

void put(node ** tree, int* datum, int depth, int k)
{
    if( !(*tree) )
    {
	node *temp = NULL;
        temp = (node *) malloc(sizeof(node) );
        temp->data = datum; 
        temp->dim = k; 
        temp->left = temp->right = NULL;
        (*tree) = temp;
        return;
    }
    
    int dim = depth % k;
    if( (*tree)->data[dim] == datum[dim])
    {
   	return;
    }
    else if( (*tree)->data[dim] > datum[dim])
    {
        put( &((*tree)->left), datum, depth+1, k);
    }
    else{
        put( &((*tree)->right), datum, depth+1, k);
    }
}

int search(node ** tree, int * datum, int depth, int k)
{
    if(!(*tree) )
    {
        return 0;
    }
    
    int dim = depth % k;

    if( (*tree)->data[dim] == datum[dim])
    {
	int i;
  	for(i=0; i<k; i++)
  	{
             if((*tree)->data[i] != datum[i])
     	     {
		return 0;
             }
  	} 
        return 1;
    }
    else if( (*tree)->data[dim] > datum[dim])
    {
	return search( &((*tree)->left), datum, depth+1, k);
    }
    else
    {
	return search( &((*tree)->right), datum, depth+1, k);
    }
}

/*void test()
{

    node *root;
    root = NULL;

    int temp[] = {1};
    put(&root,temp, 0, 1); 
    temp = {2};
    put(&root, temp, 0 , 1); 
    temp = {3};
    put(&root, temp, 0 ,1); 
    temp = {4};
    put(&root, temp, 0, 1);

    printf("\nSearch 1:%d", search(&root, int[]{1}, 0, 1));
    printf("\nSearch 2:%d", search(&root, int[]{2}, 0, 1));
    printf("\nSearch 3:%d", search(&root, int[]{3}, 0, 1));
    printf("\nSearch 4:%d", search(&root, int[]{4}, 0, 1));
    printf("\nSearch 0:%d", search(&root, int[]{0}, 0, 1));
    printf("\nSearch -1:%d", search(&root, int[]{-1}, 0, 1));

    printf("\nPrint tree:");
    print(&root);
    printf("\nCleared the tree!\n");
}*/

void main(int argc, char *argv[])
{
    node *root;
    root = NULL;

    int input, i, j, n, k, temp;
 
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
           //test();
        }
        else if(input == 1)
        {
 	      printf("\nEnter K (dimension) value of elements : ");
              scanf("%d", &k);
              
	      printf("\nEnter number of elements to insert : ");
              scanf("%d", &n);
              printf("\nEnter %d elements: ", n);
  	      for ( i = 0 ; i < n ; i++ )
              {
		  int * data = (int *) malloc(sizeof(int)*k);
		  printf("\nEnter element #%d with dimension of %d:", i, k);
		  for(j=0; j<k; j++)
		  {	  
       		       scanf("%d", &data[j]);
		  }	  
       	 	  put(&root, data, 0, k);
    	      }
        }
        else if(input == 2)
        {
           printf("\nK-D Tree : "); 
           print(&root);
           printf("\n\n");
        }
        else if (input == 3)
        {
	   printf("\nPlease input element with %d dimensions to search in KDT :", k);
           int * data = (int *) malloc(sizeof(int)*k);
           for(j=0; j<k; j++)
	   {	  
       	       scanf("%d", &data[j]);
	   }
           n = search(&root, data, 0, k);
           printf("\nSearch result : %d\n", n);
        }

    }

    /*Deleting all nodes of tree*/
    del_tree(&root);
}
