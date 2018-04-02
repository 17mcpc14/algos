#include<stdlib.h>
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

int * results = malloc(sizeof(int) * count);
int x = 0;
void binary(int length, int array[], int count, int items[], int l , int r)
{
  if(l>r) return;
  int m = (l+r)/2;
  printf("m:%d",m);
  int i;
  for(i=0; i < count; i++)
  {
     if( array[m] == items[i])
     {
        results[x] = items[i];
     } 
  }
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
 
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
   int array[n];

   printf("Enter %d elements\n", n);
 
   for ( c = 0 ; c < n ; c++ )
   {
      scanf("%d", &array[c]);
   }

   printf("Enter number of elements to search\n");
   scanf("%d", &m);
   int items[m];

   printf("Enter %d elements\n", m);
 
   for ( c = 0 ; c < m ; c++ )
   {
      scanf("%d", &items[c]);
   }
   
   int * results;
   printf("\nPlease provide your input! \n(1) Linear Search \n(2) Binary Sarch \n(5) Exit\n");
   scanf("%d", &c);
   if(c == 1)
   {
	results = linear(n, array, m, items);
        print(results, m);
   }
   else if(c == 2)
   {
        results = binary(n, array, m, items);
	print(results, m);
   }  
 
}
