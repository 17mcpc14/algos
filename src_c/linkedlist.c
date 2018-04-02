#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct link_node {
    int data;
    struct link_node * next;
};

typedef struct link_node node;

void print_inorder(node ** link)
{
    if (*link)
    {
        printf("%d",(*link)->data);

        if( (*link)->next)
        {
            printf("->");
            print_inorder(& ((*link)->next));
        }
    }
}

void del_link(node ** link)
{
    if ((*link))
    {
        del_link(&((*link)->next));
        free((*link));
    }
}

void put(node ** link, int datum)
{
    if(!(*link))
    {
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        temp->next = NULL;
        *link = temp;
        (*link)->data = datum;
        return;
    }
    else if((*link)->data > datum )
    {
        node *temp = NULL;
        temp = (node *)malloc(sizeof(node));
        temp->next = (*link)->next;
        temp->data = (*link)->data;
        (*link)->data = datum;
        (*link)->next = temp;
        return;
    }  
    put(&((*link)->next), datum);
    return;

}

void delete(node ** link, int datum)
{
   
   if (*link)
    {
        int data = (*link)->data;

        if(data == datum)
        {
           (*link) = (*link)->next;
        } 
        else if(data < datum)
        {
           return delete( &(*link)->next, datum);
        }
    }
    return;
}

int find(node ** link, int datum)
{
   if (*link)
    {
        int data = (*link)->data;
        
        if(data == datum)
        {
           return 1;
        } 
        else if(data < datum)
	{
	   return find( &(*link)->next, datum);
        }
    }
    return 0;
}

void uni(node ** link1, node ** link2, node ** result)
{
   if (*link2)
    {
        int datum = (*link2)->data;
        int is_present = find(& (*link1) , datum);
        int is_present2 = find(& (*result) , datum);

        if(is_present==0 & is_present2 == 0)
        {
	   put( &(*result), datum);
        }
        uni(&(*link1), &((*link2)->next), &(*result)); 
    }
}

void diff(node ** link1, node ** link2, node ** result)
{
   if (*link2)
    {
        int datum = (*link2)->data;
        int is_present = find(& (*link1) , datum);
        int is_present2 = find(& (*result) , datum);

        if(is_present==0 & is_present2 == 0)
        {
           put( &(*result), datum);
        }
	diff(&(*link1), &((*link2)->next), &(*result)); 
    }
}

void intersection(node ** link1, node ** link2, node ** result)
{
   if (*link1)
    {
        int datum = (*link1)->data;
        int is_present = find(& (*link2) , datum);
        int is_present2 = find(& (*result) , datum);

        if(is_present==1 & is_present2 ==0)
        {
           put( &(*result), datum); 
        }
        
        intersection(&((*link1)->next), &(*link2), &(*result)); 
        
    }
}

void main(int argc, char *argv[])
{
    node *root;
    root = NULL;

    int n, i, temp;
    printf("\nEnter number of elements in L1 : ");
    scanf("%d", &n);
    printf("\nEnter %d elements for L1 : ", n);
    for ( i = 0 ; i < n ; i++ )
    {
      	scanf("%d", &temp);
        put(&root, temp);
    }

    node *root2;
    root2 = NULL;

    int m, j;
    printf("\nEnter number of elements in L2 : ");
    scanf("%d", &m);
    printf("\nEnter %d elements for L2 : ", m);
    for ( j = 0 ; j < m ; j++ )
    {
      	scanf("%d", &temp);
        put(&root2, temp);
    }

    printf("\nL1:");
    print_inorder(&root);

    printf("\nL2:");
    print_inorder(&root2);
    printf("\n");

    node *result;
    result = NULL;
    uni(&root, &root2, &result);
    uni(&result, &root, &result);

    printf("\nUnion:");
    print_inorder(&result);
    
    result = NULL;
    diff(&root2, &root, &result); 

    printf("\nDiff:");
    print_inorder(&result);

    result = NULL;
    intersection(&root, &root2, &result);

    printf("\nIntersection:");
    print_inorder(&result);
    printf("\n"); printf("\n");

    /* Deleting all nodes of tree */
    del_link(&root);
    del_link(&root2);
    del_link(&result);
}
