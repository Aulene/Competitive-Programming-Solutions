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

map < int, int > encryptionIDs;
map < int, int > g;
int min_answer, max_answer, R;

int main()
    {
        int N, Q, key;
        int t, u, v, k;
        int i;
        int last_answer = 0;
        int node;

        cin >> N >> Q;
        cin >> R >> key;

        encryptionIDs[R] = key;

        for (i=0; i<N-1; i++)
            {
                scanf("%d %d %d", &u, &v, &k);
                encryptionIDs[u] = k;
                g[u] = v;
            }

        for (i=0; i<Q; i++)
            {
                scanf("%d", &t);
                
                // find real value of t
                t ^= last_answer;

                if (t == 0)
                    {
                        scanf("%d %d %d", &v, &u, &k);
                        
                        // find real values for u, v, and k
                        u ^= last_answer;
                        v ^= last_answer;
                        k ^= last_answer;

                        g[u] = v;
                        encryptionIDs[u] = k;
                    }
                else
                    {
                        scanf("%d %d", &v, &k);

                        // find real values for v, and k
                        v ^= last_answer;
                        k ^= last_answer;

                        // compute the requested values
                        max_answer = 0;
                        min_answer = INT_MAX;

                        node = v;

                        min_answer = min(min_answer, encryptionIDs[node]^k);
                        max_answer = max(max_answer, encryptionIDs[node]^k);

                        while(node != R)
                            {
                                node = g[node];

                                min_answer = min(min_answer, encryptionIDs[node]^k);
                                max_answer = max(max_answer, encryptionIDs[node]^k);
                            }
                            
                        printf("%d %d\n", min_answer, max_answer);
                        // update last_answer
                        last_answer = min_answer ^ max_answer;  
                    }
            }

        return 0;
    }