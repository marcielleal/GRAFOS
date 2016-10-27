#include <stdio.h>
#include <limits.h>
#define MAX 4

int matriz[MAX][MAX]={0};
int i,j,k;

void preencher(){
	for(i=0;i<MAX;++i){
		for(j=0;j<MAX;++j){
			//if(i!=j) matriz[i][j]=INT_MAX;
			//else 
			matriz[i][j]=INT_MAX;
		}
	}
}
void imprime(){
	for(i=0;i<MAX;++i){
		for(j=0;j<MAX;++j){
			printf("%d ",matriz[i][j]);
		}printf("\n");
	}printf("FIM\n");
}

int main(void){
	preencher();
	matriz[0][1]=2;
	matriz[1][0]=2;
	matriz[0][2]=4;
	matriz[2][0]=4;
	matriz[1][3]=1;
	matriz[3][1]=1;
	matriz[2][3]=5;
	matriz[3][2]=5;

	imprime();

	for(k=0;k<MAX;++k){
		for(i=0;i<MAX;++i){
			for(j=0;j<MAX;++j){
				if(matriz[i][j]>matriz[i][k]+matriz[k][j])
					matriz[i][j]=matriz[i][k]+matriz[k][j];
				imprime();			
			}
		}
	}
/*
	int maior=-1;
	for(i=0;i<MAX;++i){
		printf("%d ",matriz[i][MAX]);
		if(maior<matriz[i][MAX])
			maior=matriz[i][MAX];
	}
	printf("\n%d\n",maior);*/

	return 0;	
}
	
