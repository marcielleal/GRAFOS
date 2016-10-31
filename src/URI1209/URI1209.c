#include <stdio.h>
#define CONST 10001
int matriz[CONST][CONST]={0};

void zera(){
	int i,j;
	for(i=0;i<CONST;++i)
		for(j=0;j<CONST;++j)
			matriz[i][j]=0;
}

int imprime(int i,int first){
	if(!first)
		printf(" %d",i);
	else
		printf("%d",i);
	return 0;
}
int main(void){
	int n,m,k,a,b,i,j,l,kk=0;
	while((fscanf(stdin, "%d %d %d",&n,&m,&k))!=EOF){
		if(kk){
			zera();
			printf("\n");
		}else kk=1;

		for(i=1;i<=m;++i){
			fscanf(stdin,"%d %d",&a, &b);
			matriz[a][b]=1;
			matriz[b][a]=1;
		}

		int controle=1;
		while(controle){
			controle=0;

			for(i=1;i<=n;++i){
				matriz[i][0]=0;	//Atualiza valores
				for(j=1;j<=n;++j)
					if(matriz[i][j])
						matriz[i][0]++;
			}
			
			for(l=1;l<=n;++l){
				if(matriz[l][0]<k &&matriz[l][0]!=0){
					for(i=1;i<=n;++i)
						matriz[i][l]=0;
					for(j=1;j<=n;++j)
						matriz[l][j]=0;
					matriz[i][0]=0;
					controle=1;
				}
			}
		}
		int first=1;
		for(i=1;i<=n;++i){
			if(matriz[i][0]>=k)
				first=imprime(i,first);
		}

		if(first)
			printf("0");
	}
	return 0;
}
