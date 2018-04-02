#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print(int * results, int m)
{
   printf("\nSorted order of elements: ");
   int i;
   for ( i = 0 ; i < m ; i++ )
   {
      printf(" %d ", *(results+i));
   }
  
   printf("\n");
}

int * modified_sort(int length, int array[])
{
  int one_index = -1, three_index = length, i;

  for(i=0;i < three_index;i++)
  {
  	if(array[i] == 0 && i != one_index)
        {

           one_index++;
           int temp = array[one_index];
           array[one_index] = array[i];
           array[i] = temp;
           i--;
        }        
        else if(array[i] == 2)
        {

           three_index--;
           int temp = array[three_index];
           array[three_index] = array[i];
           array[i] = temp;
           i--;
	}
 
  }
  return array;
}

int* count_sort(int length, int array[])
{

  int one_count =0;
  int two_count =0;

  int i;
  for(i=0; i < length; i++)
  {
     if( array[i] == 0)
     {
	one_count++;
     }
     else if( array[i] == 1)
     {
        two_count++;
     }
  }

  for(i=0; i < one_count; i++)
  {
     array[i] = 0;
  }

  for(i=one_count; i < one_count+two_count; i++)
  {
     array[i] = 1;
  }

  for(i= one_count+two_count; i < length; i++)
  {
     array[i] = 2;
  }
  
  return array;
}

int* read_elements(int n, int array[])
{
   array = (int *) malloc(n);

   printf("\nPlease enter %d elements in to be sorted :\n Note: only 0, 1 , 2 valid integer elements as per the problem definition.\n Please provide your input : ", n);
  
   int i;
   for(i=0;i<n;i++)
   {
        scanf("%d", &array[i]);

        if(array[i] < 0 || array[i] > 2)
        {
           printf("\n Only integers with value 0, 1, 2 are allowed input elements.\n  Please re-enter element at location %d :", i+1);
           i--;
        }
   }
   return array;
}

void main(int argc, char *argv[])
{

   int choice =0;
   do{
   	printf("\nPlease input your choice \n (1) for counting sort\n (2) for modified counting sort\n (3) for exit\nInput choice: ");
 	
        scanf("%d", &choice);
        
        if(choice == 1) 
        {
  	     int n;
             printf("\nPlease enter number of elements in array : ");
             scanf("%d", &n);

             int* array;
             array = read_elements(n, array);
	     array = count_sort(n, array);
             print(array, n);
        }
        else if(choice == 2) 
        {
  	     int n;
             printf("\nPlease enter number of elements in array : ");
             scanf("%d", &n);

             int* array;
             array = read_elements(n, array);
	     array = modified_sort(n, array);
             print(array, n);
        }
        else if(choice<1 || choice >4)
        {
             printf("\nInvalid input choice!\n");
        }
  
   }while(choice!=3);

}
