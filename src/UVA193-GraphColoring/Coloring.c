#include <stdio.h>
#include <string.h>
#define MAX 101

int graph[MAX][MAX];
int wasColored[MAX];
int color[MAX];
int qFinal;
int listBlacks[MAX];

int canBlack(int i, int n){
	int j;
	for(j=0;j<n;++j){
		if(graph[i][j] && wasColored[i] && color[j]==1){
			return 0;
		}
	}return 1;
}

void fill(int i, int n){
	if(i<n){
		wasColored[i]=1;
		if(canBlack(i,n)){
			color[i]=1;
			fill(i+1,n);
		}

		color[i]=0;
		fill(i+1,n);
		wasColored[i]=0;
	}else{
		int qblacks = 0,k;
		for (k = 0; k < n; k++) {
			if (color[k] == 1)
				qblacks++;
		}

		if (qblacks > qFinal) {
			int j=0;
			qFinal = qblacks;
			for (k = 0; k < n; k++) {
				if (color[k] == 1)
					listBlacks[j++]=k;
			}
		}
	}
}


int main(void){
	int t,n,k,x,y,i;

	scanf("%d",&t);
	while(t--){
		scanf("%d %d", &n,&k);

		memset(graph,0,sizeof(graph));
		memset(wasColored,0,sizeof(wasColored));
		memset(color,0,sizeof(color));
		memset(listBlacks,0,sizeof(listBlacks));
		qFinal=-1;

		for(i=0;i<k;++i){
			scanf("%d %d",&x,&y);
			x--;y--;
			graph[x][y]++;
			graph[y][x]++;
		}

		fill(0,n);
		
		printf("%d\n",qFinal );

		for(i=0;i<qFinal;++i){
			if(i!=0)
				printf(" %d", listBlacks[i]+1);
			else
				printf("%d", listBlacks[i]+1);
		}
		printf("\n");

	}
	return 0;
}