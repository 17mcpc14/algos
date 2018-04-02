#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct hash_node {
    int data;
    struct node * next;
};

typedef struct hash_node node;

void print(node ** list)
{
    if( (*list) )
    {
        printf(" %d ", (*list)->data);
    
        if( (*list)->next)
        {
            printf(" -> ");
            print( &( (*list)->next));
        }

    }
}

void del_node(node ** list)
{
    if ( (*list) )
    {
        del_node(&( (*list)->next));
        free( (*list) );
    }
}


void put(node** list, int datum)
{
     if( (*list) ) 
     {
     	put( &((*list)->next), datum);
     	return;
     }
     
     (*list) = (node*)malloc(sizeof(node));
     (*list)->data = datum;
     (*list)->next = NULL;
}

int search(node** list, int datum)
{
     if( (*list) ) 
     {
     	if( (*list)->data == datum)
     	   return 1;
     	else 
     	   return search( & ((*list)->next), datum);   
     }
     return -1;
}

void main(int argc, char *argv[])
{
    node * hashtable = (node*)malloc(sizeof(node)*10);

    int input, n, temp;
 
    while(input != 4)
    { 
        printf("\nPlease input: \n(1) to insert element into hashtable\n(2) to print table \n(3) Search an element \n(4) to exit \n\nPlease enter your choice :");
	
        scanf("%d", &input);

	if(input <1 || input >4)
        {
           printf("\nInvalid input option!\n");	 
    	}        
        else if(input == 1)
        {
	      printf("\nEnter element to insert : ");
              scanf("%d", &n);
              int dim = n % 10;
              put( & hashtable[dim], n);
        }
        else if(input == 2)
        {
           printf("\nHash table : \n"); 
           for(int i=0;i<10;i++)
           {
           	print( &(hashtable[i]) );
           	printf("\n");
           }
           printf("\n\n");
        }
        else if (input == 3)
        {
	   printf("\nPlease input element to search in hashtable :");
	   scanf("%d", &n);
	   int dim = n % 10;
           temp = search(&hashtable[dim], n);
           printf("\nSearch result : %d\n", temp);
        }

    }

    /*Deleting all nodes of tree*/
    //del_tree(&root);
}
