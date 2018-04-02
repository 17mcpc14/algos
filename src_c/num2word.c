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

void uni(node ** link1, node ** link2)
{
   if (*link2)
    {
        int datum = (*link2)->data;
        int is_present = find(& (*link1) , datum);
        
        if(is_present==0)
        {
           put( &(*link1), datum);
        }
        uni(&(*link1), &((*link2)->next)); 
    }
}

void diff(node ** link1, node ** link2)
{
   if (*link2)
    {
        int datum = (*link2)->data;
        int is_present = find(& (*link1) , datum);
        
        if(is_present==1)
        {
           delete( &(*link1), datum);
        }
	diff(&(*link1), &((*link2)->next)); 
    }
}

void intersection(node ** link1, node ** link2)
{
   if (*link1)
    {
        int datum = (*link1)->data;
        int is_present = find(& (*link2) , datum);

        if(is_present==0)
        {
           delete( &(*link1), datum);
	   intersection(&((*link1)), &(*link2)); 
        }
        else{
           intersection(&((*link1)->next), &(*link2)); 
        }
    }
}

void main(int argc, char *argv[])
{
    node *root;
    root = NULL;
    node *root1;
    root1 = NULL;
    node *root2;
    root2 = NULL;

    printf("\nPlease input values for linked list #1, enter 0 to exit : \n");
    int num = 0;
    scanf("%d", &num);
    while(num !=0)
    {
      put(&root, num);put(&root1, num);put(&root2, num);
      scanf("%d", &num);
    }


    node *root4;
    root4 = NULL;

    printf("\nPlease input values for linked list #2, enter 0 to exit : \n");
    scanf("%d", &num);
    while(num !=0)
    {
      put(&root4, num);
      scanf("%d", &num);
    }

    printf("\nL1:");
    print_inorder(&root);

    printf("\nL2:");
    print_inorder(&root4);
    printf("\n");

    uni(&root, &root2);

    printf("\nUnion:");
    print_inorder(&root);

    diff(&root1, &root4);

    printf("\nDiff:");
    print_inorder(&root1);

    intersection(&root2, &root4);

    printf("\nIntersection:");
    print_inorder(&root2);
    printf("\n"); printf("\n");

    /* Deleting all nodes of tree */
    del_link(&root);
    del_link(&root2);
}
