#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int * sort(int length, int array[])
{
  int i, j;

  for(j=0;j < length;j++)
  {
  	for(i=j;i<length;i++)
  	{
 		if( array[i] < array[j])
        	{
		    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
		}
 	}
  }
  return array;
}

int * results;
int result_index = -1;

void binary_all(int length, int array[], int count, int items[], int l , int r)
{
  if(l>r) return;

  int m = (l+r)/2;

  int right[count];
  int right_index = 0;
  int left[count];
  int left_index = 0;

  int i;
  for(i=0; i < count; i++)
  {
     if( array[m] == items[i])
     {
	result_index = result_index+1;
        results[result_index] = items[i];
     }
     else if( array[m] < items[i])
     {
        right[right_index] = items[i];
        right_index = right_index+1;
     }
     else
     {
        left[left_index] = items[i];
        left_index = left_index+1;
     }  
   }

   if(left_index >0)
   {
      binary_all(length, array, left_index, left, l , m-1);
   }
   if(right_index >0)
   {
      binary_all(length, array, right_index, right, m+1, r);
   }
}


void print(int * results, int m)
{
   printf("\nResults: ");
   int c;
   for ( c = 0 ; c <= m ; c++ )
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

   int flag;

   do{
	flag = 0;
 	printf("\nEnter %d elements in sorted order :", n);
  	
   	for ( c = 0 ; c < n ; c++ )
        {
        	scanf("%d", &array[c]);
      		if( c > 0 & array[c] < array[c-1])
      		{
         		flag = 1;
		}
      	}
	
        if(flag == 1)
	{
		printf("\nEntered elements are not in sorted order!. Please retry.\n");
   	}
   }while(flag == 1);

   printf("\nEnter Number of elements to search:");
   scanf("%d", &m);

   printf("\nEnter %d elements :", m);
   int items[m];
   for ( c = 0 ; c < m ; c++ )
   {
      scanf("%d", &items[c]);
   }
 
   results = (int *)malloc( sizeof(int)*m);

   binary_all(n, array, m, items, 0 , n-1);
   print(results, result_index);

}
