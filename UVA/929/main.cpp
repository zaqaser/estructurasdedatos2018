#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define Inf 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector <int> vi;
int posX[4]={-1,0,1,0};
int posY[4]={0,1,0,-1};
int N,Z;
bool validPos(int x, int y){
    return ((x>=0 && x<N) && (y>=0 && y<Z));
}void dijkstra(piii s, vector<vi> *dist, vector<vi> *graph){
    priority_queue<piii, vector<piii>, greater<piii>> Q;
    Q.push(s);
    while (!Q.empty()){
        piii front = Q.top();
        Q.pop();
        int d = front.first;
        pii u = front.second;
        if (d == dist->at(u.first)[u.second])
            for (int j = 0; j < 4; j++){
                int newX =u.first + posX[j];
                int newY =u.second + posY[j];
                if(validPos(newX,newY)){
                    int v = graph->at(newX)[newY];
                    if(dist->at(u.first)[u.second] + v < dist->at(newX)[newY]){
                        dist->at(newX)[newY] = dist->at(u.first)[u.second] + v;
                        pii newV (newX,newY);
                        Q.push(piii(dist->at(newX)[newY], newV));
                    }}}}}
int main(){
    int n, num;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&N);
        scanf("%d",&Z);
        vector<vi> graph;
        for (int i = 0; i < N; ++i)
        {
            vi row;
            for (int j = 0; j < Z; ++j)
            {
                scanf("%d",&num);
                row.push_back(num);
            }
            graph.push_back(row);
        }
        vi rowIni(Z,Inf);
        vector<vi> dist (N,rowIni);
        dist[0][0] = graph[0][0];
        dijkstra(piii(graph[0][0],pii(0,0)),&dist,&graph);
        printf("%d\n",dist[N-1][Z-1]);

    }
 return 0;
}
