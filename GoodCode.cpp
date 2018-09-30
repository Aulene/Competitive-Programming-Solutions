// -----------
// Bit Operations
// -----------

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
// STL HAX
// -----------

// Erase one element in a multiset mx
auto itr = mx.find(a[i]);
if(itr != mx.end())
    mx.erase(itr);

// Maximum element in a multiset mx
x = *mx.rbegin();
// -----------

// -----------
// Find all Cycles in a Graph
// -----------

vector <int> path;
vector < vector <int> > cycles;
int vis[N];
vvi g(N);

void dfs(int v) 
{
    path.push_back(v);
    vis[v] = 1;
    
    for(int i = 0; i < g[v].size(); i++)
	    {
	    	int u = g[v][i];

	    	if(vis[u] != 2) 
			    {
			        if(vis[u] == 1) 
				        {
				            cycles.emplace_back();

				            int id = path.size() - 1;
				            
				            while(path[id] != u)
				                cycles.back().push_back(path[id--]);

				            cycles.back().push_back(u);
				        } 
			        else
			            dfs(u);
			    }
    	}
    

    path.pop_back();
    vis[v] = 2;
}

// -----------
// Find all Strongly Connected Components (SCCs) in a Directed Graph
// -----------

int onStack[N], low[N], ids[N];
vector < vector <int> > g(N); 
vector < vector <int> > SCCs; // contains all found SCCs
vector <int> path;
stack <int> sx;
int id = 1;

void findSCC(int idx)
{
	/*
	// put next lines in main
	// memset(ids, -1, sizeof(ids));
	// for(i = 1; i <= n; i++)
	// 	if(ids[i] == -1) findSCC(i);
	*/
	
	sx.push(idx);
	onStack[idx] = 1;
	ids[idx] = low[idx] = id++;

	for(int i = 0; i < g[idx].size(); i++) 
		{
			int u = g[idx][i];

			if(ids[u] == -1)
				{
					findSCC(u);
					low[idx] = min(low[idx], low[u]);
				}
			else if(onStack[u]) 
				low[idx] = min(low[idx], ids[u]);
		}

	if(ids[idx] == low[idx]) 
		{
			vector <int> path;

			while(sx.top() != idx) 
				{
					int u = sx.top();
					sx.pop();
					onStack[u] = 0;
					path.pb(u);
				}

			int u = sx.top();
			sx.pop();
			onStack[u] = 0;
			path.pb(u);

			SCCs.emplace_back();
			SCCs.back() = path;
		}
}

// two intersecting segments
bool intersect(int x1, int y1, int x2, int y2)
{
	if(x2 <= x1 && x1 <= y2) return 0;
	if(x2 <= y1 && y1 <= y2) return 0;
	if(x1 <= x2 && x2 <= y1) return 0;
	if(x1 <= y2 && y2 <= y1) return 0;
	return 1;	
}

// Sieve of Eratosthenes

bool prime[N];
vi vs;

void sieve()
{
	for(int i = 2; i < N; i++) prime[i] = 1;

	for(int i = 2; i < N; i++) {
		if(prime[i]) {
			vs.pb(i);
			for(int j = i * i; j < N; j += i) prime[j] = 0;
		}
	}
}
