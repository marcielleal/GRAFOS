/**
  * Considerando cada vértice sendo um número (0 a 6) e as arestas sendo
  * as peças. Se conseguirmos achar um caminho euleriano (caminho no qual
  * só uma peça [aresta] é visitada), acharemos a solução do problema. :)
  * @author Marciel Leal
  */

#include <stdio.h>
#include <string.h>

#define MAX 7

int graph[MAX][MAX], visited[MAX]={0}, existsVertexOnGraph[MAX];

void dfs(int cur){
	visited[cur]=1;
	int i;
	for(i=0;i<MAX;++i){
		//Se esta no grafo e se nao estiver sido visitado	
		if(graph[cur][i]>0 && visited[i]==0)
			dfs(i);
	}
}

int main(void){
	int n,i,j,x,y,t=0;	

	while(1){
		scanf("%d",&n);
		if(!n)
			return 0;
		
		memset(graph, 0, sizeof(graph));
		memset(existsVertexOnGraph, 0, sizeof(existsVertexOnGraph));

		for(i=0;i<n;++i){
			scanf ("%d %d", &x, &y);
			graph[x][y] = ++graph[y][x];
			existsVertexOnGraph[x] = 1;
			existsVertexOnGraph[y] = 1;
		}

		printf ("Teste %d\n", ++t);

		int quantImpares=0,grau;
		for(i=0;i<MAX;++i){
			grau=0;
			for(j=0;j<MAX;++j)
				if(graph[i][j] && i!=j) grau+=graph[i][j];
			if(grau%2==1) ++quantImpares;
		}

		if(quantImpares!=0 && quantImpares!=2){
			printf("nao\n\n");
			continue;
		}

		memset(visited, 0 , sizeof(visited));
		
		//Encontrar um i que exista no grafo
		for(i=0;i<MAX &&!existsVertexOnGraph[i];i++);
		
		dfs(i);

		int isNotConnected=0;
		for(i=0;i<MAX && !isNotConnected;++i)
			if(existsVertexOnGraph[i]&&!visited[i])
				isNotConnected=1;
		
		if(isNotConnected)
			printf("nao\n\n");
		else
			printf("sim\n\n");
	}
	return 0;
}
