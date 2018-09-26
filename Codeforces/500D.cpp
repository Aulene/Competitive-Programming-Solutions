#include <bits/stdc++.h>
using namespace std;
#define int long long int
map<pair<int, int>, int> num_paths;
long double summ = 0;
int dfs(int pos, int par, int wt, vector< vector< pair<int, int> > >&adj){
	int num_nodes = 1;
	for(auto i : adj[pos]){
		if(i.first!=par){
			num_nodes += dfs(i.first, pos, i.second, adj);
		}
	}
	int n = adj.size();
	summ += wt * num_nodes * (n-num_nodes);
	num_paths[{pos,par}] = num_nodes * (n-num_nodes);
	num_paths[{par,pos}] = num_nodes * (n-num_nodes);
	return num_nodes;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int n;
	cin>>n;
	vector<pair<int, pair<int, int> > > edges;
	vector< vector< pair<int, int> > > adj(n);
	for(int i = 0; i < n-1; i++){
		int u, v, w;
		cin>>u>>v>>w;
		u--; v--;
		edges.push_back({u,{v,w}});
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dfs(0, 0, 0, adj);
	int q;
	cin>>q;
	while(q--){
		int edge_index;
		int updated_weight;
		cin>>edge_index>>updated_weight;
		edge_index--;
		int previous_weight = edges[edge_index].second.second;
		edges[edge_index].second.second = updated_weight;
		int decrease = updated_weight - previous_weight;
		summ += decrease * num_paths[{edges[edge_index].first, edges[edge_index].second.first}];
		long double ans = 0.0;
		if(n > 3)
			ans = (long double)summ/(long double)(n-1);
		else
			ans = (long double)summ/(long double)(n-2);
		cout<<fixed<<setprecision(12)<<ans<<"\n";
	}
	return 0;
}