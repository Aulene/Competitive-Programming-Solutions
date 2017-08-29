#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<fstream>
 
using namespace std;
 
#define lli long long int
#define mod 1000000007
#define pb push_back 
 
lli a[10007];
lli ans[4510007];
 
int main()
        {
                ifstream fin ("inp.txt");
                ofstream fout ("correctans.txt");

                lli n, i, j, k, num;
                lli u, t, q, m;
                lli gridNo;
 
                fin >> t;
 
                while(t--)
                        {
                                gridNo=0;
 
                                fin >> n >> q;
 
                                for(i=0; i<n; i++)
                                        fin >> a[i];
                                
                                for(i=0; i<n; i++)
                                        {
                                                num=a[i];
 
                                                for(j=i; j<n; j++)
                                                        {
                                                                num=max(num, a[j]);
                                                                ans[gridNo]=num;
                                                                gridNo++;
                                                        }
                                        }
                                
                                sort(ans, ans+gridNo, greater<lli>());
                                
                                while(q--)
                                        {
                                                fin >> m;
                                                fout << ans[m-1] << endl;        
                                        }
                        }
                return 0;
        } 