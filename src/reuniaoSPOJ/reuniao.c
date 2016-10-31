#include<stdio.h>
#define INF 99999
#define V 100
int graph[V][V],vetor[V];


int min(int a,int b){
	return a<b?a:b;
}

int main(){
	int i,j,k,n,m,cont,x,y,p;
	
	for(i=0;i<V;++i)
		for(j=0;j<V;++j)
			graph[i][j]=INF;
	
	//Leitura
	while(fscanf(stdin,"%d %d",&n,&m) !=EOF){
		for(cont=0;cont<m;++cont){
			fscanf(stdin,"%d %d %d",&x,&y,&p);
			if(graph[x][y]==INF && graph[y][x]==INF){
				graph[x][y]=p;
				graph[y][x]=p;
			}else{
				graph[x][y]=min(graph[x][y],p);
				graph[y][x]=min(graph[y][x],p);
			}
		}
	}
	

	//Floyd-Warshall
	for(k=0;k<n;++k)
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				if(graph[i][k]+graph[k][j]<graph[i][j])
					graph[i][j]=graph[i][k]+graph[k][j];
			
		
	

	int menor;
	for(i=0;i<n;++i){
		vetor[i]=0;
		for(j=0;j<n;++j)
			if(vetor[i]<graph[i][j])
				vetor[i]=graph[i][j];
	}
	menor=vetor[0];
	for(i=0;i<n;++i)
		if(menor>vetor[i])
			menor=vetor[i];	
	
	printf("%d",menor);
	return 0;
}

