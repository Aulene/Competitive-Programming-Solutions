// Find all cycles in a graph

vector <int> path;
vector < vector <int> > cycles;

void dfs(int v) 
{
    path.push_back(v);
    vis[v] = 1;

    int u = a[v];
    
    if(vis[u] != 2) 
	    {
	        if(vis[u] == 1) 
		        {
		        	vector <int> vs;
		            cycles.__emplace_back(vs);

		            int id = path.size() - 1;
		            
		            while(path[id] != u)
		                cycles.back().push_back(path[id--]);

		            cycles.back().push_back(u);
		        } 
	        else
	            dfs(u);
	    }

    path.pop_back();
    vis[v] = 2;
}
