#include "bits/stdc++.h"
#define FIO ios_base::sync_with_stdio(false);   cin.tie(0);     cout.tie(0);
#define pb push_back
#define PI acos(-1.0)
//#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
const int OO = 0x3f3f3f3f;
const int N = 1<<18, M = 5e2 + 5, mod = 1e8;
struct item{
    ll maxSeg = 0, maxPref = 0, maxSuf = 0, sum = 0;
};
int a[N], n;
item tree[N];

void build(int ni=0, int ns=0, int ne=n-1){
    if(ns == ne){
        tree[ni] ={max(0,a[ns]), max(0,a[ns]), max(0,a[ns]), a[ns]};
        return;
    }
    int mid = ns + (ne - ns)/2, lf = 2*ni + 1, rt = lf+1;
    build(lf, ns, mid);
    build(rt, mid+1, ne);

    tree[ni].sum = tree[lf].sum + tree[rt].sum;
    tree[ni].maxSeg = max({tree[lf].maxSeg, tree[rt].maxSeg, tree[lf].maxSuf + tree[rt].maxPref});
    tree[ni].maxPref = max(tree[lf].maxPref, tree[lf].sum + tree[rt].maxPref);
    tree[ni].maxSuf = max(tree[rt].maxSuf, tree[rt].sum + tree[lf].maxSuf);
}

void update(int pos, int val, int ni = 0, int ns = 0, int ne = n-1){
    if(pos>ne || pos<ns)    return;
    if(ns == ne){
        tree[ni] ={max(0,val), max(0, val), max(0,val), val};
        return;
    }
    int mid = ns + (ne - ns)/2, lf = 2*ni + 1, rt = lf+1;
    update(pos, val, lf, ns, mid);
    update(pos, val, rt, mid+1, ne);

    tree[ni].sum = tree[lf].sum + tree[rt].sum;
    tree[ni].maxSeg = max({tree[lf].maxSeg, tree[rt].maxSeg, tree[lf].maxSuf + tree[rt].maxPref});
    tree[ni].maxPref = max(tree[lf].maxPref, tree[lf].sum + tree[rt].maxPref);
    tree[ni].maxSuf = max(tree[rt].maxSuf, tree[rt].sum + tree[lf].maxSuf);
}


int main(){
    FIO
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>a[i];
    build();
    cout<<tree[0].maxSeg<<"\n";
    for(int i=0;i<m;i++){
        int idx,val;    cin>>idx>>val;
        update(idx,val);
        cout<<tree[0].maxSeg<<"\n";
    }

}
