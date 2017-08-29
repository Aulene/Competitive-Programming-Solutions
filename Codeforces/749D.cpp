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

bool compare(pair<int,int>a, pair<int,int>b)
{
	return a.first>b.first || (a.first==b.first && a.second>b.second);
}

queue <int> ax;
bool out[200005];
vector<int> g[200005];
pair<int,int> v[200005], a[200005];

int main()
{
	int n, i, q, k, pos, j;
	int prev, identify, wholes, aux, l, lastone;
	bool ver;

	cin>>n;

	for(i=0; i<n; i++)
		{
	        cin >> v[i].first >> v[i].second;
			g[v[i].first].pb(i);
			a[i].first=v[i].second;
			a[i].second=i;
		}

	sort(a,a+n,compare);

	cin >> q;
	
	for(i=0; i<q; i++)
		{
	        cin>>k;

			for(j=0;j<k;j++)
				{
					cin>>aux;
					out[aux]=true;
					ax.push(aux);
				}

			pair <int, int> ans={0,0};
			for(pos=0; pos<n; pos++)
				{
					prev=a[pos].second;
					identify=v[prev].first;

					if(out[identify])
						continue;

		            wholes=find(g[identify].begin(), g[identify].end(), prev)-g[identify].begin();

					if(wholes==0)
						{
							ans=make_pair(identify, v[prev].second);
							break;
						}
					else
						{
							lastone=wholes-1;
							ver=0;

							for(l=g[identify][lastone]+1; l<g[identify][wholes]; l++)
								{
									if(!out[v[l].first]){
										ver=true;
										break;
								}
					}
					if(ver)
						{
							ans=make_pair(identify, v[prev].second);
							break;
						}
				}
			}

        cout << ans.first <<"  " << ans.second <<endl;

		while(!ax.empty())
			{
				out[ax.front()]=0;
				ax.pop();
			}
	}
}
