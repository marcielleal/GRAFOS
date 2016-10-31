#include <stdio.h>
#include <math.h>
//TODO pensar se os arranjos e matrizes estao sendo reinicializados
typedef struct{
	int x;
	int y;
}Coord;

double relPais[100][100]={0},relPePais[100][100]={0};
int aceitos[100],cinza[100], caminho[100][101]={0};
Coord pbob[100],ppais[100];

double distQuad(Coord c1,Coord c2){
	return sqrt(((c2.x-c1.x)*(c2.x-c1.x))+((c2.y-c1.y)*(c2.y-c1.y)));
}

int main(void){	
	int ins,n,m,i,j,k,l,contAc,contCin,contTotAc=0;
	fscanf(stdin,"%d",&ins);

	while(ins--){
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
		//Para cada ponto de encontro
		double distST,distT;
		for(i=0;i<n-1;++i){//Excluindo o ultimo
			contAc=0;
			distST=2*distQuad(pbob[i],pbob[i+1]);//Dist considerada o dobro, pois o cao anda ate 2x mais rapido
			for(j=0;j<m;++j){
				contCin=0;
				if(relPePais[i][j]+relPePais[i+1][j]<=distST){
					distT=relPePais[i][j];//+relPePais[i+1][j];
					cinza[contCin++]=j;
					for(k=j+1;k<m;++k){
						if(distT+relPePais[i+1][k]+relPais[j][k]<=distST){
							distT+=relPais[j][k];
							cinza[contCin++]=k;
						}
					}
				}
				if(contCin>contAc){
					for(l=0;l<contCin;++l)
						aceitos[l]=cinza[l];
					contAc=contCin;
				}
			}
			for(j=0;j<contAc;++j){
				caminho[i][j]=aceitos[j];
				contTotAc++;
			}
//			if(i==n-2){
			caminho[i][100]=contAc;
//				contTotAc++;
//			}
		}
		//for (i=0;i<100;++i)
			//printf("%d\n",aceitos[i]);
		
		printf("%d\n",contTotAc+n-caminho[n-2][0]+1);
		for(i=0;i<n-1;++i){
			if(i!=0) printf(" ");
			printf("%d %d",pbob[i].x,pbob[i].y);
			k=caminho[i][100];
			if(i!=n-2)
				for(j=0;j<k;++j){
					printf(" %d %d",ppais[caminho[i][j]].x,ppais[caminho[i][j]].y);
				}
			else printf(" %d %d",ppais[caminho[n-2][0]].x,ppais[caminho[n-2][0]].y);
		}
		printf(" %d %d",pbob[n-1].x,pbob[n-1].y);
		printf("\n");
		if (ins)printf("\n");
	}
	return 0;
}
