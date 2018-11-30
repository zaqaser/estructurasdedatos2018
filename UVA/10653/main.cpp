/*implementado con imawe*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <queue>


using namespace std;

int cell[1050][1050];
int row,col;
int visited[1050][1050];

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

void bfs(pair<int,int> s,pair<int,int> d)
{
    int b,i,k,x,y;

    memset(visited,-1,sizeof(visited));

    queue<pair<int,int>> q;
    pair<int,int> a,u;

    q.push(s);
    visited[s.first][s.second] = 0;

    while(!q.empty())
    {
        a = q.front();
        q.pop();

        for(i=0; i<4; i++)
        {
            x = a.first+fx[i];
            y  =a.second+fy[i];

            if(x >= 0 && x < row && y >= 0 && y < col && cell[x][y] != -1 && visited[x][y] == -1)
            {
                visited[x][y] = visited[a.first][a.second]+1;
                u = make_pair(x,y);
                q.push(u);
            }
            if(a.first == d.first&&a.second == d.second) break;
        }
    }
    cout<< visited[d.first][d.second]-visited[s.first][s.second]<<endl ;
}

int main()
{
    int ubi,ro,e,f,g,num;

    while(cin>>row>>col && (row && col))
    {

        memset(cell,0,sizeof(cell));

        scanf("%d",&ubi);
        for(int i=0; i<ubi; i++)
        {
            scanf("%d%d",&ro,&num);
            for(int j=0; j<num; j++)
            {
                scanf("%d",&e);
                cell[ro][e]=-1;
            }
        }
        pair<int,int> s,d;

        scanf("%d%d",&s.first,&s.second);

        scanf("%d%d",&d.first,&d.second);

        bfs(s,d);

    }

}
