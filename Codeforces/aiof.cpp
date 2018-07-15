int bfs(int s, int e)
{
	queue < pair <int, int> > q;
	q.p(mp(s, 0));

	while(!q.empty())
		{
			pair <int, int> pz = q.front();
			q.pop();

			int u = pz.f, v = pz.s;

			// cout << u << endl;

			for(int i = 0; i < g[u].size(); i++)
				{
					if(dist[g[u][i]] == -1 || dist[g[u][i]] < v + 1)
						{
							dist[g[u][i]] = v + 1;
							q.p(mp(g[u][i], dist[g[u][i]]));
						}
				}
		}

}