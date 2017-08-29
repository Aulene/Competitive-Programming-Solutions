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
#define pb push_back

lli a[200007];
stack<int> s;

int main()
	{
		int n, i;

		cin >> n;

		for(i=0; i<n; i++)
			cin >> a[i];


		for(i=0; i<n; i++)
			{
				while(!s.empty() && a[s.top()]>=a[i])
					s.pop();

				if(s.empty())
					
			}

		return 0;
	}