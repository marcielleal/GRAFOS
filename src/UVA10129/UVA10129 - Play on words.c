/**
  * Considerando cada vértice sendo uma letra e as arestas sendo
  * a "palavra". Se conseguirmos achar um caminho euleriano (caminho no qual
  * só uma palavra [aresta] é visitada), acharemos a solução do problema. :)
  * @author Marciel Leal
  */

#include <stdio.h>
#include <string.h>

#define MAX 27
#define tamPal 1000

unsigned int graph[MAX][MAX], in[MAX],out[MAX];
unsigned int transgraph[MAX][MAX],tin[MAX],tout[MAX];
unsigned int visited[MAX];
unsigned char palavra[tamPal];

void dfs(unsigned int temp[MAX][MAX], unsigned int cur){
	visited[cur]=1;
	int i;
	for(i=0;i<MAX;++i){
		//Se esta no grafo e se nao estiver sido visitado	
		if(temp[cur][i]>0 && visited[i]==0){
			dfs(temp,i);
		}
	}
}

int isStronglyConnected(){
	int i;
	for(i=0;i<MAX;++i)
		if(out[i])
			break;

	memset(visited, 0 , sizeof(visited));
	dfs(graph,i);
    
	for(i=0;i<MAX;++i)
		if(out[i] && !visited[i])
			return 0;

    memset(visited, 0 , sizeof(visited));
    dfs(transgraph,i);

    for(i=0;i<MAX;++i)
		if(tout[i] && !visited[i])
			return 0;
	return 1;
}

int isEulerianPath(){
	int i;

	if(isStronglyConnected()){
		for(i=0;i<MAX;++i)
			if(in[i]!=out[i])
				return 0;
		return 1;
	}
	return 0;
}


int main(void){
	unsigned int n,i,j,x,y,t;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		
		memset(graph, 0, sizeof(graph));
		memset(transgraph, 0, sizeof(transgraph));
		
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		
		for(i=0;i<n;++i){
			scanf("%s",palavra);
			x=palavra[0]-'a';
			y=palavra[strlen(palavra)-1]-'a';
			if(x!=y){
				graph[x][y]++;
				transgraph[y][x]++;
			}
			out[x]++;
			tin[x]++;
			tout[y]++;
			in[y]++;

		}

		if(isEulerianPath())
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
			
	}
	return 0;
}
