#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct tree_node {
    int ldata;
	int rdata;
	int size;
    struct tree_node * left;
	struct tree_node * mid;
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
	
	if((*tree)->size > 1)
	{
		printf("[ %d , %d ]", (*tree)->ldata, (*tree)->rdata);
 	}
	else
	{
		printf("[ %d ]", (*tree)->ldata );
	}
      
	if( (*tree)->mid)
        {
            printf(" { ");
 	    print(& ((*tree)->mid));
            printf(" } ");
        }

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
		del_tree(&((*tree)->mid));
        del_tree(&((*tree)->left));
        free((*tree));
    }
}

node * new_node(int datum)
{
    node *temp = NULL;
    temp = (node *) malloc(sizeof(node) );
    temp->ldata = datum; 
    temp->rdata = -1; 
	temp->size = 1; 
    temp->left = temp->right = temp->mid = NULL;
    return temp;
}

int propogate(node ** tree, int level, int val, int side)
{
	//if(level == 0)
	//{
	//	printf("propogation at level %d \n", level);
	//	return -1;
	//}

	if(val < 0)
	{
		printf("no  propogation needed at level %d \n", level);
		return -1;
	}
	
	// handle propogation
		
	if(side == -1) // from left
	{
		if( (*tree)->size == 1)
		{
			(*tree)->rdata = (*tree)->ldata;
			(*tree)->size = 2;
			(*tree)->ldata = val;
			(*tree)->mid = ((*tree)->left)->right;
			(*tree)->left = ((*tree)->left)->left;
		}
		else
		{
			node *temp = new_node((*tree)->rdata);
			temp->left = (*tree)->mid;
			temp->right = (*tree)->right;
			(*tree)->right = temp;
		
			(*tree)->size = 1;
			(*tree)->mid = NULL;
		}	
	}
        else if(side == 0)
	{
		node *temp = new_node((*tree)->ldata);
		temp->left = (*tree)->left;
		temp->right = ((*tree)->mid)->left;
		(*tree)->left = temp;
		
		temp = new_node((*tree)->rdata);
		temp->left = ((*tree)->mid)->right;
		temp->right = (*tree)->right;
		(*tree)->right = temp;
			
		(*tree)->ldata = val;
		(*tree)->size = 1;
		free((*tree)->mid);
		(*tree)->mid = NULL;
	}
	else
	{
		if( (*tree)->size == 1)
		{
			(*tree)->rdata = val;
			(*tree)->size = 2;
			(*tree)->mid = ((*tree)->right)->left;
			(*tree)->right = ((*tree)->right)->right;
		}
		else
		{
			node *temp = new_node((*tree)->ldata);
			temp->left = (*tree)->left;
			temp->right = (*tree)->mid;
			(*tree)->left = temp;

			(*tree)->ldata = (*tree)->rdata;
			(*tree)->size = 1;
			(*tree)->mid = NULL;
		}		
       	}	
	
	return 0;	
}

int put(node ** tree, int* datum, int level)
{
    if( !(*tree) )
    {
	(*tree) = new_node(datum);
	return -1;
    }

    if( (*tree)->size ==1) 
    {
	if( !(*tree)->left ) // just add to root node
	{	
		if( (*tree)->ldata < datum )
		{
			(*tree)->rdata = datum;
		}
		else
		{
			(*tree)->rdata = (*tree)->ldata;
			(*tree)->ldata = datum;
		}
		(*tree)->size = 2;
		return -1;
	}
	else 
	{
		if( (*tree)->ldata > datum )
		{
			int val = put( &(*tree)->left, datum, level+1);
			return propogate(tree, level, val,-1);
		}
		else
		{
			int val = put( &(*tree)->right, datum, level+1);
			return propogate(tree, level, val,1);
		}
	}	
    }
    else if( !(*tree)->left ) //split the root into 2 children
    {
	if( (*tree)->ldata > datum )
	{
		(*tree)->left = new_node(datum);
		(*tree)->right = new_node((*tree)->rdata);		
	}
	else
	{
		(*tree)->left = new_node((*tree)->ldata);
		if( (*tree)->rdata > datum )
 		{
			(*tree)->right = new_node((*tree)->rdata);
			(*tree)->ldata = datum;
		}
		else
		{
			(*tree)->right = new_node(datum);
			(*tree)->ldata = (*tree)->rdata;
		}	
	}
	(*tree)->size = 1;
		
	// propagate upwards that the child is been split
	return (*tree)->ldata;
	
    }
    else
    {
	if( (*tree)->ldata < datum && (*tree)->rdata > datum )
	{
		if( !(*tree)->mid )
		{
			(*tree)->mid = new_node(datum);
			// no propagation needed as there are already nodes at this level
			return -1;
		}
		else
		{
			int val = put( &(*tree)->mid, datum, level+1); 
			return propogate(tree, level, val, 0);
		}
	}
	else if( (*tree)->ldata > datum )
	{
		int val = put( &(*tree)->left, datum, level+1);
		return propogate(tree, level, val, -1);			
	}
	else if( (*tree)->rdata < datum )
	{
		int val = put( &(*tree)->right, datum, level+1);
		return propogate(tree, level, val, 1);			
	}
    }
}

