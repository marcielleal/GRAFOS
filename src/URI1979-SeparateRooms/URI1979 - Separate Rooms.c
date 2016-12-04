#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX 101

int conj1[MAX],conj2[MAX];

int main(void){
	int k,i,j,n,m,a,teste,erro;
	char c;
	
	while(1){
		scanf("%d",&n);

		if(!n)
			break;
		
		memset(conj1,0,sizeof(conj1));
		memset(conj2,0,sizeof(conj2));
		erro=0;
		teste=0;

		for(k=0;k<n;++k){
			scanf("%d", &a);
			
			if(conj1[a]){
				teste=1;
				//printf("Entrou no conj1[a] teste=1 %d\n",a );
			}
			else if(conj2[a]){
				teste=0;
				//printf("Entrou no conj1[a] teste=0 %d\n",a );
			}
			else{
				//printf("Entrou no else %d\n",a );
				conj1[a]=1;
				teste=1;
			}
			
			//Le linha
			while(scanf("%d%c",&m,&c)==2){
				//printf("%d %d\n",a,m);
				if(teste){
					if(conj1[m]){
						//printf("break no teste\n");
						erro=1;
					}else{
						conj2[m]=1;
						//printf("Entrou no teste else %d\n",m );
					}
				}else{
					if(conj2[m]){
						//printf("break no else\n");
						erro=1;
					}else{
						conj1[m]=1;
						//printf("Entrou no else else %d\n",m );
					}
				}

				if(c=='\n'){
					//printf("quebra de linha\n");
					break;
				}
			}//imprime();
		}
		if(!erro)
			printf("SIM\n");
		else
			printf("NAO\n");
		
		//clear();
	}
  	return 0;
}