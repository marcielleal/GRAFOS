#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX 101

int graph[MAX][MAX];
int color[MAX];

int isBipartite(int src,int n){
	int i,v;

	color[src] = 1;

	std::queue <int> q;
	q.push(src);

	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		for (v=0;v<n;++v){
			if (graph[u][v] && color[v] == -1){
				color[v]= 1-color[u];
				q.push(v);
			}

			else if (graph[u][v] && color[v] == color[u])
				return 0;
		}
	}
	return 1;
}

int main(void){
	int k,i,j,n,m,a,teste,erro;
	char c;
	
	while(1){
		scanf("%d",&n);

		if(!n)
			break;
		
		memset(graph,0,sizeof(graph));
		memset(color,-1,sizeof(color));

		for(k=0;k<n;++k){
			scanf("%d", &a);
			a--;
			while(scanf("%d%c",&m,&c)==2){
				m--;
				graph[a][m]++;
				graph[m][a]++;
				if(c=='\n'){
					break;
				}
			}
		}
		if(isBipartite(0,n))
			printf("SIM\n");
		else
			printf("NAO\n");
		
	}
  	return 0;
}