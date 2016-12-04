#include <stdio.h>
#include <string.h>
#define MAX 101

int graph[MAX][MAX]={0},matchy[MAX], matchx[MAX],used[MAX];
int entry1[MAX],entry2[MAX];

//Dfs com emparelhamento
int FindMatch(int cur, int m){
    int i;
    for(i=0;i<m;++i){
        //Se i eh adjacente a cur e se i nao ja estiver sido usado
        if(graph[cur][i] && !used[i]){
            used[i]=1;
            //Se i nao tiver sido emparelhado ou se eh possivel emparelhar o cara que esta emparelhado com i
            if(matchy[i]<0 || FindMatch(matchy[i],m)){
               matchy[i]= cur;//"Emparelha" cur com i
               matchx[cur]=i;
               return 1;
            }
        }
    }return 0;
}


int BipartiteMatching(int n,int m) {
  	memset(matchx,-1,sizeof(matchx));
  	memset(matchy,-1,sizeof(matchy));

    int counter = 0;
    for (int i = 0; i < n; i++) {
		memset(used,0,sizeof(used));
    	if (FindMatch(i,m)) 
    		counter++;
  	}
  	return counter;
}

int main(void){
	int t,k,i,j,n,m;
	scanf("%d",&t);

	for(k=1;k<=t;++k){
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d", &entry1[i]);
		
		scanf("%d", &m);
		for (int i=0; i<m; ++i)
			scanf("%d", &entry2[i]);
		
		memset(graph,0,sizeof(graph));

		for(i=0;i<n;++i){
			for(j=0;j<m;++j){
				if(entry1[i]!=0){
					if(entry2[j]%entry1[i]==0)
						graph[i][j]=1;
				}else{
					if(entry2[j]==0)
						graph[i][j]=1;
				}
			}
		}
		printf("Case %d: ",k);
		printf("%d\n",BipartiteMatching(n,m));
	}

  	return 0;
}