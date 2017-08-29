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

int ans[37];
int a[37], b[37];

int main()
	{
		ifstream fin ("blocks.in");
		ofstream fout ("blocks.out");

		int n, i, l1, l2;
		string s1, s2;

		fin >> n;

		while(n--)
			{
				for(i=0; i<=26; i++)
					{
						a[i]=0;
						b[i]=0;
					}

				fin >> s1 >> s2;
				l1=s1.size();
				l2=s2.size();

				for(i=0; i<l1; i++)
					a[s1[i]-'a'+1]++;
				for(i=0; i<l2; i++)
					b[s2[i]-'a'+1]++;

				/*
				for(i=0; i<26; i++)
					cout << a[i] << " ";
				cout << endl;
				for(i=0; i<26; i++)
					cout << b[i] << " ";
				cout << endl;
				*/

				for(i=1; i<=26; i++)
					ans[i]+=max(a[i], b[i]);

			}

		for(i=1; i<=26; i++)
			fout << ans[i] << endl;
		return 0;
	}