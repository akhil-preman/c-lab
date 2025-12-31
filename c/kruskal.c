#include<stdio.h>
#include<limits.h>

#define V 4

int parent[V], rank[V];

void makeSet(int x)
{
	parent[x] = x;
	rank[x] = 0;
}

int findSet(int x)
{
	if(x!= parent[x])
		parent[x] =findSet(parent[x]);
	return(parent[x]);
}

void link(int x, int y)
{

	if(x!= y)
	{
		
		if(rank[x]>rank[y])
		{
			parent[y]=x;
		}
		else
		{
			parent[x]=y;
		}
		if(rank[x] == rank[y])
		{
			rank[y] = rank[y]+1;
		}
	}
}

void unionSet(int x,int y)
{
	link(findSet(x), findSet(y));
}

void kruskal(int wg[V][V])
{
	int edge_count = 0, min_cost = 0;

	while(edge_count< V-1)
	{
		int min = INT_MAX, u = -1, v= -1;
		for(int i=0; i<V; i++)
		{
			for(int j=0;j<V; j++)
			{
				if(findSet(i) !=findSet(j) && wg[i][j] < min)
				{
					min = wg[i][j];
					u = i;
					v = j;
				}
			}
		}
		unionSet(u, v);
		printf("%d. (%d, %d) - %d\n", ++edge_count, u, v, min);
		min_cost = min_cost + min;
	}
	printf("minimum cost is : %d\n", min_cost);		
}

int main()
{
	//Adjacency matrix with weights(2D array)
	int wg[V][V] = {
			{INT_MAX,10, 4, 3},
			{10, INT_MAX, INT_MAX, 5},
			{4, INT_MAX, INT_MAX, 12},
			{3, 5, 12, INT_MAX},
		};
	//step 1: Call MakeSet operation
	for(int i=0; i<V;i++)
		makeSet(i);
		
	//MST Creation
	kruskal(wg);
	
	return(0);
}

