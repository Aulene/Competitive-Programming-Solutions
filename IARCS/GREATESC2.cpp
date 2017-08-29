#include<iostream>
 
using namespace std;
 
bool graph[3507][3507];
bool visited[3507];
int dist[3507];
int start, v, n;
 

 
int main()
{
    int i, m, j;
    int node1, node2;
 
    cin >> n >> m;
 
    while(m--)
        {
            cin >> node1 >> node2;
            graph[node1][node2] = 1;
            graph[node2][node1] = 1;
        }
 
    for(i = 1; i <= n; i++)
        {
            dist[i] = 1000000;
            visited[i] = 0;
        }
 
    cin >> start >> v;
    
    int ans = dfs(start);
    
    if(ans == 1000000)
        ans = 0;

    cout << ans << endl;
    return 0;
}
 