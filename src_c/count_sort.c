#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int * sorted_array;

void count_sort(int array[], int length)
{
  int i, temp, count_array[10];
  for(i=0;i<10;i++)
  {
     count_array[i] = 0;
  }

  for(i=0;i<length;i++)
  {
     temp = array[i];
     count_array[temp] = count_array[temp]+ 1;
  }
 
  temp = count_array[0];
  for(i=1;i<10;i++)
  {
     temp = temp + count_array[i];
     count_array[i] = temp;
  }

  for(i=0;i<length;i++)
  {
     temp = array[i];
     int count = count_array[temp];
     if(count>0)
     {
        sorted_array[count-1] = temp;
        count --;
        count_array[temp] = count;
     }
  }
  
}

void main(int argc, char *argv[])
{

   int n, c;
 
   printf("\nEnter number of elements in array : ");
   scanf("%d", &n);
   int array[n];
   sorted_array = (int *) malloc(n * sizeof(int));

   printf("Enter %d elements: \n", n);
  	
   for ( c = 0 ; c < n ; c++ )
   {
       scanf("%d", &array[c]);
   }

   count_sort(array, n);

   printf("\nSorted Elements: ");
  	
   for ( c = 0 ; c < n ; c++ )
   {
       printf(" %d ", sorted_array[c] );
   } 
}
