#include "bits/stdc++.h"
#define FIO ios_base::sync_with_stdio(false);   cin.tie(0);     cout.tie(0);
#define pb push_back
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
//const ll inf = 0x3f3f3f3f3f3f3f3fll;
const int N = 2e5 + 5, mod = 998244353;
vector <pair<int, int>> adj[N];
int n,m;
int st, nd;
ll dis[N];
bool flag;

void dijkstra(int src){
    priority_queue <pair<ll, int>> pq;
    pq.push({0, src});
    memset(dis, '?', (n+1)*sizeof dis[0]);
    dis[src] = 0;

    while(pq.size()){
        int u = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();

        if(u == nd) flag = 1;
        if(d != dis[u])     continue;

        for(auto e: adj[u]){
            int v = e.second;
            int c = e.first;
            ll nd = dis[u] + c;
            if(nd < dis[v]){
                dis[v] = nd;
                pq.push({-nd, v});
            }
        }
    }
}

void solve(){
    scanf("%d%d%d%d", &n, &m, &st, &nd);
    for(int i=0;i<m;i++){
        int u,v,c;
        scanf("%d%d%d", &u,&v,&c);
        adj[u].pb({c,v});
        adj[v].pb({c,u});
    }
    flag = 0;
    dijkstra(st);
    if(flag)    printf("%lld\n", dis[nd]);
    else    puts("NONE");
    for(int i=1;i<=n;i++)   adj[i].clear();
}

int main(){
//    FIO
    int t = 1;
    scanf("%d", &t);
    while(t--){
        solve();
    }

}
