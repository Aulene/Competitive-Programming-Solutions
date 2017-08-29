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

const int nmax = 2e5 + 5;
const int mod = 1e9 + 7;

enum {WHITE, BLACK};

vector < vector < int > > g;
vector < int > color;
int N;


long long dp[nmax][2];

//dp[v][0] : # ways, where the subtree rooted at v have no black nodes
//dp[v][1] : # ways, where the subtree rooted at v has 1 black node

void dfs(int v, int p)
{
	dp[v][0] = 1; // init
	dp[v][1] = 0; // init
	for(auto child : g[v]){
		if(child == p) continue;
		dfs(child, v);
		//We are considering all the "children" whose subtree has no black node.
		dp[v][1] = (dp[v][1] % mod * dp[child][0] % mod)%mod; 
		//Updating the answer for subtree of v with only one black node, 
		//this the second case of having 1 black node
		//which is curr subtree of V don't have a black node and we assume the child has a black node
		dp[v][1] = (dp[v][1] % mod + (dp[v][0] % mod * dp[child][1] % mod)%mod)%mod; 
		//Multiplying the possibilities of no black nodes from every children of v
		dp[v][0] = (dp[v][0] % mod * dp[child][0] % mod)%mod;
	}
	if(color[v] == BLACK) dp[v][1] = dp[v][0]; //We take the subtrees of v where there are no black nodes, as v itself is black
	else dp[v][0] = (dp[v][0] % mod +  dp[v][1] % mod)%mod; //Total cases.
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N; g.resize(N + 1); color.resize(N + 1);
	for(int i = 0; i < N - 1; i++) {
		int p; int child = i + 1; 
		cin >> p;
		g[child].push_back(p);
		g[p].push_back(child);
	}
	for(int i = 0; i < N; i++) cin >> color[i];
	dfs(0, -1);
	cout << dp[0][1] % mod << endl;
	return 0;
}