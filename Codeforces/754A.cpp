#include<iostream>
#include<fstream>
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
#define p push
#define pb push_back
#define mp make_pair

int a[107];
bool dp[107][107];
bool printed=0;
int n;

int recur(int index, vector< pair <int, int > > ans)
{
	if(index>n)
		{
			vector < pair <int, int > >::iterator it;
			printed=1;

			cout << "YES" << endl;
			cout << ans.size() << endl;
			for(it=ans.begin(); it!=ans.end(); it++)
				cout << it->first << " " << it->second << endl;

			exit(0);
		}

	int i;
	vector <pair <int, int > > ans1;

	for(i=index; i<=n; i++)
		if(dp[index][i])
			{
				ans1=ans;
				ans1.pb(mp(index, i));
				recur(i+1, ans1);
			}

	return 0;
}

int main()
	{
		int i, j;
		vector <pair <int, int > > x;

		cin >> n;

		for(i=1; i<=n; i++)
			cin >> a[i];


		for(i=1; i<=n; i++)
			{
				int sum=0;

				for(j=i; j<=n; j++)
					{
						sum+=a[j];

						if(sum)
							dp[i][j]=1;
					}
			}
		recur(1, x);

		if(!printed)
			cout << "NO" << endl;

		return 0;
	}