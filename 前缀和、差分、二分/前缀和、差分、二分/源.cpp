#define  _CRT_SECURE_NO_WARNINGS 1

AcWing
首页
活动
题库
竞赛
应用
更多
吐槽
18
Hynehc 的头像
AcWing 99. 激光炸弹
作者： 作者的头像   Hynehc, 2023 - 02 - 10 16:28 : 53, 所有人可见, 阅读 1

0


//这里填你的代码^^#include<algorithm>
#include<iostream>
using namespace std;
const int N = 5010;
int s[N][N];
int main()
{
    int n, R;
    cin >> n >> R;
    R = min(R, 5001);
    for (int i = 0;i < n;i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        s[x][y] += w;
    }
    for (int i = 1;i <= 5001;i++)
        for (int j = 1;j <= 5001;j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    int res = 0;
    for (int i = R;i <= 5001;i++)
        for (int j = R;j <= 5001;j++)
            res = max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);
    cout << res << endl;
}
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
0 评论
我的头像
在这里写评论...（支持MarkDown和Latex语法）
1024x
© 2018 - 2023 AcWing 版权所有 | 京ICP备17053197号 - 1
用户协议 | 常见问题 | 联系我们

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 100010;
int n;
int a[N], b[N];
int main()
{
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) b[i] = a[i] - a[i - 1];
    ll p = 0, q = 0;
    for (int i = 2;i <= n;i++)
        if (b[i] > 0) p += b[i];
        else q -= b[i];
    cout << max(p, q) << endl;
    cout << abs(p - q) + 1 << endl;
}


//最佳牛围栏
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 100010;
double a[N], s[N];
int n, f;
bool check(double avg)
{
    for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i] - avg;
    double mins = 0;
    for (int k = f;k <= n;k++)
    {
        mins = min(mins, s[k - f]);
        if (s[k] >= mins) return true;
    }
    return false;
}
int main()
{
    cin >> n >> f;
    double l = 0, r = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << (int)(r * 1000) << endl;
}