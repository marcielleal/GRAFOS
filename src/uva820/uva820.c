#include <stdio.h>
#define V 101		//TODO lembrar de ignorar 0
#define INF 99999

typedef struct{
	int no;
	int min;
	int fluxo;
	int max;
}Vertice;

Vertice graph[V][V];

void imprimeNode(Vertice no){
	printf("%d %d %d %d\n",no.no,no.min,no.fluxo,no.max);
}

int main(void){
	Vertice matriz[3][3];
	Vertice k;
	k.no=1;
	k.min=2;
	k.fluxo=3;
	k.max=4;

	int i;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			matriz[i][j]=k;
			imprimeNode(matriz[i][j]);
		}
	}
	return 0;
}