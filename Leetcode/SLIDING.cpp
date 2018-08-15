#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int recur(map < vector < vector <int> >, int> &vis, map < vector < vector <int> >, int> &dp, vector < vector <int> > vs)
{
	int n = 2, m = 3, ans = 10000;

	queue < vector < vector <int> > > q;
	dp[vs] = 0;
	q.push(vs);

	while(!q.empty())
		{
			vs = q.front();
			q.pop();

			if(vis[vs]) 
				continue;

			vis[vs] = 1;

			// for(int i = 0; i < 2; i++)
			// 	{ for(int j = 0; j < 3; j++) cout << vs[i][j] << " "; cout << endl; } cout << dp[vs] << endl; cout << endl;

			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 3; j++)
					{
						if(vs[i][j] == 0)
							{
								if(i - 1 >= 0) {
									vector < vector <int> > vs2 = vs;
									swap(vs2[i][j], vs2[i - 1][j]);

									if(!vis[vs2]) {
										dp[vs2] = dp[vs] + 1;
										q.push(vs2);
									}
								}

								if(i + 1 < 2) {
									vector < vector <int> > vs2 = vs;
									swap(vs2[i][j], vs2[i + 1][j]);
									
									if(!vis[vs2]) {
										dp[vs2] = dp[vs] + 1;
										q.push(vs2);
									}
								}

								if(j - 1 >= 0) {
									vector < vector <int> > vs2 = vs;
									swap(vs2[i][j], vs2[i][j - 1]);
									
									if(!vis[vs2]) {
										dp[vs2] = dp[vs] + 1;
										q.push(vs2);
									}
								}

								if(j + 1 < 3) {
									vector < vector <int> > vs2 = vs;
									swap(vs2[i][j], vs2[i][j + 1]);
									
									if(!vis[vs2]) {
										dp[vs2] = dp[vs] + 1;
										q.push(vs2);
									}
								}
							}
					}
		}
	
	return ans;
}

int slidingPuzzle(vector < vector <int> > &board) 
{
	map < vector < vector <int> >, int> vis, dp;
	recur(vis, dp, board);
	vector < vector <int> > vs2(2);

	for(int i = 0; i < 2; i++)
			{
				vs2[i].resize(3);
				for(int j = 0; j < 3; j++)
				{
					if(i == 1 && j == 2) vs2[i][j] = 0;
					else vs2[i][j] = ((3 * i) + (j + 1));
				}
			}

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++) cout << vs2[i][j] << " "; cout << endl;
	}
	int ans = dp[vs2];

	if(!vis[vs2]) ans = -1;
	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int u;

		vector < vector <int> > vs(2);

		for(int i = 0; i < 2; i++)
			{vs[i].resize(3); for(int j = 0; j < 3; j++) cin >> u, vs[i][j] = u;}

		cout << slidingPuzzle(vs) << endl;


		return 0;
	}