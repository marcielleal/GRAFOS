#include <stdio.h>
#include <math.h>
#include <string.h>
#define V 101

typedef struct{
	int x;
	int y;
}Coord;

double relPais[100][100]={0},relPePais[100][100]={0};
Coord pbob[100],ppais[100];

int used[V]={0};
int matchx[V];
int matchy[V];
int graph[V][V];

void zeraGraph(){
	for (int i = 0; i < V; ++i){
		for (int j = 0; j < V; ++j){
			graph[i][j]=0;
		}
	}
}

double distQuad(Coord c1,Coord c2){
	return sqrt(((c2.x-c1.x)*(c2.x-c1.x))+((c2.y-c1.y)*(c2.y-c1.y)));
}

//Dfs com emparelhamento
int dfs(int cur){
    int i,v;
    for(i=0;i<graph[cur][100];++i){
        v=graph[cur][i];
        //Se i eh adjacente a cur e se i nao ja estiver sido usado
        if(used[v]==0){
            used[v]=1;
            //Se i nao tiver sido emparelhado ou se eh possivel emparelhar o cara que esta emparelhado com i
            if(matchy[v]<0 || dfs(matchy[v])){
               matchy[v]= cur;//"Emparelha" cur com i
               matchx[cur]=v;
               return 1;
            }
        }
    }return 0;
}

int main(void){	
	int ins,n,m,i,j,k,l,contAc,contCin,contTotAc=0;
	fscanf(stdin,"%d",&ins);

	while(ins--){
		zeraGraph();
		/* Leitura */
		fscanf(stdin,"%d %d",&n,&m);

		for(i=0;i<n;++i)
			fscanf(stdin,"%d %d",&pbob[i].x,&pbob[i].y);
		
		for(i=0;i<m;++i){
			fscanf(stdin,"%d %d",&ppais[i].x,&ppais[i].y);
			for(j=0;j<n;++j)//Relacionam. de dist ponto de encontro e paisagem
				relPePais[j][i]=distQuad(pbob[j],ppais[i]);

			for(j=0;j<i;++j){//Calcula a dist de todos os novos nos aos que ja estavam
				relPais[i][j]=distQuad(ppais[i],ppais[j]);
				relPais[j][i]=relPais[i][j];
			}
		}
		/*------------------------------------*/
		
		memset(matchx,-1,sizeof(matchx));
		memset(matchy,-1,sizeof(matchy));

		double distST;
		for(i=0;i<n-1;++i){
			distST=2*distQuad(pbob[i],pbob[i+1]);
			for(j=0;j<m;++j){
				if(distST>= relPePais[i][j]+relPePais[i+1][j])
					graph[i][graph[i][100]++]=j;//A coluna 100 guarda o total de elementos na linha
			}
		}

		contAc=0;
		for(i=0;i<n-1;++i){
			if(matchx[i]==-1){
				memset(used,0,sizeof(used));
				if(dfs(i))
					contAc++;
			}
		}
		
		printf("%d\n",contAc+n);
		for(int i = 0; i<n; ++i){
			if(i!=0) printf(" ");
			printf("%d %d", pbob[i].x,pbob[i].y);
			if(matchx[i]>=0)
				printf(" %d %d",ppais[matchx[i]].x,ppais[matchx[i]].y );
		}
		printf("\n");
		if(ins) printf("\n");
	}
	return 0;
}
