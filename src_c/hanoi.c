#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*
        Method that recursively moves n elements from one tower to another using a spare tower
*/
void move(int from[], int from_size, char * from_name, int to[], int to_size, char * to_name, int temp[], int temp_size, char * temp_name, int count)
{

        //printf("\n%s: %d, %s: %d, %s: %d, count:%d", from_name, from_size, to_name, to_size, temp_name, temp_size, count);

        if(count > 1) {
            move(from, from_size, from_name, temp, temp_size, temp_name, to, to_size, to_name, count - 1);
        
             from_size = from_size - count +1;
             temp_size = temp_size + count - 1;
        }
        
        printf("\nMove item: %d from: %s to: %s", from[from_size-1], from_name, to_name);

        to[to_size] = from[from_size-1];
        from[from_size-1] = 0 ;
        from_size--;
	    to_size++;

        if(count > 1) {
            move(temp, temp_size, temp_name, to, to_size, to_name, from, from_size, from_name,count - 1);
        }
}

void main(int argc, char *argv[])
{

   int a[] = {4,3,2,1,0,0};
   int b[] = {0,0,0,0,0,0};
   int c[] = {0,0,0,0,0,0};

   move(a, 4, "Tower#1", b, 0, "Tower#2", c, 0, "Temp Tower", 4);  
  
   printf("\n");	    
}
