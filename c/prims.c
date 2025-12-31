#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 4

int parent[V], key[V];
bool selected[V];

void init()
{
	for(int i=0; i<V; i++)
	{
		parent[i]= -1;
		key[i] = INT_MAX;
		selected[i] = false;
	}
}
int extractMin(int key[V], bool selected[V])
{
	int min=INT_MAX, min_indx = 0;
	for(int i=0; i<V; i++)
	{
		if(selected[i] == false && key[i] < min)
		{
			min = key[i];
			min_indx = i;
		}
	}
		return(min_indx);
	
}
void printMST(int parent[V], int wg[V][V])
{
	int cost = 0;
	for(int i=1; i<V; i++)
	{	
		printf("%d. (%d,%d) - %d\n",i, parent[i], i, wg[parent[i]] [i]);
		cost = cost + wg[parent[i]][i];
	}
	printf("Minimum cost is: %d", cost);
}
void prim(int wg[V][V], int root)
{	init();
	key[root] = 0;
	for(int count=0; count<V-1; count++)
	{
		int u;
		u = extractMin(key, selected);
		selected[u] = true;
		
		for(int v=0; v<V; v++)
		{
			if(wg[u][v] > 0)
			{
				if(!selected[v] && wg[u][v] < key[v])
				{
					parent[v] =u;
					key[v] = wg[u][v];
				}
			}
		}
	}
	printMST(parent, wg);
}
int main()
{
	//adjacency matrix with weighted 2d array
	int wg[V][V] = {
			{0, 10, 4, 3},
			{10, 0, 0, 5},
			{4, 0, 0, 12},
			{3, 5, 12, 0},
		};
	prim(wg,0);	
	return(0);
}

