/**
  * Considerando cada vértice sendo um número (0 a 6) e as arestas sendo
  * as peças. Se conseguirmos achar um caminho euleriano (caminho no qual
  * só uma peça [aresta] é visitada), acharemos a solução do problema. :)
  * @author Marciel Leal
  */

#include <stdio.h>
#include <string.h>

#define MAX 27
#define tamPal 100000

int graph[MAX][MAX], visited[MAX]={0}, in[MAX],out[MAX];
char palavra[tamPal];

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

int main(void){
	int n,i,j,x,y,t;

	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		
		memset(graph, 0, sizeof(graph));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		
		for(i=0;i<n;++i){
			scanf("%s",palavra);
			x=palavra[0]-'a';
			y=palavra[strlen(palavra)-1]-'a';
			//printf(" %c %c\n",palavra[strlen(palavra)-2],y+'a');
			//printf("%s\n",palavra );
			//printf("%c %c\n",x+97,y+97 );
			graph[x][y]++;//=++graph[y][x];
			out[x] = 1;
			in[y] = 1;
		}

		int quantImpares=0,grau;
		for(i=0;i<MAX;++i){
			grau=0;
			for(j=0;j<MAX;++j)
				if(graph[i][j] && i!=j) grau+=graph[i][j];
			if(grau%2==1){//printf("%c %c\n",i+'a',j+'a'); 
			++quantImpares;}
		}

		if(quantImpares!=0 && quantImpares!=2){
			printf("The door cannot be opened.\n");
			continue;
		}

		memset(visited, 0 , sizeof(visited));
		
		//Encontrar um i que exista no grafo

		for(i=0;i<MAX &&!(out[i]||in[i]);i++);
		
		dfs(i);

		int isNotConnected=0;
		for(i=0;i<MAX && !isNotConnected;++i)
			if((in[i]||out[i])&&!visited[i])
				isNotConnected=1;
		
		if(isNotConnected)
			printf("The door cannot be opened.\n");
		else
			printf("Ordering is possible.\n");
	}
	return 0;
}
