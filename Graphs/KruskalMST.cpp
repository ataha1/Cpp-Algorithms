#include "bits/stdc++.h"
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 10e5 + 5, M = N-1;

vector <pair<int,int>> bad;

struct DSU{
    int p[N], sz[N], ncmp, mxsz;

    void init(int nNodes){
        iota(p, p+nNodes,0);
        ncmp = nNodes;
        mxsz = 1;
        fill(sz, sz+nNodes,1);
    }

    int find(int u){
        return (p[u]==u)? u : p[u] = find(p[u]);
    }

    bool join(int u, int v){
        u = find(u);
        v = find(v);
        if (u==v)   return 0;
        if(sz[u]>sz[v])
            swap(u,v);
        p[u] = v;
        sz[v] += sz[u];
        --ncmp;
        mxsz = max(mxsz,sz[v]);
        return 1;
    }

}dsu;

int from[M], to[M], cst[M], sorted[M];

ll kruskal(int n, int m){
    ll ans=0;

    iota(sorted, sorted+m, 0);
    sort(sorted, sorted+m, [](int i, int j){
         return cst[i]<cst[j];
    });

    dsu.init(n);

    for(int i=0;i<m;i++){
        int u = from[sorted[i]], v = to[sorted[i]], c = cst[sorted[i]];
        if(dsu.join(u,v))
            ans+=c;
    }
    if(dsu.ncmp!=1) ans=-1;
    return ans;
}


int main() {
    int n,m;  cin>>n>>m;
    int u,v,c;
    for(int i=0;i<m;i++){
        cin>>u>>v>>c;
        --u;    --v;
        from[i]=u;  to[i] = v;  cst[i] = c;
    }
    ll ans = kruskal(n,m);
    if(~ans)    cout<<ans;
    else    cout<<"IMPOSSIBLE";


}
