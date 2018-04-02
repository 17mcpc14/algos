#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int binary(int l, int r, int array[], int item)
{
  if(l>r) return 0;
  int m = (l+r)/2;
 
  if( array[m] == item)
  {
     return 1;
  }
  else if (array[m] > item )
  {
    return binary(m+1 , r,  array, item); 
  }
  else{
    return binary(l, m-1, array, item);
  }
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
 	printf("Enter %d elements in sorted order\n", n);
  	
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

   printf("\nEnter Element to search:");
   scanf("%d", &m);

   if( array[0] > m | array[n-1] < m)
   {
	printf("\nEntered element is out of array min, max\n");
   }
   else
   {
    	int r = binary(0, n-1, array, m);
   	printf("\nResult: %d\n", r);
   }
 
}
