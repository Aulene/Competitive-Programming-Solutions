//Aulene
//Kruskal was basically plagiarised from HackerEarth since I learnt it from there
 
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
 
int a[2007][2007];
bool vis[2007][2007];
lli roots[2007];
pair< int, pair <int, int > > p[2000007];
 
int root(int x)
{
    while(roots[x]!=x)
            {
                    roots[x]=roots[roots[x]];
                    x=roots[x];
            }
    return x;
}
 
lli kruskal(int n)
{
    int x, y, i, f, q;
    lli cost, minCost=0;

    for(i=0; i<n; i++)
        {
            x=p[i].second.first;
            y=p[i].second.second;
            cost=p[i].first;

            f=root(x);
            q=root(y);

            if(f!=q)
                {
                        minCost+=cost;
                        roots[f]=roots[q];
                }
        }

    return minCost;
}
 
int main()
    {
        lli n, i, j, x=0;
        lli ans;

        cin >> n;

        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);

        for(i=1; i<=n; i++)
            roots[i]=i;

        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(!vis[i][j] && i!=1 && j!=1 && i!=j) //ensure that 1 isn't present cuz its useless and stuff
                    {
                        p[x]=mp(a[i][j], mp(i, j));
                        vis[i][j]=1;
                        vis[j][i]=1;
                        x++;
                    }
        
        sort(p, p+x);
        ans=kruskal(x);

        cout << ans << endl;

        return 0;
    }