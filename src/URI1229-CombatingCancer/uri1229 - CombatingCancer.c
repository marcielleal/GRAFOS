#include <stdio.h>
#define MAX 10001

typedef struct {
	int v,grau;
}grauVert;

int mol1[MAX][MAX],mol2[MAX][MAX];
int rel[MAX];
grauVert grau1[MAX],grau2[MAX];

void clear(){
	int i,j;
	for(i=0;i<MAX;++i){
		for(j=0;j<MAX;++j){
			mol1[i][j]=0;
			mol2[i][j]=0;
		}
		rel[i]=0;
	}
}

void selection(int v[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(v[i]>v[j]){ 
				temp=v[i];
				v[i]=v[j];
				v[j]=temp;
			}
		}
	}
	
}

int main(void){
	int n,a,b,i,j;

	while(scanf("%d",&n)==1){
		clear();
		for(i=1;i<n;++i){
			scanf("%d %d",&a,&b);
			mol1[a][b]++;
			mol1[b][a]++;
			grau1[a].v=a;
			grau1[a].grau++;
			grau1[b].v=b;
			grau1[b].grau++;
		}
		for(i=1;i<n;++i){
			scanf("%d %d",&a,&b);
			mol2[a][b]++;
			mol2[b][a]++;
			grau2[a].v=a;
			grau2[a].grau++;
			grau2[b].v=b;
			grau2[b].grau++;
		}

		

	}


	return 0;
}