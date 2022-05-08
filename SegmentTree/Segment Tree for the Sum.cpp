#include "bits/stdc++.h"
#define FIO ios_base::sync_with_stdio(false);   //cin.tie(0);     cout.tie(0);
#define pb push_back
#define PI acos(-1.0)
//#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
const int OO = 0x3f3f3f3f;
const int N = 1<<18, M = 5e2 + 5, mod = 1e8;
long long a[N], tree[N], n, m;

void build(int ni = 0, int ns = 0, int ne = n-1){
    if(ns == ne)    return tree[ni] = a[ns], void();
    int mid = ns + (ne - ns)/2, lf = 2*ni + 1, rt = lf + 1;
    build(lf, ns, mid);
    build(rt, mid+1, ne);
    tree[ni] = tree[lf] + tree[rt];
}

long long query(int qs, int qe, int ni = 0, int ns = 0, int ne = n-1){
    if(qs>ne || qe<ns)  return 0;
    if(ns >= qs && ne <= qe)    return tree[ni];
    int mid = ns + (ne - ns)/2, lf = 2*ni + 1, rt = lf + 1;
    return query(qs, qe, lf, ns, mid) + query(qs, qe, rt, mid+1, ne);
}

void update(int pos, int val, int ni = 0, int ns = 0, int ne = n-1){
    if(pos < ns || pos > ne)    return;
    if(ns == ne)    return tree[ni] = a[ns] = val, void();
    int mid = ns + (ne - ns)/2, lf = 2*ni + 1, rt = lf + 1;
    update(pos, val, lf, ns, mid);
    update(pos, val, rt, mid+1, ne);
    tree[ni] = tree[rt] + tree[lf];
}



int main(){
    FIO
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>a[i];
    build();
    while(m--){
        int op; cin>>op;
        if(op == 1){
            int i, v;   cin>>i>>v;
            update(i,v);
        }
        else{
            int l,r;    cin>>l>>r;
            cout<<query(l,r-1)<<"\n";
        }
    }
}
