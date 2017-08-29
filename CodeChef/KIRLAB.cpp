#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#include<map>
 
#define lli long long int
#define MAX 10000007
using namespace std;
 
lli a[100007];
lli dp[100007];
bool v[MAX];
lli sp[MAX];
int ind[MAX];

int sieve()
{
    lli i, j;
    
    sp[1]=1;

    for(i=2; i<MAX; i+=2)
        sp[i]=2;

    for(i=3; i<MAX; i+=2)
        if(!v[i])
            {
                sp[i]=i;

                for(j=i; (j*i)<MAX; j+=2)
                    {
                        if(!v[j*i])
                            v[j*i]=1;
                        sp[j*i]=i;
                    }
            }

    return 0;
}
 
int main()
{
    sieve();
 
    lli t, n, i, j, ans;
    lli num, div, cur;

    cin >> t;
 
    while(t--)
        {
            memset(dp, 0, sizeof(dp));
            ans=0;
            
            scanf("%lld", &n);

            for(i=0; i<n; i++)
                scanf("%lld", &a[i]);

            for(i=0; i<n; i++)
                {
                    num=a[i];
                    //cout << num << endl;

                    while(num!=1)
                        {
                            //cout << div << " ";
                            div=sp[num];
                            ind[div]=i;
                            num=num/div;
                        }

                    //cout << endl;
                }

            for(i=0; i<n; i++)
                {
                    cur=0;
                    num=a[i];

                    //cout << num << endl;

                    while(num!=1)
                        {
                            div=sp[num];
                            
                            //cout << div << " " << ind[div] << " " << dp[ind[div]] << endl;
                            cur=max(cur, dp[ind[div]]);

                            ind[div]=i;
                            num=num/div;
                        }

                    //cout << endl << endl;
                    dp[i]=dp[i]+cur+1;
                }

            /*
            for(i=0; i<n; i++)
                cout << dp[i] << " ";
            cout << endl;
            */
                
            for(i=0; i<n; i++)
                ans=max(ans, dp[i]);

            printf("%lld\n", ans);
        }
    
    return 0;
}
