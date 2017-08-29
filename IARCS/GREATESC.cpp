#include<iostream>
#include<cstdio>
#include<climits>
#include<queue>
 
using namespace std;
 
bool connections[3507][3507];
bool visited[3507];
int dist[3507];
int start, finito, n;
 
queue<int> q;
 
int bfs()
{
    int v, i;
 
    dist[start]=0;
    q.push(start);
 
    while(!q.empty())
        {
            v=q.front();
            q.pop();
 
            for(i=1; i<=n; i++)
                {
                    if(connections[v][i]==1 && visited[i]==0)
                        {
                            dist[i]=min(dist[i], dist[v]+1);
                            visited[i]=1;
                            q.push(i);
                        }
                }
        }

    return 0;
}
 
int main()
{
    int i, m, j;
    int node1, node2;
 
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            connections[i][j]=0;
 
    cin >> n >> m;
 
    for(i=0; i<m; i++)
        {
            cin >> node1 >> node2;
            connections[node1][node2]=1;
            connections[node2][node1]=1;
        }
 
    for(i=1; i<=n; i++)
        {
            dist[i]=INT_MAX;
            visited[i]=0;
        }
 
    cin >> start >> finito;
    bfs();
 
    cout << dist[finito] << endl;
    return 0;
}
 