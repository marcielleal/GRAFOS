#include <stdio.h>
#include <string.h>
#define V 5

int graph[V][V]={{0, 1, 0, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 1},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
              };

int used[V]={0};
int match[V]={0};

int dfs(int cur){
	printf("%d ",cur);
	used[cur]=1;
	int i;
	for(i=0;i<V;++i)
		if(graph[cur][i]>0 && used[i]==0)
			dfs(i);
}

int main(void){
	memset(used,0,sizeof(used));
	memset(match,-1,sizeof(match));
	dfs(0);
	return 0;
}