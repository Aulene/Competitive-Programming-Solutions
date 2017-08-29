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

struct Node{
    lli children[2];

    Node()
        {
            children[0] = 0;
            children[1] = 0;
        }

    Node(lli x, lli y)
        {
            children[0] = x;
            children[1] = y;
        }
};

vector <lli> queries;
lli t1m3 = 0;
Node tr33[1<<22];
vector <lli> g[100002];
lli n, Q, key[100002];
lli front[300002];

lli buildNodes(lli node, lli treeNum)
{
    lli next_node = ++t1m3;

    if(treeNum == 31) 
        return next_node;

    lli digit = queries[treeNum];
    tr33[next_node] = tr33[node];
    tr33[next_node].children[digit] = buildNodes(tr33[next_node].children[digit], treeNum + 1);

    return next_node;
}

lli propogate(lli q)
{
    queries.clear();

    while(q)
        {
            queries.pb(q & 1);
            q >>= 1;
        }

    while(queries.size() < 31) 
        queries.pb(0); 

    reverse(queries.begin(), queries.end());
    return 0;
}

lli dfs(lli x, lli val)
{
    propogate(key[x]);
    front[x] = buildNodes(front[val], 0);

    lli j;

    for(j = 0; j < g[x].size(); j++)
        {
            lli children = g[x][j];

            if(children == val) 
                continue;

            dfs(children, x);
        }

    return 0;
}

lli minAns(lli node, lli treeNum)
{
    if(treeNum == 31) 
        return 0;

    lli digit = (1 << (30 - treeNum));

    if(tr33[node].children[queries[treeNum]])
        return minAns(tr33[node].children[queries[treeNum]], treeNum + 1);
    else 
        return digit + minAns(tr33[node].children[queries[treeNum] ^ 1], treeNum + 1);
}

lli maxAns(lli node, lli treeNum)
{
    if(treeNum == 31) 
        return 0;

    lli digit = (1 << (30 - treeNum));

    if(tr33[node].children[queries[treeNum] ^ 1])
        return digit + maxAns(tr33[node].children[queries[treeNum] ^ 1], treeNum + 1);
   else 
        return maxAns(tr33[node].children[queries[treeNum]], treeNum + 1);
}

int main()
{
    lli R;
    lli last_answer = 0, min_answer, max_answer, t;
    lli a, b;
    lli node, K;

    scanf("%lld %lld %lld", &n, &Q, &R); 
    scanf("%lld", &key[R]);
    
    for(lli j = 1; j < n; j++)
        {
            
            scanf("%lld %lld", &b, &a); 
            scanf("%lld", &key[b]);
            g[a].pb(b);
            g[b].pb(a);
        }


    front[0] = ++t1m3;
    tr33[t1m3] = Node();
    dfs(R, 0);

    while(Q--)
        {
            scanf("%lld", &t);

            t ^= last_answer;

            if(!t)
                {
                    lli a , b , keyU;
                    scanf("%lld %lld %lld",&a, &b, &keyU);

                    a^=last_answer;
                    b ^= last_answer;
                    keyU ^= last_answer;

                    propogate(keyU);
                    front[b] = buildNodes(front[a], 0);
                }
            else
                {
                    scanf("%lld %lld", &node, &K);

                    node ^= last_answer; 
                    K ^= last_answer;

                    propogate(K);
                    min_answer = minAns(front[node], 0);
                    max_answer = maxAns(front[node], 0);

                    printf("%lld %lld\n", min_answer, max_answer);
                    last_answer = min_answer ^ max_answer;
                }
        }

    return 0;
}
