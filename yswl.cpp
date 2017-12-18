#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se secondB
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=101010;

int n,m,q;
int pre[N];
pair<int,pii> e[N];

int find(int x) {
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
void join(int x,int y) {
	int fx=pre[x];
	int fy=pre[y];
	pre[fx]=fy;
}

void solve(int st,int ed) {
	rep(i,0,n+1) pre[i]=i;
	rep(i,0,m) {
		int x=find(e[i].se.fi);
		int y=find(e[i].se.se);
		if(x!=y) {
			join(x,y);
			if(find(st)==find(ed)) {
				printf("%d\n",-e[i].fi);
				return ;
			}	
		}
	}
}

int main() {
	///
	scanf("%d%d%d",&n,&m,&q);
	///read
	rep(i,0,m) {
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		e[i]=mp(-w,mp(u,v));
	}
	sort(e,e+m);
	///solve
	rep(i,0,q) {
		int u,v;scanf("%d%d",&u,&v);
		solve(u,v);
	}
	return 0;
} 
