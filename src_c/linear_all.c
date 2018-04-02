#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int * linear(int length, int array[], int count, int items[])
{
  int * results = malloc(sizeof(int) * count);
  int i, j, k;
  for(j=0;j<count;j++)
  {
  	for(i=0;i<length;i++)
  	{
 		if(array[i] == items[j])
        	{
		    results[j] = 1;
		}
 	}
  }
  return results;
}


void print(int * results, int m)
{
   printf("\nResults: ");
   int c;
   for ( c = 0 ; c < m ; c++ )
   {
      printf(" %d ", *(results+c));
   }
  
   printf("\n");
}


void main(int argc, char *argv[])
{

   int n, m, c;
 
   printf("\nEnter number of elements in array : ");
   scanf("%d", &n);
   int array[n];

   printf("\nEnter %d elements :", n);
   for ( c = 0 ; c < n ; c++ )
   {
      	scanf("%d", &array[c]);
   }

   printf("\nEnter Element to search:");
   scanf("%d", &m);
   
   int items[m];

   printf("\nEnter %d elements :", m);
 
   for ( c = 0 ; c < m ; c++ )
   {
      scanf("%d", &items[c]);
   }
   
   int * results = linear(n, array, m, items);
   print(results, m);
 
}
