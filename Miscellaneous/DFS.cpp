int dfs(int src)
{
	if(vis[src]) return 0;

	vis[src] = 1;

	for(int i = 0; i < g[src].size(); i++) dfs(g[src][i]);
		return 0;
}