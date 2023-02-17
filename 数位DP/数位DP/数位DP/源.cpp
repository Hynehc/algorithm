#define  _CRT_SECURE_NO_WARNINGS 1
//度的数量
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 35;
//int f[N][N];
//int K, B;
//void init()
//{
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j <= i;j++)
//			if (!j) f[i][j] = 1;
//			else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
//}
//int dp(int n)
//{
//	if (n == 0) return 0;
//	vector<int>nums;
//	while (n) nums.push_back(n % B), n /= B;
//	int res = 0, last = 0;
//	for (int i = nums.size() - 1;i >= 0;i--)
//	{
//		int x = nums[i];
//		if (x > 0)
//		{
//			res += f[i][K - last];
//			if (x > 1)
//			{
//				if (K - last - 1 >= 0) res += f[i][K - last - 1];
//				break;
//			}
//			else
//			{
//				last++;
//				if (last > K) break;
//			}
//		}
//		if (i == 0 && last == K) res++;
//	}
//	return res;
//}
//int main()
//{
//	init();int l, r;
//	cin >> l >> r >> K >> B;
//	cout << dp(r) - dp(l - 1) << endl;
//}



//数字游戏
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//using namespace std;
//const int N = 15;
//int f[N][N];
//void init()
//{
//	for (int i = 0;i <= 9;i++) f[1][i] = 1;
//	for (int i = 2;i < N;i++)
//		for (int j = 0;j <= 9;j++)
//			for (int k = j;k <= 9;k++)
//				f[i][j] += f[i - 1][k];
//}
//int dp(int n)
//{
//	if (!n) return 1;
//	vector<int>nums;
//	while (n) nums.push_back(n % 10), n /= 10;
//	int res = 0, last = 0;
//	for (int i = nums.size() - 1;i >= 0;i--)
//	{
//		int x = nums[i];
//		for (int j = last;j < x;j++)
//			res += f[i + 1][j];
//		if (x < last) break;
//		last = x;
//		if (!i) res++;
//	}
//	return res;
//}
//int main()
//{
//	init();
//	int l, r;
//	while (cin >> l >> r) cout << dp(r) - dp(l - 1) << endl;
//}





//Windy数
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//#include<cmath>
//using namespace std;
//const int N = 11;
//int f[N][10];
//void init()
//{
//	for (int i = 0;i <= 9;i++) f[1][i] = 1;
//	for (int i = 2;i < N;i++)
//		for (int j = 0;j <= 9;j++)
//			for (int k = 0;k <= 9;k++)
//				if (fabs(j - k) >= 2)
//					f[i][j] += f[i - 1][k];
//}
//int dp(int n)
//{
//	if (!n) return 0;
//	vector<int>nums;
//	while (n) nums.push_back(n % 10), n /= 10;
//	int res = 0, last = -2;
//	for (int i = nums.size() - 1;i >= 0;i--)
//	{
//		int x = nums[i];
//		for (int j = i == nums.size() - 1;j < x;j++)
//		{
//			if (fabs(j - last) >= 2)
//				res += f[i + 1][j];
//		}
//		if (fabs(x - last) >= 2) last = x;
//		else break;
//		if (!i) res++;
//	}
//	for (int i = 1;i < nums.size();i++)
//		for (int j = 1;j <= 9;j++)
//			res += f[i][j];
//	return res;
//}
//int main()
//{
//	init();
//	int l, r;
//	cin >> l >> r;
//	cout << dp(r) - dp(l - 1) << endl;
//	return 0;
//}





//数字游戏II
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 11, M = 110;
//int P;
//int f[N][10][M];
//int mod(int x, int y)
//{
//	return (x % y + y) % y;
//}
//void init()
//{
//	memset(f, 0, sizeof f);
//	for (int i = 0;i <= 9;i++) f[1][i][i % P]++;
//	for (int i = 2;i < N;i++)
//		for (int j = 0;j <= 9;j++)
//			for (int k = 0;k < P;k++)
//				for (int x = 0;x <= 9;x++)
//					f[i][j][k] += f[i - 1][x][mod(k - j, P)];
//}
//int dp(int n)
//{
//	if (!n) return 1;
//	vector<int>nums;
//	while (n) nums.push_back(n % 10), n /= 10;
//	int res = 0, last = 0;
//	for (int i = nums.size() - 1;i >= 0;i--)
//	{
//		int x = nums[i];
//		for (int j = 0;j < x;j++)
//			res += f[i + 1][j][mod(-last, P)];
//		last += x;
//		if (!i && last % P == 0) res++;
//	}
//	return res;
//}
//int main()
//{
//	int l, r;
//	while (cin >> l >> r >> P)
//	{
//		init();
//		cout << dp(r) - dp(l - 1) << endl;
//	}
//	return 0;
//}
//




