#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<climits>
#include<vector>

#define lli long long int
#define pb push_back

using namespace std;

bool lcs[6107][6107];

int solve(string s)
{
	int n=s.size(), i, k, j;
	int ans=0, maxLength=1;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			lcs[i][j]=0;

	for(i=0; i<n; i++)
		lcs[i][i]=1;

	for(i=0; i<n; i++)
		if(s[i]==s[i+1])
			{
				lcs[i][i+1]=1;
				maxLength=2;
			}

	for(k=3; k<=n; k++)
		{
			for(i=0; i<n-k+1; i++)
				{
					j=i+k-1;

					if(lcs[i+1][j-1] && s[i]==s[j])
						{
							lcs[i][j]=1;
							maxLength=max(maxLength, k);
						}
				}
		}

	return maxLength;
}

int main()
{
	int t, n, i, j;
	int lps=0, ans;
	string s;

	cin >> t;

	while(t--)
		{
			cin >> s;

			n=s.size();
			ans=solve(s);
			ans=n-ans;

			cout << ans << endl;
		}

	return 0;
}