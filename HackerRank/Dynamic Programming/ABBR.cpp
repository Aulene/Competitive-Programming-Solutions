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

bool dp[1007][1007];

int main()
	{
		int t, i, j, l1, l2;
		string s1, s2;

		cin >> t;

		while(t--)
			{
				cin >> s1 >> s2;

				l1=s1.size();
				l2=s2.size();

				for(i=0; i<1007; i++)
					for(j=0; j<1007; j++)
						dp[i][j]=0;

				dp[0][0]=1;

				for(i=0; i<l1; i++)
					{
						for(j=0; j<=l2; j++)
							{
								if(dp[i][j])
									{
										if(j<l2 && (s1[i]-32 == s2[j] || s1[i] == s2[j]) )
											dp[i+1][j+1]=1;

										if(s1[i]>='a' && s1[i]<='z')
											dp[i+1][j]=1;
									}
							}
					}

				/*
				for(i=0; i<l1; i++)
					{
						for(j=0; j<l2; j++)
							cout << dp[i][j] << " ";
						cout << endl; 
					}
				*/
					
				if(dp[l1][l2])
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}



		return 0;
	}