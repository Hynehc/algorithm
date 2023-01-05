	#define  _CRT_SECURE_NO_WARNINGS 1
//容斥原理--能被整除的数
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 20;
int n, m;
int p[N];
int main()
{
	cin >> n >> m;
	for (int i = 0;i < m;i++) cin >> p[i];//枚举从1 到 1111...(m个1)的每一个集合状态, (至少选中一个集合)
	int res = 0;
	for (int i = 1;i < 1 << m;i++)
	{
		int t = 1, cnt = 0;// t代表当前所有质数的乘积，cnt代表什么当前选法包含几个集合
		for(int j=0;j<m;j++)//枚举当前状态的每一位
			if (i >> j & 1)// i右移j位与上1，即如果当前位是1的话,代表当前集合存在
			{
				cnt++;//有一个1，集合数量+1
				if ((ll)t * p[j] > n)//乘积大于n, 则n/t = 0, 跳出这轮循环
				{
					t = -1;//如果t（已有的质数选法）乘上这个质数大于给定的数n，说明1∼n中的数不能被p整除
					break;
				}
				t *= p[j];// 将该质数乘到t中
			}
		if (t != -1)
		{
			if (cnt % 2) res += n / t;//选中奇数个集合, 则系数应该是1, n/t为当前这种状态的集合数量
			else res -= n / t;//反之则为 -1
		}
	}
	cout << res << endl;
	return 0;
}






//博弈论--Nim游戏
/*
先手必胜状态：先手操作完，可以走到某一个必败状态
先手必败状态：先手操作完，走不到任何一个必败状态
先手必败状态：a1 ^ a2 ^ a3 ^ ... ^an = 0
先手必胜状态：a1 ^ a2 ^ a3 ^ ... ^an ≠ 0
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int res = 0;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		res ^= x;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
}





//台阶 - Nim游戏
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int res = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		if (i % 2) res ^= x;
	}
	if (res) puts("Yes");
	else puts("No");
}







//集合-Nim游戏
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;
const int N = 110, M = 10010;
int m, n;
int s[N], f[M];//s存储的是可供选择的集合,f存储的是所有可能出现过的情况的sg值
int sg(int x)
{
	if (f[x] != -1) return f[x];//因为取石子数目的集合是已经确定了的,所以每个数的sg值也都是确定的,如果存储过了,直接返回即可
	unordered_set<int> S;
	for (int i = 0;i < m;i++)
	{
		int sum = s[i];
		if (x >= sum) S.insert(sg(x - sum));
	}
	for (int i = 0;;i++)
		if (!S.count(i))
			return f[x] = i;
}
int main()
{
	cin >> m;
	for (int i = 0;i < m;i++) cin >> s[i];
	cin >> n;
	memset(f, -1, sizeof f);//初始化f均为-1,方便在sg函数中查看x是否被记录过
	int res = 0;
	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		res ^= sg(x);//观察异或值的变化,基本原理与Nim游戏相同
	}
	if (res) puts("Yes");
	else puts("No");
	return 0;
}





//拆分-Nim游戏
#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_set>
using namespace std;
const int N = 110;
int n;
int f[N];
unordered_set<int> S;
int sg(int x)
{
	if (f[x] != -1) return f[x];
	for (int i = 0;i < x;i++)
		for (int j = 0;j <= i;j++)
			S.insert(sg(i) ^ sg(j));
	for (int i = 0;;i++)
		if (!S.count(i))
			return f[x] = i;
}
int main()
{
	memset(f, -1, sizeof f);
	cin >> n;
	int res = 0;
	while (n--)
	{
		int x;
		cin >> x;
		res ^= sg(x);
	}
	if (res) puts("Yes");
	else puts("No");
}