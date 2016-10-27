#include<stdio.h>
#define INF 99999
#define V 4
int graph[V][V],vetor[V];

void imprime(){
	int i,j;
	for(i=0;i<V;++i){
		for(j=0;j<V;++j)
			printf("%d\t",graph[i][j]);
		printf("\n");
	}
}

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
	}imprime();
	

	//Floyd-Warshall
	for(k=0;k<n;++k){
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				if(graph[i][k]+graph[k][j]<graph[i][j])
					graph[i][j]=graph[i][k]+graph[k][j];
			}
		}
	}

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
	/*graph[0][1]=22;
	graph[1][0]=22;
	graph[0][2]=30;
	graph[2][0]=30;
	graph[0][5]=35;
	graph[5][0]=35;
	graph[1][5]=11;
	graph[1][5]=11;
	graph[1][6]=30;
	graph[6][1]=30;
	graph[1][2]=25;
	graph[2][1]=25;
	graph[2][3]=15;
	graph[3][2]=15;
	graph[2][6]=10;
	graph[6][2]=10;
	graph[3][4]=15;
	graph[4][3]=15;
	graph[3][5]=10;
	graph[5][3]=10;
	graph[4][5]=20;
	graph[5][4]=20;
	graph[5][6]=33;
	graph[6][5]=33;
	*/

	printf("%d",menor);
	return 0;
}

