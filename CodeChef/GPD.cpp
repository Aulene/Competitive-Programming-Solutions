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

map < lli, vector < lli > > g;
map < lli, lli > encryptionIDs;
map < lli, bool > vis;
lli min_answer, max_answer, R;

lli dfs(lli V, lli K)
{
    if(vis[V])
        return 0;

    lli x = K^encryptionIDs[V];
    bool rval = 0;

    if(V == R)
        {   
            /*
            cout << V << " " << K << " " << encryptionIDs[V] << endl;
            cout << min_answer << " " << x << endl;
            cout << max_answer << " " << x << endl << endl;
            */

            min_answer = min(min_answer, x);
            max_answer = max(max_answer, x);

            return 1;
        }

    vis[V] = 1;

    vector <lli> :: iterator it;

    for(it = g[V].begin(); it!=g[V].end(); it++)
        {
            if(dfs(*it, K))
                {   
                    /*
                    cout << V << " " << K << " " << encryptionIDs[V] << endl;
                    cout << min_answer << " " << x << endl;
                    cout << max_answer << " " << x << endl << endl;
                    */

                    min_answer = min(min_answer, x);
                    max_answer = max(max_answer, x);
                    rval = 1;
                }
        }

    return rval;
}

int main()
    {
        lli N, Q, key;
        lli t, u, v, k;
        lli i;
        lli last_answer = 0;

        cin >> N >> Q;
        cin >> R >> key;

        encryptionIDs[R] = key;

        for (i=0; i<N-1; i++)
            {
                scanf("%lld %lld %lld", &u, &v, &k);

                g[v].pb(u);
                g[u].pb(v);

                encryptionIDs[u] = k;
            }

        for (i=0; i<Q; i++)
            {
                scanf("%lld", &t);
                
                // find real value of t
                t ^= last_answer;

                if (t == 0)
                    {
                        scanf("%lld %lld %lld", &v, &u, &k);
                        
                        // find real values for u, v, and k
                        u ^= last_answer;
                        v ^= last_answer;
                        k ^= last_answer;

                        g[u].pb(v);
                        g[v].pb(u);

                        encryptionIDs[u] = k;
                    }
                else
                    {
                        scanf("%lld %lld", &v, &k);

                        // find real values for v, and k
                        v ^= last_answer;
                        k ^= last_answer;

                        // compute the requested values
                        max_answer = encryptionIDs[v]^k;
                        min_answer = encryptionIDs[v]^k;

                        dfs(v, k);

                        printf("%lld %lld\n", min_answer, max_answer);
                        // update last_answer
                        last_answer = min_answer ^ max_answer;  
                    }
            }

        return 0;
    }