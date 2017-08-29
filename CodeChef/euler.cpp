#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define ep emplace_back

vector< pair<int, int> > g[100007];
bool e[100007];
vector<int> cycle;

void euler(int v) 
{
    while (!g[v].empty()) 
        {
            auto u=g[v].back();
            g[v].pop_back();

            if(e[u.second]) 
                continue;
            e[u.second]=1;

            euler(u.first);
            cycle.push_back(v);
        }
}

int main() 
{
    int n, m;
    int a, b;

    cin >> n >> m;

    for (int i=0; i<m; i++) 
        {
            cin >> a >> b;
            g[--a].emplace_back(--b, i);
            g[b].emplace_back(a, i);
        }

    for (int i=0; i<n; i++)
        if(g[i].size()%2) 
            {
                cout << "NO" << endl;
                return 0;
            }

    cout << "YES" << endl;

    euler(0);
    for (int i: cycle) 
        printf("%d %d\n", i+1, i+2);
    return 0;
}

