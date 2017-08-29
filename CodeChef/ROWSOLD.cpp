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

lli ones[100007];
lli numberOfNum[100007];
lli dp[100007];

int main()
	{
		int n, t, i, j, pos;
		lli nums, ans, onesAtEnd;
		string s;
		
		cin >> t;

		while(t--)
			{
				memset(dp, 0, sizeof(dp));

				nums=ans=onesAtEnd=0;

				cin >> s;
				n=s.size();

				for(i=n-1; i>=0; i--)
					{
						if(s[i]=='1')
							{
								ans = ans + n - i - 1 - onesAtEnd;
								onesAtEnd++;
							}
					}

				for(i=0; i<n; i++)
					if(s[i]=='1')
						{
							numberOfNum[nums]=i;
							nums++;
						}


				for(i=nums-1; i>=0; i--)
					{
						pos = numberOfNum[i];

						if(pos+1<n)
							{
								if(s[pos+1] == '1')
									{
										dp[i] = dp[i+1];
									}
								else
									{
										dp[i] = dp[i+1]+1;
									}
							}
					}

				for(i=0; i<nums; i++)
					ans+=dp[i];

				cout << ans << endl;
			}

		return 0;
	}