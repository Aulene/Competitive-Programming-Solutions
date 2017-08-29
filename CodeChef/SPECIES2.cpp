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

char a[57][57];
bool vis[57][57];
lli n;

bool fill(char x, int i, int j)
{
	if(vis[i][j])
		return 1;

	bool ans=1;

	if(a[i][j]=='.' || a[i][j]==x || a[i][j]=='0')
		{
			vis[i][j]=1;
			return 1;
		}

	if(a[i][j]=='?')
		{
			a[i][j] = x;
			//cout << i << " " << j << " " << a[i][j] << endl;

			ans=min(fill(x, i+1, j), ans);
			ans=min(fill(x, i-1, j), ans);
			ans=min(fill(x, i, j-1), ans);
			ans=min(fill(x, i, j+1), ans);

			vis[i][j]=1;
			return ans;
		}

	if(a[i][j]!=x)
		{
			//cout << i << " " << j << endl;  
			vis[i][j]=1;
			return 0;
		}

	return 1;
}

int main()
	{
		lli t, i, j, ans;
		char x;

		cin >> t;

		while(t--)
			{
				ans=1;
				bool ex=1;
				bool chgd=0, exer;

				cin >> n;

				for(i=0; i<57; i++)
					for(j=0; j<57; j++)
						{
							a[i][j]='0';
							vis[i][j]=0;
						}
				
				for(i=1; i<=n; i++)
					for(j=1; j<=n; j++)
						{
							cin >> a[i][j];
							if(a[i][j]=='?')
								chgd=1;
						}

				if(!chgd)
					{
						for(i=1; i<=n; i++)
							{
								for(j=1; j<=n; j++)
									{
										if(a[i][j]=='G')
											{
												ex=1;

												if(!(a[i][j-1]=='.' || a[i][j-1]=='0'))
													ex=0;

												if(!(a[i][j+1]=='.' || a[i][j+1]=='0'))
													ex=0;

												if(!(a[i-1][j]=='.' || a[i-1][j]=='0'))
													ex=0;

												if(!(a[i+1][j]=='.' || a[i+1][j]=='0'))
													ex=0;
											}
										else if(a[i][j]=='B' || a[i][j]=='P')
											{
												x=a[i][j];

												//cout << i << " " << j << endl;

												ex=min(ex, fill(x, i+1, j));
												ex=min(ex, fill(x, i-1, j));
												ex=min(ex, fill(x, i, j+1));
												ex=min(ex, fill(x, i, j-1));
											}

										if(!ex)
											{
												ans=0;
												break;
											}
									}

								if(!ex)
									{
										ans=0;
										break;
									}
							}
					}

				for(i=1; i<=n; i++)
					{
						for(j=1; j<=n; j++)
							{
								if(a[i][j]=='B' || a[i][j]=='P')
									{
										x=a[i][j];

										//cout << i << " " << j << endl;

										ex=min(ex, fill(x, i+1, j));
										ex=min(ex, fill(x, i-1, j));
										ex=min(ex, fill(x, i, j+1));
										ex=min(ex, fill(x, i, j-1));
									}
							}

						if(!ex)
							{
								ans=0;
								break;
							}
					}

				for(i=1; i<=n; i++)
					{
						for(j=1; j<=n; j++)
							{
								if(a[i][j] == '?')
									{
										exer=1;

										if(!(a[i][j-1]=='.' || a[i][j-1]=='0'))
											exer=0;

										if(!(a[i][j+1]=='.' || a[i][j+1]=='0'))
											exer=0;

										if(!(a[i-1][j]=='.' || a[i-1][j]=='0'))
											exer=0;

										if(!(a[i+1][j]=='.' || a[i+1][j]=='0'))
											exer=0;

										if(exer)
											ans=(ans*3)%mod;
										else
											{
												ans=(ans*2)%mod;
												ex=min(ex, fill(x, i+1, j));
												ex=min(ex, fill(x, i-1, j));
												ex=min(ex, fill(x, i, j+1));
												ex=min(ex, fill(x, i, j-1));
											}
									}

								if(!ex)
									{
										ans=0;
										break;
									}
							}
					}

				/*
				for(i=1; i<=n; i++)
					{
						for(j=1; j<=n; j++)
							cout << a[i][j];
						cout << endl;
					}
				*/

				cout << ans << endl;
			}

		return 0;
	}