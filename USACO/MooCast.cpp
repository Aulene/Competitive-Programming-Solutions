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
#include<fstream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

struct cow
{
	int x, y;
	int power;
};

cow a[207];
bool visited[207];
int n;

int dfs(int index)
{
	int i=0, diff, ans=1;

	if(visited[index])
		return 0;

	visited[index]=1;

	for(i=1; i<=n; i++)
		{
			diff=ceil(sqrt(pow(abs(a[i].x-a[index].x), 2)+pow(abs(a[i].y-a[index].y), 2)));
			//cout << index << " " << i << " " << diff << endl;
			//cout << a[index].power << endl;
			if(diff<=a[index].power)
				dfs(i);
		}

	return ans;
}

int main()
	{
		ifstream fin ("moocast.in");
		ofstream fout ("moocast.out");

		int i, ans=0, j, f;
		fin >> n;

		for(i=1; i<=n; i++)
			fin >> a[i].x >> a[i].y >> a[i].power;

		for(i=1; i<=n; i++)
			{
				f=0;

				for(j=0; j<207; j++)
					visited[j]=0;

				dfs(i);

				for(j=1; j<=n; j++)
					{
						//cout << visited[j] << " ";
						if(visited[j])
						f++;
					}
				//cout << endl;

				ans=max(ans, f);
				//cout << ans << endl;
			}
		fout << ans << endl;
		return 0;
	}