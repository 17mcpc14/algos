#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
  

int minDistance(int dist[], int sptSet[], int V)
{
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
   {
     	if (sptSet[v] == 0 && dist[v] <= min)
	{
        	min = dist[v], min_index = v;
	}	 
   }
   return min_index;
}
  
int printSolution(int dist[],int V)
{
   printf("\nDistance from Sources :");
   for (int i = 0; i < V; i++)
   {
      printf("\n%d -> %d ", i, dist[i]);
   }	  
}
  
void dijkstra(int * graph, int src, int V)
{
     int dist[V];    
     int sptSet[V]; 
     for (int i = 0; i < V; i++)
     {
          dist[i] = INT_MAX, sptSet[i] = 0;
     }	
  
     dist[src] = 0;
  
     for (int count = 0; count < V-1; count++)
     {
        int u = minDistance(dist, sptSet, V);
  
        sptSet[u] = 1;
  
        for (int v = 0; v < V; v++)
        {
	    if (sptSet[v] == 0 && graph[u*V+v] && dist[u] != INT_MAX && dist[u]+graph[u*V+v] < dist[v])
	    {							   
           	 dist[v] = dist[u] + graph[u*V+v];
	    }
	}
     }
  
     printSolution(dist, V);
}
  
int main()
{
   int i, j, V;
   printf("\nPlease enter number of edges in the graph : ");
   scanf("%d", &V);
         
   printf("\nPlease enter the graph ( matrix of %d x %d ) : ", V, V);

   int * graph = (int*)malloc(sizeof(int)*V*V);

   for(i =0; i <V; i++)
   {
	for(j=0; j <V; j++)
	{
	   scanf( "%d", graph+(i*V+j) );
        }
   }
   
   dijkstra(graph, 0, V);
  
   return 0;
}
