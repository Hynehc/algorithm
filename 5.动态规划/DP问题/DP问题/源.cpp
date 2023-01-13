#define  _CRT_SECURE_NO_WARNINGS 1

//01背包问题
//朴素写法

//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m;
//int v[N], w[N];//v是体积，w是价值
//int f[N][N];//f为dp
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 0;j <= m;j++)
//		{
//			f[i][j] = f[i - 1][j];//左半边的子集
//			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}

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

//朴素写法

//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m;
//int v[N], w[N];//v是体积，w是价值
//int f[N][N];//f为dp
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= m;j++)
//		{
//			f[i][j] = f[i-1][j];//左半边的子集
//			//f[i][j] = f[i - 1][j];
//			if(j>=v[i])
//			f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//			//f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i])
//			//j>j-v[i],所以j从大到小开始遍历，则先算f[j],那么f[j-v[i]]为i-1的f[j]
//		}
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}

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
//		for (int j = v[i];j <= m ;j++)
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



//总结
//01背包 f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
//完全背包 f[i][j] = max(f[i-1][j],f[i][j-v[i]]+w[i]);




//石子合并
//#include<iostream>
//using namespace std;
//const int N = 310;
//int n;
//int s[N];//前缀和
//int f[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> s[i], s[i] += s[i - 1];
//
//	for (int len = 2;len <= n;len++)//枚举区间长度
//	{
//		for (int i = 1;i + len - 1 <= n;i++)//枚举端点
//		{
//			int j = i + len - 1;//右端点
//			f[i][j] = 1e8;//初始化最大值
//			for (int k = i;k < j;k++)
//			{
//				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
//			}
//		}
//	}
//	cout << f[1][n] << endl;//区间为1到n
//	return 0;
//}




//最长公共子序列
//#include<iostream>
//using namespace std;
//const int N = 1000;
//int n, m;
//char a[N], b[N];
//int f[N][N];
//int main()
//{
//	cin >> n >> m >> a + 1 >> b + 1;
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//			if (a[i] == b[j])
//				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
//		}
//	cout << f[n][m] << endl;
//	return 0;
//}