#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

signed main() {
	int n,k, i, idx, sum;
	bool ans;

	cin >> n >> k;
	string s;
	cin >> s;
	int m = s.size();

	vector < pair <int, int> > v(26, mp(-1, -1));

	for(i=0;i<m;i++)
		{
			idx = s[i] - 'A';

			if(v[idx].f == -1)
				{
					v[idx].f = i;
					v[idx].s = i;
				}
			else
				v[idx].s=i;
		}
	
	sum=0;
	ans=true;
	for(int i=0;i<m;i++){
		int idx=s[i]-'A';
		if(v[idx].f==i){
			++sum;
			if(sum>k){
				ans=false;
				break;
			}
		}
		
		if(v[idx].s==i){
			--sum;
		}
	}
	
	if(ans)
	cout<<"YES\n";
	else
	cout<<"NO\n";
}