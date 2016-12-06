/**
  * Considerando cada vértice sendo um número (0 a 6) e as arestas sendo
  * as peças. Se conseguirmos achar um caminho euleriano (caminho no qual
  * só uma peça [aresta] é visitada), acharemos a solução do problema. :)
  * @author Marciel Leal
  */

#include <stdio.h>
#include <string.h>

#define MAX 27
#define tamPal 1000

unsigned int graph[MAX][MAX], visited[MAX], in[MAX],out[MAX];
unsigned char palavra[tamPal];

void dfs(int cur){
	visited[cur]=1;
	int i;
	for(i=0;i<MAX;++i){
		//Se esta no grafo e se nao estiver sido visitado	
		if(graph[cur][i]>0 && visited[i]==0){
			dfs(i);
		}
	}
}

int isEulerianPath(){
	if(!isStronglyConnected()){
		return 0;
	}

	for(i=0;i<MAX;++i){
		if(in[i]!=out[i])
			return 0;
	}
	return 1;
}

int main(void){
	unsigned int n,i,j,x,y,t;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		
		memset(graph, 0, sizeof(graph));
		memset(visited, 0 , sizeof(visited));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		
		for(i=0;i<n;++i){
			scanf("%s",palavra);
			x=palavra[0]-'a';
			y=palavra[strlen(palavra)-1]-'a';
			if(x!=y)
				graph[x][y]++;
			out[x]++;
			in[y]++;
		}

		
		
		if(isEulerianPath())
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
			
	}
	return 0;
}
