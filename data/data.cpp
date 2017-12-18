#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char s[10]="0.in";
const int N=101010;
const int base=10000;

map<pii,int> g;
pair<pii,int> e[N];
int pre[N];

int find(int x) {
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
void join(int x,int y) {
	int fx=find(x);
	int fy=find(y);
	pre[fx]=fy;
}

int Rand(int n) {
	if(n==0) return 0;
	return 1ll*rand()*rand()%n+1;
}

int main() {
    rep(cas,0,10) {
    	/// 
        s[0]='0'+cas;
        freopen(s,"w",stdout);
        ///init
        g.clear();
		rep(i,0,N) pre[i]=i;
        ///get n,m,q
        int n=8*base+Rand(2*base), q=80+Rand(20);
		int m=n-1+Rand(10*base-(n-1));
		printf("%d %d %d\n",n,m,q);
		///get edge
		int cnt=0, mm=m;
		for(;m;) {
			int u=Rand(n), v=Rand(n);
			int w=Rand(707063423);
			if(g[mp(u,v)]||u==v) continue;
			if(find(u)==find(v)) {
				if(cnt+m-1>=n-1) {
					g[mp(u,v)]=g[mp(v,u)]=w;
					e[m--]=mp(mp(u,v),w);
					printf("%d %d %d\n",u,v,w);
				}
			} else {
				join(u, v); ++cnt;
				g[mp(u,v)]=g[mp(v,u)]=w;
				e[m--]=mp(mp(u,v),w);
				printf("%d %d %d\n",u,v,w);
			}
		}
		///get qry
		for(;q;) {
			int u=Rand(n);
			int v=Rand(n);
			if(u!=v) {
				--q;
				printf("%d %d\n",u,v);
			}
		}
    }
    return 0;
}
