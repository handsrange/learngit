//验证输入
#include <cstdio>
const int maxn = 100000;
const int maxv = 707063423;
const int maxq = 100;
char in[10] = "data/0.in";
int n, m, q;
int u, v, w;
int main()
{
	for(int i = 0; i < 10; i++)
	{
		in[5] = i + '0';
		freopen(in,"r",stdin);
		if(scanf("%d%d%d",&n,&m,&q) == EOF)
		{
			printf("数据不完整\n");
			return 0;
		}
		if(n > maxn || m > maxn || q > maxq || n < 1 || m < 1 || q < 0)
		{
			printf("第 %d 组数据不符合描述范围\n", i);
			return 0;
		}
		for(int j = 0; j < m; j++)
		{
			if(scanf("%d%d%d",&u,&v,&w) == EOF)
			{
				printf("数据不完整\n");
				return 0;
			}
			if(u > n || v > n || w > maxv || u < 1 || v < 1 || w < 0)
			{
				printf("第 %d 组数据不符合描述范围\n", i);
				return 0;
			}
		}
		for(int j = 0; j < q; j++)
		{
			if(scanf("%d%d",&u,&v) == EOF)
			{
				printf("数据不完整\n");
				return 0;
			}
			if(u > n || v > n || u < 1 || v < 1)
			{
				printf("第 %d 组数据不符合描述范围\n", i);
				return 0;
			}
		}
	}
	printf("ok\n");
	return 0;
}