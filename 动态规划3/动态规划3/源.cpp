#define  _CRT_SECURE_NO_WARNINGS 1
//计数类DP--计数问题
#include<iostream>
#include<cmath>
using namespace std;
int dgt(int n)// 计算整数n有多少位
{
	int res = 0;
	while (n) ++res, n /= 10;
	return res;
}
int cnt(int n, int i)
{
	int res = 0, d = dgt(n);
	for (int j = 1;j <= d;j++)// 从右到左第j位上数字i出现多少次，所有位上的次数加起来就是i出现的总次数
	{
		int p = pow(10, j - 1), l = n / p / 10, r = n % p, dj = n / p % 10;
		// l和r是第j位左边和右边的整数 (视频中的abc和efg); dj是第j位的数字
		if (i) res += l * p;// 计算第j位左边的整数小于l (视频中xxx = 000 ~ abc - 1)的情况
		if (!i && l) res += (l - 1) * p;
		// 如果i = 0, 左边高位不能全为0(视频中xxx = 001 ~ abc - 1)，并且&&l表示这时i也不能在最高位出现
		if ((dj > i) && (i || l)) res += p;
		//(i || l)表示i=0时，i不能出现在最高位（即l不能为0），因为这种数是不存在的
		if ((dj == i) && (i || l)) res += r + 1;
		//(i || l)表示i=0时，i不能出现在最高位（即l不能为0），因为这种数是不存在的
	}
	return res;
}
int main()
{
	int a, b;
	while (cin >> a >> b, a)
	{
		if (a > b) swap(a, b);
		for (int i = 0;i <= 9;i++) cout << cnt(b, i) - cnt(a - 1, i) << " ";
		cout << endl;
	}
	return 0;
}





//状态压缩DP--蒙德里安的梦想
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 12, M = 1 << N;
long long f[N][M];// 第一维表示列， 第二维表示所有可能的状态
bool st[M];//存储每种状态是否有奇数个连续的0，如果奇数个0是无效状态，如果是偶数个零置为true
int n, m;
int main()
{
	while (cin >> n >> m, n || m)
	{
		for (int i = 0;i < 1 << n;i++)
		{
			st[i] = true;//记录一列中0的个数
			int cnt = 0;
			for (int j = 0;j < n;j++)// 通过位操作，i状态下j行是否放置方格，0就是不放， 1就是放
			{
				if (i >> j & 1)
				{
					if (cnt & 1)// 如果放置小方块使得连续的空白格子数成为奇数
					{
						st[i] = false;
						break;
					}
				}
				else cnt++;//不放置小方格
			}
			if (cnt & 1) st[i] = false;
		}
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 1;i <= m;i++)//枚举i列每一种状态
			for (int j = 0;j < 1 << n;j++)//枚举i-1列每一种状态
				for (int k = 0;k < 1 << n;k++)// f[i-1][k] 成功转到 f[i][j]
					if ((j & k) == 0 && st[j | k])
						f[i][j] += f[i - 1][k]; //那么这种状态下它的方案数等于之前每种k状态数目的和
		cout << f[m][0] << endl;
	}
}




//最短Hamilton路径
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 20, M = 1 << N;
int n;
int w[N][N];
int f[M][N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> w[i][j];
	memset(f, 0x3f, sizeof f);
	f[1][0] = 0;//因为零是起点,所以f[1][0]=0
	for (int i = 0;i < 1 << n;i++)//i表示所有的情况
		for (int j = 0;j < n;j++)//j表示走到哪一个点
			if (i >> j & 1)
				for (int k = 0;k < n;k++)//k表示走到j这个点之前,以k为终点的最短距离
					if ((i - (1 << j)) >> k & 1)
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);//更新最短距离
	cout << f[(1 << n) - 1][n - 1] << endl;//表示所有点都走过了,且终点是n-1的最短距离
}







//树状DP--没有上司的舞会
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 6010;
int n;
int h[N], e[N], ne[N], idx;
int happy[N];
int f[N][2];
bool has_fa[N];
void add(int a,int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
	f[u][1] = happy[u];
	for (int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		dfs(j);
		f[u][1] += f[j][0];
		f[u][0] += max(f[j][0], f[j][1]);
	}
}
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> happy[i];
	memset(h, -1, sizeof h);
	for (int i = 0;i < n - 1;i++)
	{
		int a, b;
		cin >> a >> b;
		add(b, a);
		has_fa[a] = true;
	}
	int root = 1;
	while (has_fa[root]) root++;
	dfs(root);
	cout << max(f[root][0], f[root][1]) << endl;
}





//记忆化搜索--滑雪
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 310;
int n, m;
int g[N][N];
int f[N][N];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int dp(int x, int y)
{
	int& v = f[x][y];
	if (v != -1) return v;
	v = 1;
	for (int i = 0;i < 4;i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a >= 1 && a <= n && b >= 1 && b <= m && g[x][y] > g[a][b])
			v = max(v, dp(a,b) + 1);
	}
	return v;
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> g[i][j];
	memset(f, -1, sizeof f);
	int res = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			res = max(res, dp(i, j));
	cout << res << endl;
}