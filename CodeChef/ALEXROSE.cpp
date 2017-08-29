#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<climits>
#include<map>
#include<fstream>

#define lli long long int
 
using namespace std;
 
lli a[100007];
lli n, k;
map<lli, lli> o;
 
bool compare(lli a, lli b)
{
	if(o[a]!=o[b])
		return o[a]>o[b];
	return a<b;
}
 
int main()
{
	//ifstream cin ("inp.txt");
	//ofstream fout ("ans.txt");

	lli t, i, k, j;
	lli prev, ans, r;
	lli made;
 		
 	cin >> t;
	//cin >> t;
 
	while(t--)
		{
			//cin >> n >> k;
 			cin >> n >> k;

			for(i=0; i<n; i++)
				{
					cin >> a[i];
					o[a[i]]++;
				}
 
			sort(a, a+n, compare);
 
			ans=0;
 
			/*
			for(i=0; i<n; i++)
				cout << a[i] << " " << o[a[i]] << endl;
			*/
 
			for(i=0; i<n; i++)
				o[a[i]]=o[a[i]]%k;
 
			for(i=0; i<n; i++)
				{
					if(o[a[i]]>0)
						{
							r=k-o[a[i]];

							for(j=n-1; j>=0; j--)
								if(o[a[j]] && a[j]>a[i] && r)
									{
										if(o[a[j]]<=r)
											r-=o[a[j]];
										else
											r=0;									
									}

							if(r==0)
								{
									//cout << a[i] << " ";
									r=k-o[a[i]];
									o[a[i]]=0;

									for(j=n-1; j>=0; j--)
										if(o[a[j]] && a[j]>a[i] && r)
											{
												//cout << a[j] << " ";
												if(o[a[j]]<=r)
													{
														r-=o[a[j]];
														ans+=o[a[j]];
														o[a[j]]=0;
													}
												else
													{
														o[a[j]]-=r;
														ans+=r;
														r=0;
													}
											}

									//cout << endl;
								}
						}
				}
 
			//for(i=0; i<n; i++)
			//	fout << a[i] << " " << o[a[i]] << endl;
 
			cout << ans << endl;
			o.clear();
		}	
	return 0;
}
 