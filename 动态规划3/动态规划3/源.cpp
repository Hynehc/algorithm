#define  _CRT_SECURE_NO_WARNINGS 1
//������DP--��������
#include<iostream>
#include<cmath>
using namespace std;
int dgt(int n)// ��������n�ж���λ
{
	int res = 0;
	while (n) ++res, n /= 10;
	return res;
}
int cnt(int n, int i)
{
	int res = 0, d = dgt(n);
	for (int j = 1;j <= d;j++)// ���ҵ����jλ������i���ֶ��ٴΣ�����λ�ϵĴ�������������i���ֵ��ܴ���
	{
		int p = pow(10, j - 1), l = n / p / 10, r = n % p, dj = n / p % 10;
		// l��r�ǵ�jλ��ߺ��ұߵ����� (��Ƶ�е�abc��efg); dj�ǵ�jλ������
		if (i) res += l * p;// �����jλ��ߵ�����С��l (��Ƶ��xxx = 000 ~ abc - 1)�����
		if (!i && l) res += (l - 1) * p;
		// ���i = 0, ��߸�λ����ȫΪ0(��Ƶ��xxx = 001 ~ abc - 1)������&&l��ʾ��ʱiҲ���������λ����
		if ((dj > i) && (i || l)) res += p;
		//(i || l)��ʾi=0ʱ��i���ܳ��������λ����l����Ϊ0������Ϊ�������ǲ����ڵ�
		if ((dj == i) && (i || l)) res += r + 1;
		//(i || l)��ʾi=0ʱ��i���ܳ��������λ����l����Ϊ0������Ϊ�������ǲ����ڵ�
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





//״̬ѹ��DP--�ɵ��ﰲ������
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 12, M = 1 << N;
long long f[N][M];// ��һά��ʾ�У� �ڶ�ά��ʾ���п��ܵ�״̬
bool st[M];//�洢ÿ��״̬�Ƿ���������������0�����������0����Ч״̬�������ż��������Ϊtrue
int n, m;
int main()
{
	while (cin >> n >> m, n || m)
	{
		for (int i = 0;i < 1 << n;i++)
		{
			st[i] = true;//��¼һ����0�ĸ���
			int cnt = 0;
			for (int j = 0;j < n;j++)// ͨ��λ������i״̬��j���Ƿ���÷���0���ǲ��ţ� 1���Ƿ�
			{
				if (i >> j & 1)
				{
					if (cnt & 1)// �������С����ʹ�������Ŀհ׸�������Ϊ����
					{
						st[i] = false;
						break;
					}
				}
				else cnt++;//������С����
			}
			if (cnt & 1) st[i] = false;
		}
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 1;i <= m;i++)//ö��i��ÿһ��״̬
			for (int j = 0;j < 1 << n;j++)//ö��i-1��ÿһ��״̬
				for (int k = 0;k < 1 << n;k++)// f[i-1][k] �ɹ�ת�� f[i][j]
					if ((j & k) == 0 && st[j | k])
						f[i][j] += f[i - 1][k]; //��ô����״̬�����ķ���������֮ǰÿ��k״̬��Ŀ�ĺ�
		cout << f[m][0] << endl;
	}
}




//���Hamilton·��
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
	f[1][0] = 0;//��Ϊ�������,����f[1][0]=0
	for (int i = 0;i < 1 << n;i++)//i��ʾ���е����
		for (int j = 0;j < n;j++)//j��ʾ�ߵ���һ����
			if (i >> j & 1)
				for (int k = 0;k < n;k++)//k��ʾ�ߵ�j�����֮ǰ,��kΪ�յ����̾���
					if ((i - (1 << j)) >> k & 1)
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);//������̾���
	cout << f[(1 << n) - 1][n - 1] << endl;//��ʾ���е㶼�߹���,���յ���n-1����̾���
}







//��״DP--û����˾�����
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





//���仯����--��ѩ
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