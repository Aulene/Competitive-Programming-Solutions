// Bit Operations

// Total number of set bits
u =  __builtin_popcount(n);

// Multiply by 2
n = n << 1;

// Divide by 2
n = n >> 1;

// Turn off rightmost set bit
n = n & (n - 1);

// Set ith bit
n = n | (1 << i);

// Unset ith bit
n = n & !(1 << i);

// Check if ith bit is set
u = n & (1 << i); // non-zero if set

// Find rightmost set bit
u = log2(n & -n) + 1;

// Find leftmost (most significant) set bit
u = (int)(log2l(n)) + 1;

// ----------

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