//不要62
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 35;
//int f[N][N];
//void init()
//{
//	for (int i = 0;i <= 9;i++)
//		if (i != 4)
//			f[1][i] = 1;
//	for(int i=1;i<N;i++)
//		for (int j = 0;j <= 9;j++)
//		{
//			if (j == 4) continue;
//			for (int k = 0;k <= 9;k++)
//			{
//				if (k == 4 || j == 6 && k == 2) continue;
//				f[i][j] += f[i - 1][k];
//			}
//		}
//}
//int dp(int n)
//{
//	if (!n) return 1;
//	vector<int>nums;
//	while (n) nums.push_back(n % 10), n /= 10;
//	int res = 0, last = 0;
//	for (int i = nums.size() - 1;i >= 0;i--)
//	{
//		int x = nums[i];
//		for (int j = 0;j < x;j++)
//		{
//			if (j == 4 || last == 6 && j == 2) continue;
//			res += f[i + 1][j];
//		}
//		if (x == 4 || last == 6 && x == 2) break;
//		last = x;
//		if (!i) res++;
//	}
//	return res;
//}
//int main()
//{
//	init();
//	int l, r;
//	while (cin >> l >> r, l || r)
//	{
//		cout << dp(r) - dp(l - 1) << endl;
//	}
//	return 0;
//}





//恨7不成妻
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//using namespace std;
//typedef long long ll;
//const int N = 20, P = 1e9 + 7;
//struct F
//{
//	int s0, s1, s2;
//}f[N][10][7][7];
//int power7[N], power9[N];
//int mod(ll x, int y)
//{
//	return (x % y + y) % y;
//}
//void init()
//{
//	for (int i = 0;i <= 9;i++)
//	{
//		if (i == 7) continue;
//		auto& v = f[1][i][i % 7][i % 7];
//		v.s0++, v.s1 += i, v.s2 += i * i;
//	}
//	ll power = 10;
//	for(int i = 2;i <N ;i ++ , power *= 10)
//		for (int j = 0;j <= 9;j++)
//		{
//			if (j == 7) continue;
//			for(int a = 0;a < 7;a++)
//				for(int b = 0;b < 7;b++)
//					for (int k = 0;k <= 9;k++)
//					{
//						if (k == 7) continue;
//						auto& v1 = f[i][j][a][b], & v2 = f[i - 1][k][mod(a - j * power, 7)][mod(b - j, 7)];
//						v1.s0 = mod(v1.s0 + v2.s0, P);
//						v1.s1 = mod(v1.s1 + v2.s1 + j * (power % P) % P * v2.s0, P);
//						v1.s2 = mod(v1.s2 + j * j * (power % P) % P * (power % P) % P * v2.s0 + v2.s2 + 2 * j * power % P * v2.s1, P);
//
//					}
//		}
//	power7[0] = 1;
//	for (int i = 1;i < N;i++) power7[i] = power7[i - 1] * 10 % 7;
//	power9[0] = 1;
//	for (int i = 1;i < N;i++) power9[i] = power9[i - 1] * 10ll % P;
//}
//F get(int i, int j, int a, int b)
//{
//	int s0 = 0, s1 = 0, s2 = 0;
//	for(int x=0;x<7;x++)
//		for(int y=0;y<7;y++)
//			if (x != a && y != b)
//			{
//				auto v = f[i][j][x][y];
//				s0 = (s0 + v.s0) % P;
//				s1 = (s1 + v.s1) % P;
//				s2 = (s2 + v.s2) % P;
//			}
//	return { s0,s1,s2 };
//}
//int dp(ll n)
//{
//	if (!n) return n;
//	ll backup_n = n % P;
//	vector<int>nums;
//	while (n) nums.push_back(n % 10), n /= 10;
//	int res = 0;
//	ll last_a = 0, last_b = 0;
//	for (int i = nums.size() - 1;i >= 0;i--)
//	{
//		int x = nums[i];
//		for (int j = 0;j < x;j++)
//		{
//			if (j == 7) continue;
//			int a = mod(-last_a * power7[i + 1], 7);
//			int b = mod(-last_b, 7);
//			auto v = get(i + 1, j, a, b);
//			res = mod(
//				res +
//				(last_a % P) * (last_a % P) % P * power9[i + 1] % P * power9[i + 1] % P * v.s0 % P +
//				v.s2 +
//				2 * last_a % P * power9[i + 1] % P * v.s1, 
//				P);
//		}
//		if (x == 7) break;
//		last_a = last_a * 10 + x;
//		last_b += x;
//		if (!i && last_a % 7 && last_b % 7) res = (res + backup_n * backup_n) % P;
//	}
//	return res;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	init();
//	while (t--)
//	{
//		ll l, r;
//		cin >> l >> r;
//		cout << mod(dp(r) - dp(l - 1), P) << endl;
//	}
//	return 0;
//}
