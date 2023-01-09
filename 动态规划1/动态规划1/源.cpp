#define  _CRT_SECURE_NO_WARNINGS 1



//01背包问题
//朴素写法

#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v是体积，w是价值
int f[N][N];//f为dp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			f[i][j] = f[i - 1][j];//左半边的子集
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}

//优化写法(空间)
//从代码层面上化简代码--二维->一维

//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m;
//int v[N], w[N];//v是体积，w是价值
//int f[N];//f为dp
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = m;j >= v[i];j--)
//		{
//			f[j] = f[j];//左半边的子集
//			//f[i][j] = f[i - 1][j];
//
//			f[j] = max(f[j], f[j - v[i]] + w[i]);
//			//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i])
//			//j>j-v[i],所以j从大到小开始遍历，则先算f[j],那么f[j-v[i]]为i-1的f[j]
//		}
//	}
//	cout << f[m] << endl;
//	return 0;
//}





//完全背包问题
//方法：循环顺序从小到大

//朴素写法--三维

#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v是体积，w是价值
int f[N][N];//f为dp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			for (int k = 0;k * v[i] <= j;k++)
			{
				f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}


//优化--二维
#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v是体积，w是价值
int f[N][N];//f为dp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}




//优化写法(空间)
//从代码层面上化简代码--二维->一维

#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];//v是体积，w是价值
int f[N];//f为dp
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
	for (int i = 1;i <= n;i++)
	{
		for (int j = v[i];j <= m ;j++)
		{
			f[j] = f[j];//左半边的子集
			//f[i][j] = f[i - 1][j];

			f[j] = max(f[j], f[j - v[i]] + w[i]);
			//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i])
			//j>j-v[i],所以j从大到小开始遍历，则先算f[j],那么f[j-v[i]]为i-1的f[j]
		}
	}
	cout << f[m] << endl;
	return 0;
}



//总结
//01背包 f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
//完全背包 f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);





//多重背包问题 I
//朴素解法
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int n, m;
int v[N], w[N], s[N];
int f[N][N];
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i] >> s[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
			for (int k = 0;k <= s[i] && k * v[i] <= j;k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
	cout << f[n][m] << endl;
}



//多重背包问题 II -- 二进制优化
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 25000, M = 2010;
int n, m;
int v[N], w[N];
int f[N];
int main()
{
	cin >> n >> m;
	int cnt = 0; //分组的组别
	for (int i = 1;i <= n;i++)
	{
		int a, b, s;
		cin >> a >> b >> s;
		int k = 1;// 组别里面的个数
		while (k <= s)
		{
			cnt++; //组别先增加
			v[cnt] = a * k;//整体体积
			w[cnt] = b * k;// 整体价值
			s -= k;// s要减小
			k *= 2;// 组别里的个数增加
		}
		//剩余的一组
		if (s > 0)
		{
			cnt++;
			v[cnt] = a * s;
			w[cnt] = b * s;
		}
	}
	n = cnt;//枚举次数正式由个数变成组别数
	for (int i = 1;i <= n;i++)
		for (int j = m;j >= v[i];j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	cout << f[m] << endl;
}





//分组背包问题
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int n, m;
int v[N][N], w[N][N], s[N];
int f[N];
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		for (int j = 0;j < s[i];j++)
			cin >> v[i][j] >> w[i][j];
	}
	for (int i = 1;i <= n;i++)
		for (int j = m;j >= 0;j--)
			for (int k = 0;k < s[i];k++)
				if (v[i][k] <= j)
					f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
	cout << f[m] << endl;
}