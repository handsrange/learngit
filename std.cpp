//测试输出
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100001;
int f[maxn];
int n, m, q;
int u, v, w;
int ans[100];
pair< int, pair< int, int > > ed[maxn];
char in[10] = "data/0.in";
char out[11] = "data/0.out";
int root(int x)
{
	int y,t;
	y=x;
	while(x != f[x])x=f[x];
	while(y != x)
	{
		t=f[y];
		f[y]=x;
		y=t;
	}
	return x;
}

int solve(int x,int y)
{
	for(int j = 1; j <= n; j++)
	{
		f[j] = j;
	}
	for(int j = 0; j < m; j++)
	{
		u = root(ed[j].second.first);
		v = root(ed[j].second.second);
		if(u != v)
		{
			f[u] = v;
			if(root(x) == root(y))
			{
				return -ed[j].first;
			}
		}
	}
	return 0;
}

int main()
{
	for(int i = 0; i < 1; i++)
	{
		in[5] = i + '0';
		out[5] = i + '0';
		freopen(in,"r",stdin);
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			ed[i] = make_pair(-w, make_pair(u, v));
		}
		sort(ed, ed + m);
		for(int i = 0; i < q; i++)
		{
			scanf("%d%d", &u, &v);
			ans[i] = solve(u, v);
		}
		freopen(out,"r",stdin);
		for(int i = 0; i < q; i++)
		{
			if(scanf("%d", &w) == EOF || w != ans[i])
			{
				printf("输出错误\n");
				return 0;
			}
		}
	}
	printf("ok\n");
	return 0;
}