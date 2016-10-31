#include <iostream>
#include <queue>
#define V 4

int graph[V][V]={{0,1,0,1},
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                };

bool bfs(int start){
    std::queue<int> q;
    bool visited[V];
    q.push(start);

    int cur;
    while(!q.empty()){
        cur=q.front();

        for(int i=0;i<V;++i){
            if(graph[cur][i]!=0 && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }

        q.pop();
        std::cout<<cur<<std::endl;
    }
}

int main(void){
    bfs(0);
    return 0;
}
