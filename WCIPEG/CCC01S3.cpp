#include<iostream>
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
#define pb push_back

vector<int> a[107];
bool printed[30][30];
bool graph[30][30];
bool removed[30][30];
bool visited[30];

int dfs(int index)
{
	if(visited[index])
		return 0;

	if(index==2)
		return 1;

	visited[index]=1;

	int i, v, ans=0;
	vector<int>::iterator it;

	for(it=a[index].begin(); it!=a[index].end(); it++)
		{
			v=*it;

			if(removed[index][v])
				continue;

			ans=max(ans, dfs(v));
		}

	return ans;
}

int main()
	{
		string s;
		int u, v, i, j, final=0, num=0, ans;
		char s1, s2;

		while(cin >> s)
			{
				if(s=="**")
					break;

				u=s[0]-'A'+1;
				v=s[1]-'A'+1;

				final=max(final, u);
				final=max(final, v);

				a[u].pb(v);
				a[v].pb(u);
				graph[v][u]=1;
				graph[u][v]=1;
			}


		for(i=1; i<=final; i++)
			{
				for(j=1; j<=final; j++)
					{
						if(graph[i][j] && !printed[i][j])
							{
								memset(visited, 0, sizeof(visited));
								removed[i][j]=1;
								ans=dfs(1);

								if(!ans)
									{
										s1='A'+i-1;
										s2='A'+j-1;
										cout << s1 << s2 << endl;
										printed[i][j]=1;
										printed[j][i]=1;
										num++;
									}

								removed[i][j]=0;
							}
					}
			}

		cout << "There are " << num << " disconnecting roads." << endl;
		return 0;
	}