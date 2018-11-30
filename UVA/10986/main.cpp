#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define Inf 0x3f3f3f3f
#define Max  99999

typedef pair<int, int> pii;
vector<pii> G[Max];
int d[Max];

void dijkstra(int S){
    int u, v, c, w;
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    memset(d, Inf, sizeof d);
    Q.push(pii(0, S));
    d[S] = 0;
    while(!Q.empty()) {
        u = Q.top().second;
        c = Q.top().first;
        Q.pop();
        if(d[u] < c || d[u] < c) continue;
        for(int i = 0; i < G[u].size(); i++){
            v = G[u][i].first;
            w = G[u][i].second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
}

int main(){
    int N, n, m, u, v, w, S, T, c = 0;
    scanf("%d", &N);
    while(N--){

        scanf("%d %d %d %d", &n, &m, &S, &T);
        for(int i = 0; i <= n; i++) G[i].clear();
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w));
        }
        dijkstra(S);
        if(d[T] == Inf) printf("Case #%d: unreachable\n", ++c);
        else printf("Case #%d: %d\n", ++c, d[T]);
    }
    return 0;
}
