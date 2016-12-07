#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int adj[26][26];
int E;
int In[26];
int Out[26];

std::stack<int> pilha;   
int set[26];
int tos;

void stackClear(){
    while(!pilha.empty())
        pilha.pop();
}

void euler(int u){
    if(Out[u]){
        int v;
        for(v=0;v<26;++v){
            if(adj[u][v]){
                pilha.push(v);
                adj[u][v]=0;
                --Out[u];
                --In[u];
                break;
            }
        }
        euler(v);
    }
}


bool checkEulerPath(){
    int noInicio=0,noFinal=0;
    int start=0, end=0;

    for(int i=0;i<26;i++){
        //Se houver muito mais saidas que entradas (vice-versa)
        if(In[i]>Out[i]+1||In[i]+1<Out[i])
            return false;
        if(In[i]==Out[i]+1){
            noFinal++;
            end=i;
        }
        if(In[i]+1==Out[i]){
            noInicio++;
            start=i;
        }
    }
    if(noInicio==1 && noFinal==1
        ||noInicio==0 && noFinal==0){
        stackClear();
        pilha.push(start);
        while(!pilha.empty()){
            int u=pilha.top();
            pilha.pop();
            euler(u);
        }
    }else
        return false;

    //Grafo vazio
    for(int i=0;i<26;++i)
        for(int j=0;j<26;++j)
            if(adj[i][j])
                return false;
    return true;
}
char palavra[1000];

int main(void){
    int n,i,j,x,y,t;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        
        memset(adj,0,sizeof(adj));
        memset(In,0,sizeof(In));
        memset(Out,0,sizeof(Out));
       
        for(i=0;i<n;++i){
            scanf("%s",palavra);
            x=palavra[0]-'a';
            y=palavra[strlen(palavra)-1]-'a';
            
            adj[x][y]++;
            In[y]++;
            Out[x]++;
        }

        if(checkEulerPath())
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}