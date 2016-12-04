#include <stdio.h>
#define 10000
int mol1[MAX][MAX]={0},mol2[MAX][MAX]={0};

int main(void){
	int n,a,b,maximo,i,j;

	while(1){
		maximo=2*n-2;
		
		scanf("%d",&n);

		for(i=1;i<n;++i){
			scanf("%d %d",&a,&b);
			mol1[a][b]++;
			mol1[b][a]++;
		}
		for(i=1;i<n;++i){
			scanf("%d %d",&a,&b);
			mol2[a][b]++;
			mol2[b][a]++;
		}

		int isDif=0;
		for(i=0;i<MAX;++i){
			for(j=0;j<MAX;++j){
				if(mol1[i][j]!=mol2[i][j]){
					isDif=1;
				}
				//Mais rapido que memset?
				mol1[i][j]=0;
				mol2[i][j]=0;
			}
		}

		if(isDif)
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
}