int search(node ** tree, int * datum)
{
    if(!(*tree) )
    {
        return 0;
    }
    
    if( (*tree)->ldata == datum || ((*tree)->size ==2 && (*tree)->rdata == datum) )
    {
	return 1;
    }	
    else if( (*tree)->ldata > datum)
    {
	return search( &(*tree)->left, datum );
    }
    else if( (*tree)->size ==2 && (*tree)->rdata < datum)
    {
	return search( &(*tree)->right , datum);
    }
    else if( (*tree)->size ==2 && (*tree)->rdata > datum && (*tree)->ldata < datum)
    {
	return search( &(*tree)->mid , datum);
    }
    return 0;
}

int delete(node ** tree, int datum)
{
    if(!(*tree) )
    {
        return 0;
    }
    
    if( (*tree)->ldata == datum ) 
    {
	if(!(*tree)->left)
	{
		if( (*tree)->size == 1)
		{
			free((*tree));			
			return 1;
		}
		else
		{
			(*tree)->ldata = (*tree)->rdata;
			(*tree)->size = 1;
			return 1;
		}
	}
	else
	{
		// propegate left tree upwards
	}
    }
    else if( (*tree)->ldata > datum ) 
    {
	if(!(*tree)->left)
	{
		return 0;
	}
	else
	{
		// search and propagate left node if needed
	}	
    }	
    else if( (*tree)->size == 2 && (*tree)->rdata == datum ) 
    {
	if(!(*tree)->right)
	{
		(*tree)->size = 1;
		return 1;
	}
	else
	{
		// propegate right tree upwards
	}
   }
   else if( (*tree)->rdata < datum ) 
   {
	if(!(*tree)->right)
	{
		return 0;
	}
	else
	{
		// search and propagate right node if needed
	}	
   }
   else if( (*tree)->size == 2 && (*tree)->rdata < datum && (*tree)->ldata < datum )
   {
	if( !(*tree)->mid )
	{
		return 0;
	}
	else
	{
		// search and propagate middle node
	}
  }
}

void main(int argc, char *argv[])
{
    node *root;
    root = NULL;

    int input, i, j, k, n, data, temp;
 
    while(input != 4)
    { 
        printf("\nPlease input: \n(1) to insert elements into tree\n(2) to print tree \n(3) Search an element \n(4) to delete an elemtn \n(5) to exit \n\nPlease enter your choice :");
	
        scanf("%d", &input);

	if(input <1 || input >5)
        {
           printf("\nInvalid input option!\n");	 
    	}
        else if(input == 1)
        {   
	    printf("\nEnter number of elements to insert : ");
            scanf("%d", &n);
            printf("\nEnter %d elements: ", n);
	    for ( i = 0 ; i < n ; i++ )
            {
		scanf("%d", &data);
		put(&root, data, 0);
    	    }
        }
        else if(input == 2)
        {
           printf("\n2-3 Tree : "); 
           print(&root);
           printf("\n\n");
        }
        else if (input == 3)
        {
	   printf("\nPlease input element to search in 2-3 Tree :");
           scanf("%d", &k);
	   temp = search(&root, k);
           printf("\nSearch result : %d\n", temp);
        }
	else if (input == 4)
        {
	   printf("\nPlease input element to delete in 2-3 Tree :");
           scanf("%d", &k);
	   temp = delete(&root, k);
           printf("\nDelete result : %d\n", n);
        }

    }

    /*Deleting all nodes of tree*/
    del_tree(&root);
}
