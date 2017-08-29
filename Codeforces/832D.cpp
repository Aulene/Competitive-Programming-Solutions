#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

void build(int start, vector <int> &segtree, vector <int> &lv, int left, int right) 
{
	if(int(segtree.size()) - 1 < start)
		segtree.resize(start + 1);
	if(left == right)
		segtree[start] = left;
	else 
		{
			build(2 * start, segtree, lv, left, (right + left) / 2);
			build(2 * start + 1, segtree, lv, (right + left) / 2 + 1, right);
			
			if(lv[segtree[start * 2]] < lv[segtree[start * 2 + 1]])
				segtree[start] = segtree[start * 2];
			else 
				segtree[start] = segtree[start * 2 + 1];
		}

	return;
}

int rmq(int start, vector <int> &segtree, vector <int> &lv, int u, int v, int left, int right) 
{
	if (v < left || u > right)
		return -1;

	if (left >= u && right <= v)
		return segtree[start];

	int t1 = rmq(2 * start, segtree, lv, u, v, left, (right + left) / 2);
	int t2 = rmq(2 * start + 1, segtree, lv, u, v, (right + left) / 2 + 1, right);

	if(t1 == -1) return t2;
	if(t2 == -1) return t1;
	if(lv[t1] < lv[t2]) return t1;
	return t2;
}

int dfs(vector < vector <int> > &graph, vector <int> &tour, int root, vector <int> &startNode, vector <int> &lv, vector <int> &vis, int current) 
{
	int i;
	vis[root] = 1;

	tour.pb(root);
	lv.pb(current);
	
	startNode[root] = int((tour).size())  - 1;

	for(i = 0; i <= int(graph[root].size()) - 1; i++) 
		if(!vis[graph[root][i]]) 
			{
				dfs(graph, tour, graph[root][i], startNode, lv, vis, current + 1);
				tour.pb(root);
				lv.pb(current);
			}

	return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, p, a, b, c, f2b, f2s, s2t, seq1, seq2, seq3, ans1, ans2, ans3;

    cin >> n >> q;
    vector < vector <int> > graph(n + 1);

    for(i = 2; i <= n; i++)
	    {
	        cin >> p;
	        graph[i].pb(p);
	        graph[p].pb(i);
	    }

    vector <int> tour, lv;
    vector <int> startNode(n + 1), vis(n + 1, 0), segtree;

	dfs(graph, tour, 1, startNode, lv, vis, 0);
	build(1, segtree, lv, 0, int(lv.size()) - 1);

	while(q--)
		{
		    cin >> a >> b >> c;
		    f2b = tour[rmq(1, segtree, lv, min(startNode[a], startNode[b]), max(startNode[a], startNode[b]), 0, int(lv.size()) - 1)];
		    f2s = tour[rmq(1, segtree, lv, min(startNode[a], startNode[c]), max(startNode[a], startNode[c]), 0, int(lv.size()) - 1)];
		    s2t = tour[rmq(1, segtree, lv, min(startNode[c], startNode[b]), max(startNode[c], startNode[b]), 0, int(lv.size()) - 1)];
		    
		    seq1 = lv[startNode[a]] + lv[startNode[b]] - lv[startNode[f2b]] * 2;
		    seq2 = lv[startNode[a]] + lv[startNode[c]] - lv[startNode[f2s]] * 2;
		    seq3 = lv[startNode[b]] + lv[startNode[c]] - lv[startNode[s2t]] * 2;
		    
		    ans1 = (seq1 + seq2 - seq3) / 2;
		    ans2 = (seq1 + seq3 - seq2) / 2;
		    ans3 = (seq3 + seq2 - seq1) / 2;

		    cout << max(ans1, max(ans2, ans3)) + 1 << endl;
		}

    return 0;
}