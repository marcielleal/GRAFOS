#include <stdio.h>
#include <string.h>
#define V 1001

int graph[V][V]={0};

int used[V]={0};
int match[V];

void zeraGraph(){
    int i,j;
    for(i=0;i<V;++i)
        for(j=0;j<V;++j)
            graph[i][j]=0;
}

void imprime(int n){
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)
            printf("%d\t",graph[i][j]);
        printf("\n");
    }printf("\n");
}


//Dfs com emparelhamento
int dfs(int cur,int tam, int* numEmp){
    int i;
    for(i=1;i<=tam;++i){
        //Se i eh adjacente a cur e se i nao ja estiver sido usado
        if(graph[cur][i] && used[i]==0){
            used[i]=1;
            //Se i nao tiver sido emparelhado ou se eh possivel emparelhar o cara que esta emparelhado com i
            if(match[i]<0 || dfs(match[i],tam,numEmp)){
               match[i]= cur;//"Emparelha" cur com i
               match[cur]=i;
               (*numEmp)++;
               return 1;
            }
        }
    }return 0;
}

int minEmp(int tam)
{
    int min=1000,numEmpAtual=0,i;
    memset(match,-1,sizeof(match));

    for(i=1;i<=tam;++i){
        memset(used, 0, sizeof(used));
        dfs(i,tam,&numEmpAtual);
    }
    return numEmpAtual;
}
 
// Driver program to test above functions
int main()
{
    int t,i,j,n,m,x,y;
    fscanf(stdin,"%d",&t);
    while(t--){
        zeraGraph();
        fscanf(stdin,"%d %d",&n,&m);
        for(i=0;i<m;++i){
            fscanf(stdin,"%d %d",&x,&y);
            graph[x][y]=1;
            graph[y][x]=1;
        }
        printf("%d",minEmp(n));
        if(t) printf("\n");
    }
 
    return 0;
}
