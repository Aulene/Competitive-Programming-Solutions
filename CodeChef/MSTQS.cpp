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

lli V;
lli g[2007][2007];
lli org[2007][2007];
lli parent[2007];

lli minKey(lli key[], bool mstSet[])	//geeksforgeeks - http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
{
   lli min = INT_MAX, min_index;
 
   for (lli v = 1; v <= V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 

lli printMST(lli n)	//geeksforgeeks - http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
{
	lli ans=0;

   for (lli i = 1; i <= V; i++)
     	{
     		//cout << i << " " << parent[i] << endl;
     		ans+=g[i][parent[i]];
     	}
  return ans;
}

lli primMST() //geeksforgeeks - http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
{
    
     lli key[V+7];   
     bool mstSet[V+7];  
 
     for(lli i = 1; i <= V; i++)
       	{
       		key[i] = INT_MAX; 
       		mstSet[i] = 0;
       	}
 
     key[1] = 0; 
     parent[1] = -1; 

     for (lli count = 1; count < V-1; count++)
     {
        lli u = minKey(key, mstSet);
        mstSet[u] = true;

        for (lli v = 1; v <= V; v++)
          if (g[u][v] && !mstSet[v] && g[u][v] < key[v])
            	{
            		parent[v]=u;
            		key[v]=g[u][v];
            	}
     }	
     lli ans=0;
 
    	ans=printMST(V);
    	return ans;
}

int main()
	{
		lli n, m, q, i, j, f;
		lli u, v, wt;

		cin >> n >> m >> f;
		V=n;

		while(m--)
			{
				cin >> u >> v >> wt;
				g[u][v]=wt;
				g[v][u]=wt;
			}

		for(i=1; i<=V; i++)
			for(j=1; j<=V; j++)
				org[i][j]=g[i][j];

		while(f--)
			{
				cin >> q;

				if(q==1)
					{
						cin >> u >> v;
						g[u][v]=0;
						g[v][u]=0;
					}
				else if(q==2)
					{
						cin >> u >> v;
						g[u][v]=org[u][v];
						g[v][u]=org[v][u];
					}
				else
					{
						cout << primMST() << endl;
					}
			}
		return 0;
	}